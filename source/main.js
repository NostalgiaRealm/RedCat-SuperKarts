// The app: the JavaScript reconstruction's menu and its flow (../RedCat Superkarts/source/main.js at commit 5bfe0b62,
// 1.0.3), with its race replaced by the recompiled one. Kept as there, in its own compact style so the two can be
// compared line by line: the intro, the main menu and its greetings, QuickRace, Adventure, highscores, settings with
// Geavanceerd, Instellen and Meer instellingen, Help, Stoppen, the reward movies, the saves (rcsk.* in localStorage)
// and the keyboard, pad and touch navigation of the menus.
// Changed for the recomp ("recomp:" marks each place):
// - showTrack/DrivingView and resumeViewer became startSelectedRace with source/race-runner.js: the menu hides its
//   screens, shows the canvas and the JS port's loading screen (fed by the runner's load percent until the race
//   runs), awaits runner.start() and hands its result patch to finishRace unchanged.
// - Left out because the original race code does them itself: the JS-drawn quit requester and pause gate, the race
//   HUD, the race's key handling (focus loss in a race is the runner's: it presses the original's P). Left out for
//   now: the track viewer (?track). During a race the menu ignores keys and the pad.
// - The free-flight panel and its touch buttons are the JS port's; the flight itself is the race worker's
//   (source/host/free-flight.js). Its Instellingen holds the race under the settings (runner.menu, raceMenu) and
//   their OK or Terug gives it back (resumeRace), where the JS port suspended and resumed its viewer.
// - Settings that change are also passed to runner.applySettings().
import {readSettings,writeSettings,renderDimensions,autoPixelBudget,chooseMultisampleCount} from './menu/settings.js';
import {GAME_VERSION} from './version.js';
import {MoviePlayback} from './menu/movie-playback.js';
import {InputController,nativeIntroSkipKey} from './menu/input.js';
import {NativeMenu} from './menu/native-menu.js';
import {MenuAudio} from './menu/menu-audio.js';
import {NATIVE_MOVIE_GAIN,settingsAudioPercent} from './menu/audio-mixing.js';
import {nativeMenuNavigationSound,nativeMenuRaceModeSound,nativeAdventureBriefingSound,nativeCountryInfoSound,nativeMenuFirstTime,nativeMainMenuGreeting} from './menu/menu-sound-events.js';
import {NativeControlDraft,NATIVE_CONTROL_FIELDS,nativeBindingImage,nativeBindingLabel,nativeOptionsDraft,commitNativeOptions,nativeShowsStartInfo} from './menu/native-control-settings.js';
import {createNativeDisplaySettings} from './menu/native-display-settings.js';
import {nativeNavigationOrder} from './menu/native-tab-order.js';
import {applyNativeMenuRegion} from './menu/menu-regions.js';
import {assetURL} from './menu/asset-url.js';
import {readRaceSave,writeRaceSave,applyRaceResult,saveHighscore,unlockAllCountries,configWithRaceSave} from './menu/race-save.js';
import {nativeHighscoreIndex,formatNativeResultTime} from './menu/simulation/native-results.js';
import {NativeMenuRandom,nativeMenuRandomSeed,nativeAdventureOutcomeVoice,nativeDebriefRankVoice} from './menu/simulation/native-menu-random.js';
import {createLoadingScreen} from './menu/loading-screen.js';
import {HelpViewer} from './menu/help-viewer.js';
import {nativeHelpContext,nativeHelpNotice} from './menu/native-help-context.js';
import {nativeAdventureConfiguration,createNativeAdventureProfile,restartNativeAdventureProfile,
  nativeAdventureBriefing,beginNativeAdventureEvent,applyNativeAdventureResult,
  nativeAdventureSaveSlot,nativeAdventureReward,NATIVE_ADVENTURE_TYPES,NATIVE_ADVENTURE_COUNTRIES,
  nativeAdventureQualification} from './menu/simulation/native-adventure.js';
import {RaceRunner} from './race-runner.js';
import {exportSaves,parseSaves,importSaves} from './save-transfer.js';
import {unsupported,classicAddress} from './web/support.js';

const $=id=>document.getElementById(id),screen=$('screen');
const moviePlayback=new MoviePlayback($('movie'),$('movie-audio'),{onError:()=>message('De film kon niet worden afgespeeld.')});
const countries=['Nederland','Duitsland','Groot-Brittanië','Frankrijk','Spanje','Italië'];
const countryArt=['mn_0301a','mn_0302a','mn_0304a','mn_0303a','mn_0305a','mn_0306a'];
const characters=['RedCat','WhizzKitty','Brutus','Max'],modes=['Landenrace','Tijdrace','Sterrenrace','Duelrace'];
let settings=readSettings(),mode='intro',page='main',forms=null,nativeMenu=null,returnFromSettings='main',loadSerial=0,configs={},assetManifest={},menuAudio=null;
let selection={character:0,difficulty:1,country:0,race:0};
let raceSave=readRaceSave(),lastRace=null,playMode='quickrace',newProfileSelection=false;
let adventureConfig=null,promptReturn=null,rewardDone=null,highscoreCountry=0;
let optionsDraft=null,controlDialog=null,displayDraft=null,advancedSettingsActive=false;
let moreSettingsDraft=null;
// recomp: the recompiled race behind its runner (source/race-runner.js). racing is true from the start of a race's
// loading until runner.start() has settled; the menu then ignores keys, the pad and focus loss.
let runner=null,racing=false,lastRunnerConfig=null;
// recomp: raceMenu is true while the settings are open over a held race (the flight panel's Instellingen).
let raceMenu=false;
const visitedForms=new Set();
const firstTimePhases={main:'PHASE_MAIN',characters:'PHASE_SELECTCHAR',
  countries:'PHASE_SELECTCOUNTRY',adventure:'PHASE_ADVENT_MAIN'};
function consumeFirstTime(name){
  let seen=visitedForms.has(name);
  try{seen||=!!localStorage.getItem('rcsk.firsttime.'+name);localStorage.setItem('rcsk.firsttime.'+name,'1');}catch{}
  visitedForms.add(name);
  return nativeMenuFirstTime(configs,firstTimePhases[name],seen);
}
function formVoice(name,first,again=null){
  if(page===name)return;
  const sample=consumeFirstTime(name)?first:again;
  if(sample!==null)menuAudio?.generic(sample);
}
async function commonPress(method){
  if(!menuAudio||!method)return;
  if(method==='defOkButtonButtonStateChange')await menuAudio.generic(44,true);
  else if(method==='defBackButtonButtonStateChange')await menuAudio.generic(45,true);
  else if(['defHelpButtonButtonStateChange','defQuitButtonButtonStateChange','defOptionButtonButtonStateChange'].includes(method)){
    await menuAudio.generic(46,true);
    const sample=method==='defHelpButtonButtonStateChange'?20:method==='defQuitButtonButtonStateChange'?22:23;
    await menuAudio.character(selection.character,sample,method==='defOptionButtonButtonStateChange');
  }
}
try{const saved=JSON.parse(localStorage.getItem('rcsk.selection.v1'));for(const [key,max]of Object.entries({character:3,difficulty:2,country:5,race:2}))if(Number.isInteger(saved?.[key])&&saved[key]>=0&&saved[key]<=max)selection[key]=saved[key];}catch{}
const saveSelection=()=>{try{localStorage.setItem('rcsk.selection.v1',JSON.stringify(selection));}catch{}};
function message(text){$('message').textContent=text;$('message').hidden=false;clearTimeout(message.timer);message.timer=setTimeout(()=>$('message').hidden=true,6500);}
// recomp: the notice for a browser the race cannot run in (#unsupported in source/index.html; source/web/support.js), in
// Dutch as the menu; the link to the old version appears only when classic/ answers.
const UNSUPPORTED_WHY={isolation:'deze website geeft het spel niet het gedeelde geheugen dat het nodig heeft (de pagina is niet "cross-origin isolated")',
  wasm:'deze browser kent niet alles van WebAssembly wat het spel nodig heeft',
  canvas:'deze browser kan het beeld van het spel niet buiten de pagina tekenen (OffscreenCanvas ontbreekt)',
  webgl2:'deze browser geeft het spel geen WebGL 2 om mee te tekenen (het ontbreekt of staat uit)'};
function showUnsupported(reason){
  const box=$('unsupported');
  const text=document.createElement('p');
  text.textContent=`De races kunnen in deze browser niet starten: ${UNSUPPORTED_WHY[reason]||'onbekende reden'}. Probeer een recente versie van Chrome, Edge, Firefox of Safari.`;
  const actions=document.createElement('p');actions.className='unsupported-actions';
  const close=document.createElement('button');close.type='button';close.textContent='OK';close.onclick=()=>{box.hidden=true;};
  actions.append(close);box.replaceChildren(text,actions);box.hidden=false;
  classicAddress().then(url=>{if(!url)return;const a=document.createElement('a');a.href=url;a.id='unsupported-classic';a.textContent='Speel de vorige versie';actions.prepend(a);});
}
// recomp: settings are stored as the JS port stores them and also go to the race runner.
function storeSettings(){writeSettings(settings);try{runner?.applySettings({...settings});}catch(error){console.error(error);}}
const input=new InputController({onMenu:menuKey,onPause:back,deadzone:()=>settings.deadzone,enabled:()=>(!racing&&!runner?.active)||raceMenu});
// recomp: the JS port's flight panel (main.js:72-81 there), made before the runner so its touch controls bind Omhoog and
// Omlaag (Space and C, source/input/touch.js; there input.bindTouch). Instellingen holds the race under the menu.
const flightPanel=document.createElement('aside');flightPanel.id='flight-controls';flightPanel.hidden=true;
const flightHelp=document.createElement('p');flightHelp.textContent='Vrij vliegen — race gepauzeerd. Rijtoetsen: bewegen en draaien · Spatie: omhoog · C: omlaag.';
const flightActions=document.createElement('div');flightActions.append(button('Instellingen',()=>{
  if(!runner?.active)return;raceMenu=true;flightPanel.hidden=true;flightTouch.hidden=true;runner.menu(true);input.resyncPad();showSettings('race');
}),button('Stop vliegen',()=>{
  settings.freeFlight=false;storeSettings();
}));flightPanel.append(flightHelp,flightActions);$('app').append(flightPanel);
const flightTouch=document.createElement('div');flightTouch.id='flight-touch';flightTouch.hidden=true;
for(const label of ['Omhoog','Omlaag'])flightTouch.append(button(label,()=>{}));
$('touch-controls').insertBefore(flightTouch,$('touch-stop'));
function button(text,handler,attrs={}){
  const b=document.createElement('button');b.textContent=text;
  const definitions={Help:['mn_0222','defHelpButtonButtonStateChange'],Instellingen:['mn_0219','defOptionButtonButtonStateChange'],Stoppen:['mn_0220','defQuitButtonButtonStateChange'],Terug:['mn_0216','defBackButtonButtonStateChange'],OK:['mn_0217','defOkButtonButtonStateChange'],Start:['mn_0217','defOkButtonButtonStateChange']};
  const radio=text&&Object.hasOwn(attrs,'aria-pressed'),[art,press]=radio?['mn_0005',null]:definitions[text]||['mn_0004',null];
  for(const [state,suffix]of [['up',radio?'b':'a'],['hover',radio?'d':'b'],['down','c']])b.style.setProperty('--'+state,`url("${assetURL(`assets/menu/${art}${suffix}.png`)}")`);
  if(text){
    const width=radio?117:119,height=radio?40:43;b.style.width=width+'px';b.style.height=height+'px';
    const mask=radio?'mn_0005z.bmp':text==='OK'||text==='Start'?'mn_0217z.bmp':'mn_0004z.bmp';
    applyNativeMenuRegion(b,nativeMenu?.manifest[mask]?.region,width,height);
  }
  let pending=null,busy=false;b.onpointerdown=e=>{if(e.button===0)pending=commonPress(press);};b.onpointercancel=()=>pending=null;
  b.onclick=async()=>{if(busy)return;busy=true;try{await(pending||commonPress(press));if(b.isConnected)await handler();}finally{busy=false;pending=null;}};
  for(const[k,v]of Object.entries(attrs))b.setAttribute(k,v);return b;
}
function artButton(art,text,handler,selected=false){
  const b=button('',handler,{'aria-label':text,'aria-pressed':String(selected)});b.className='art-button';
  const img=document.createElement('img');img.src='assets/menu/'+art+'.png';img.alt='';
  if(art.endsWith('a')&&nativeMenu?.manifest[art.slice(0,-1)+'b.bmp']&&nativeMenu?.manifest[art.slice(0,-1)+'c.bmp']){
    const state=suffix=>img.src='assets/menu/'+art.slice(0,-1)+suffix+'.png';
    b.addEventListener('pointerenter',()=>state('b'));b.addEventListener('pointerleave',()=>state('a'));
    b.addEventListener('pointerdown',()=>state('c'));b.addEventListener('pointerup',()=>state('b'));
    b.addEventListener('pointercancel',()=>state('a'));b.addEventListener('focus',()=>state('b'));b.addEventListener('blur',()=>state('a'));
  }
  const span=document.createElement('span');span.textContent=text;b.append(img,span);return b;
}
// recomp: the menus hide the race's canvas, FPS counter and touch controls (the JS port: #world stays, its HUDs hide).
function hideRace(){$('game').hidden=true;$('fps-counter').hidden=true;$('touch-controls').hidden=true;}
function base(title,art,variant=''){
  bindingCapture=null;mode='menu';input.setMode('menu');screen.hidden=false;$('intro').hidden=true;hideRace();
  const wrap=document.createElement('div');wrap.className='menu '+variant;
  const header=document.createElement('header');header.className='menu-header';const logo=document.createElement('img');logo.className='brand';logo.src='assets/menu/mn_0003x.png';logo.alt='RedCat SuperKarts';header.append(logo,button('Help',showHelp));wrap.append(header);
  if(art){const img=document.createElement('img');img.className='menu-title';img.src='assets/menu/'+art+'.png';img.alt=title;wrap.append(img);}else{const h=document.createElement('h1');h.textContent=title;wrap.append(h);}
  const content=document.createElement('div');content.className='menu-content';wrap.append(content);
  const footer=document.createElement('footer');footer.className='footer';footer.append(button('Terug',()=>showMain()));wrap.append(footer);
  screen.replaceChildren(wrap);return {wrap,content,footer};
}
function showNative(name,options){
  const focused=screen.querySelector('[data-form]')?.dataset.form===name?document.activeElement?.dataset.element:null;
  bindingCapture=null;mode='menu';input.setMode('menu');screen.hidden=false;$('intro').hidden=true;hideRace();
  screen.replaceChildren(nativeMenu.render(name,options));
  if(focused){const element=screen.querySelector(`[data-element="${focused}"]`);if(element&&!element.disabled&&element.tabIndex>=0)element.focus();}
  else if(['TFRMSELECTCHAR','TFRMSELECTCOUNTRY','TFRMADVENTUREMAIN','TFRMADVENTBRIEF'].includes(name)){
    // Original FormShow4742d4/47004c/4762ec/479074 focuses OK.
    // Adventure4762ec skips that request when no profile enables the button.
    const accept=screen.querySelector('[data-native=btnOk]');
    if(accept&&!accept.disabled)accept.focus();
  }
}
const commonActions=()=>({btnMainHelp:showHelp,btnMainStop:showQuit,btnMainOptions:()=>{
  // Main's own474aa4 click follows the shared synchronous press sounds.
  if(page==='main')menuAudio?.generic(46);
  showSettings('main');
}});
function showMain(){
  playMode='quickrace';newProfileSelection=false;
  const entering=page!=='main'||screen.childElementCount===0;
  page='main';
  if(entering&&menuAudio)menuAudio.generic(nativeMainMenuGreeting(consumeFirstTime('main')));
  const choose=(sample,fn)=>async()=>{await menuAudio?.character(selection.character,sample,true);fn();};
  if(nativeMenu){
    showNative('TFRMMAIN',{actions:{...commonActions(),btnAdventure:choose(13,showAdventure),btnQuickRace:choose(14,showCharacters),btnHighscore:choose(15,showHighscores)}});
    screen.querySelector('[data-native=btnAdventure]')?.focus();return;
  }
  const {content,footer}=base('Hoofdmenu','mn_0105x');
  const cards=document.createElement('div');cards.className='cards main-cards';
  cards.append(artButton('mn_0103a','Avontuur',choose(13,showAdventure)),artButton('mn_0102a','QuickRace',choose(14,showCharacters)),artButton('mn_0101a','Highscore',choose(15,showHighscores)));content.append(cards);
  footer.replaceChildren(button('Instellingen',()=>showSettings('main')),button('Stoppen',showQuit));
}
function selectedProfile(){return raceSave.profiles[raceSave.selectedSlot]||null;}
function profileSelection(profile){
  const event=nativeAdventureBriefing(profile,adventureConfig);
  selection={character:profile.character,difficulty:profile.difficulty,country:event.country,race:event.raceType};
}
function showCharacters(){
  const adventure=playMode==='adventure';
  if(adventure){if(page!=='characters')menuAudio?.generic(53);}
  else formVoice('characters',31,53);
  page='characters';saveSelection();
  const shift=async n=>{await menuAudio?.generic(nativeMenuNavigationSound(n),true);selection.character=Math.max(0,Math.min(3,selection.character+n));showCharacters();menuAudio?.character(selection.character,0);};
  const accept=()=>{
    if(adventure){
      const profile=selectedProfile();profile.character=selection.character;profile.difficulty=selection.difficulty;
      writeRaceSave(raceSave);newProfileSelection=false;showBriefing();
    }else showCountries();
  };
  const portrait=(i,small=false)=>i<0||i>3?'':configs['ini/shellimg.dat'].charpics[i].split(',')[small?2:1].trim();
  showNative('TFRMSELECTCHAR',{actions:{...commonActions(),btnBack:showMain,btnOk:accept,
    btnPrevious:()=>shift(-1),btnNext:()=>shift(1),...Object.fromEntries(['rdoEasy','rdoMedium','rdoHard'].map((key,i)=>[key,()=>{selection.difficulty=i;menuAudio?.character(selection.character,i+1);showCharacters();}]))},
    images:{imgBackGround:configs['ini/shellang.ini'].dutch_images[adventure?26:27],
      imgPrevious:portrait(selection.character-1,true),imgCurrent:portrait(selection.character),imgNext:portrait(selection.character+1,true)},
    // 0x473c9f enables Back only in QuickRace (shell state 2).
    disabled:[...(adventure?['btnBack']:[]),...(selection.character===0?['btnPrevious']:[]),...(selection.character===3?['btnNext']:[])],
    text:{lblCharname:characters[selection.character],btnOk:configs['ini/shellang.ini'].dutch[adventure?14:47]},
    selected:[['rdoEasy','rdoMedium','rdoHard'][selection.difficulty]]});
}
function showCountries(){
  playMode='quickrace';if(selection.race>2)selection.race=0;formVoice('countries',35);
  page='countries';saveSelection();
  const shift=async n=>{await menuAudio?.generic(nativeMenuNavigationSound(n),true);selection.country=Math.max(0,Math.min(5,selection.country+n));showCountries();
    menuAudio?.character(selection.character,raceSave.locks[selection.country]?67+selection.country:4+selection.country);};
  const art=(i,small=false)=>{
    if(i<0||i>5)return '';
    const columns=configs['ini/shellimg.dat'].countrypics[NATIVE_ADVENTURE_COUNTRIES[i]].split(',');
    return columns[(raceSave.locks[i]?2:0)+(small?1:0)].trim();
  };
  const accept=()=>{
    if(raceSave.locks[selection.country]){
      const lang=configs['ini/shellang.ini'].dutch;
      originalNotice(`${lang[69]} ${countries[selection.country]} ${lang[70]}`,showCountries,24);
    }else showStartInfo();
  };
  showNative('TFRMSELECTCOUNTRY',{actions:{...commonActions(),btnBack:showCharacters,btnOk:accept,
    btnLeft:()=>shift(-1),btnRight:()=>shift(1),...Object.fromEntries(['rdoCountry','rdoTime','rdoItem'].map((key,i)=>[key,()=>{menuAudio?.character(selection.character,nativeMenuRaceModeSound(i));selection.race=i;showCountries();}]))},
    images:{imgLeftSelected:art(selection.country-1,true),imgSelectedCountry:art(selection.country),imgRightSelected:art(selection.country+1,true)},
    disabled:[...(selection.country===0?['btnLeft']:[]),...(selection.country===5?['btnRight']:[])],
    text:{lblCountryName:countries[selection.country]},selected:[['rdoCountry','rdoTime','rdoItem'][selection.race]]});
}
function adventureMatrixImages(profile){
  const images={},icons=configs['ini/shellimg.dat'].staticons;
  for(let country=0;country<6;country++)for(let type=0;type<4;type++)
    images[`img${country}${NATIVE_ADVENTURE_TYPES[type].toUpperCase()}`]=icons[NATIVE_ADVENTURE_TYPES[type]].split(',')[profile?.matrix[country][type]?0:1].trim();
  return images;
}
function showBriefing(){
  const profile=selectedProfile();if(!profile){showAdventure();return;}
  playMode='adventure';profileSelection(profile);page='briefing';
  const type=NATIVE_ADVENTURE_TYPES[selection.race],difficulty=['easy','normal','hard'][selection.difficulty],brief=configs['ini/brief.dat'][type+'_'+difficulty];
  const text=brief.welcome+' '+countries[selection.country]+Array.from({length:Number(brief.numlines)||0},(_,i)=>brief[i]||'\r\n').join('');
  const times={...configs['race.ini']['best times'],...raceSave.bestTimes};
  const language=configs['ini/shellang.ini'].dutch;
  showNative('TFRMADVENTBRIEF',{actions:{...commonActions(),btnBack:showMain,btnOk:()=>{
    menuAudio?.stop();
    beginNativeAdventureEvent(profile,adventureConfig);showStartInfo();
  },btnOverview:()=>{menuAudio?.generic(46);showCountryInfo();}},images:{...adventureMatrixImages(profile),
      imgCountryRacer:configs['ini/shellimg.dat'].debriefpics[NATIVE_ADVENTURE_COUNTRIES[selection.country]].split(',')[0].trim()},
    text:{lblCountry:countries[selection.country],lblType:modes[selection.race],lblBriefing:text,btnOk:language[65],
      lblTrackTime:language[67],lblLapTime:language[68],
      lblTrackTimeString:formatNativeResultTime(Number(times['race_record_e'+selection.country]||0)),
      lblLapTimeString:formatNativeResultTime(Number(times['lap_record_e'+selection.country]||0))}});
  screen.querySelector('[data-element=lblBriefing]').style.setProperty('white-space','pre-line','important');
  menuAudio?.generic(nativeAdventureBriefingSound(selection.country,selection.race));
}
// rcskmenu 0x475400 seeds the form slot from lastplayer (raceSave.selectedSlot).
// Left/Right 0x475e90/0x475ec0 change only the form slot; OK 0x4755d9, New
// 0x476175 and Delete 0x476093 write lastplayer.
let adventureSlot=-1;
function showAdventure(slot){
  playMode='adventure';newProfileSelection=false;formVoice('adventure',24,25);page='adventure';
  const occupied=raceSave.profiles.map(Boolean);
  if(Number.isInteger(slot))adventureSlot=slot;
  else adventureSlot=selectedProfile()?raceSave.selectedSlot:occupied.indexOf(true);
  slot=adventureSlot;
  const profile=raceSave.profiles[slot]||null;
  if(profile)selection={character:profile.character,difficulty:profile.difficulty,country:profile.country,race:profile.raceType};
  const previous=nativeAdventureSaveSlot(occupied,'previous',slot),next=nativeAdventureSaveSlot(occupied,'next',slot);
  const portrait=(index,small)=>index<0?'':configs['ini/shellimg.dat'].charpics[raceSave.profiles[index].character].split(',')[small?2:1].trim();
  const shift=index=>{if(index>=0)showAdventure(index);};
  const accept=async()=>{
    if(!profile){originalNotice(configs['ini/shellang.ini'].dutch[49],newAdventureProfile,24);return;}
    const changed=raceSave.selectedSlot!==slot||profile.completed;raceSave.selectedSlot=slot;
    if(profile.completed)restartNativeAdventureProfile(profile);
    if(changed)writeRaceSave(raceSave);
    profileSelection(profile);await menuAudio?.character(profile.character,17,true);showBriefing();
  };
  showNative('TFRMADVENTUREMAIN',{actions:{...commonActions(),btnBack:showMain,btnOk:accept,
    btnNewPlayer:newAdventureProfile,btnDeletePlayer:deleteAdventureProfile,btnLeft:()=>shift(previous),btnRight:()=>shift(next)},
    images:{...adventureMatrixImages(profile),imgLeftSelected:portrait(previous,true),imgSelected:portrait(slot,false),imgRightSelected:portrait(next,true)},
    text:{lblPlayerName:profile?.name||'',btnLeft:'Vorige speler',btnRight:'Volgende speler'},
    disabled:[...(previous<0?['btnLeft']:[]),...(next<0?['btnRight']:[]),...(!profile?['btnOk','btnDeletePlayer']:[])]});
}
function newAdventureProfile(){
  const restore=menuReturn();
  const slot=nativeAdventureSaveSlot(raceSave.profiles.map(Boolean),'new');
  if(slot<0){originalNotice(configs['ini/shellang.ini'].dutch[52],restore,21);return;}
  showNameEntry(configs['ini/shellang.ini'].dutch[53],'',name=>{
    if(!name){restore();return;}
    const profile=createNativeAdventureProfile(name,{slot,raceType:raceSave.profiles[adventureSlot]?.raceType??0});
    raceSave.profiles[slot]=profile;raceSave.selectedSlot=slot;writeRaceSave(raceSave);
    playMode='adventure';newProfileSelection=true;profileSelection(profile);showCharacters();
  },restore,'profile-name');
}
function removeSelectedProfile(slot=raceSave.selectedSlot){
  raceSave.profiles[slot]=null;
  const occupied=raceSave.profiles.map(Boolean),next=nativeAdventureSaveSlot(occupied,'next',slot);
  raceSave.selectedSlot=next>=0?next:nativeAdventureSaveSlot(occupied,'previous',slot);
  writeRaceSave(raceSave);
}
function deleteAdventureProfile(){
  const slot=adventureSlot,profile=raceSave.profiles[slot];
  if(!profile)return;
  const restore=menuReturn();
  menuAudio?.character(profile.character,26);
  originalPrompt(48,restore,()=>{restore();removeSelectedProfile(slot);showAdventure();});
}
function showHighscores(){
  if(page!=='highscores')highscoreCountry=0;
  page='highscores';const country=highscoreCountry,text={lblCountryName:NATIVE_ADVENTURE_COUNTRIES[country].toUpperCase()},images={};
  const lang=configs['ini/shellang.ini'].dutch,art=configs['ini/shellimg.dat'].highscorepics;
  const available=Object.values(configs['game.ini'].available_characters).filter(value=>value.includes(',')).map(value=>value.split(',')[0].toLowerCase());
  for(let i=1;i<=5;i++){
    const score=raceSave.boards[country][i-1],present=score.bestLapMs!==0;
    text['lblName'+i]=present?score.name:'';
    text['lblRound'+i]=present?formatNativeResultTime(score.bestLapMs):'';
    text['lblDiff'+i]=present?lang[8+score.difficulty]:'';
    images['imgHigh'+i]=present?art[available[score.character]]:'';
  }
  const countryImage=(index,small=false)=>index<0||index>5?'':configs['ini/shellimg.dat'].countrypics[NATIVE_ADVENTURE_COUNTRIES[index]]
    .split(',')[(raceSave.locks[index]?2:0)+(small?1:0)].trim();
  const shift=async n=>{await menuAudio?.generic(nativeMenuNavigationSound(n),true);highscoreCountry=Math.max(0,Math.min(5,highscoreCountry+n));showHighscores();};
  showNative('TFRMHIGHSCORE',{actions:{btnOk:showMain,btnQuit:showQuit,btnLeft:()=>shift(-1),btnRight:()=>shift(1)},
    disabled:[...(country===0?['btnLeft']:[]),...(country===5?['btnRight']:[])],
    text,images:{...images,imgLeftSelected:countryImage(country-1,true),imgSelectedCountry:countryImage(country),imgRightSelected:countryImage(country+1,true)}});
}
function originalPrompt(id,done=showMain,confirm=null){
  page='prompt';promptReturn=done;
  const lang=configs['ini/shellang.ini'].dutch;
  showNative('TFRMREQUESTER',{text:{lblQuit:lang[id],btnOk:lang[confirm?42:14],btnCancel:lang[43]},
    hidden:confirm?[]:['btnCancel'],actions:{btnOk:confirm||done,btnCancel:done}});
}
function originalNotice(text,done,icon=21){
  page='prompt';promptReturn=done;
  showNative('TFRMREQUESTER',{images:{imgIcon:configs['ini/shellang.ini'].dutch_images[icon]},
    text:{lblQuit:text,btnOk:configs['ini/shellang.ini'].dutch[14]},hidden:['btnCancel'],actions:{btnOk:done}});
}
function showNameEntry(text,initial,accept,cancel,entryPage='score-name'){
  page=entryPage;promptReturn=cancel;let name=initial,settled=false;
  const finish=fn=>{if(!settled){settled=true;fn();}};
  const submit=()=>finish(()=>accept(name));
  const lang=configs['ini/shellang.ini'].dutch;
  showNative('TFRMEDITBOX',{values:{edtName:name},text:{lblNameText:text,btnOk:lang[14],btnCancel:lang[64]},
    disabled:name?[]:['btnOk'],actions:{btnOk:submit,btnCancel:()=>finish(cancel),edtName:value=>{
      name=value;screen.querySelector('[data-native=btnOk]').disabled=!name;
    }}});
  const field=screen.querySelector('[data-element=edtName]');field.focus();field.select();
  // Original edtNameKeyUp470600 accepts Enter on release, including an
  // empty value. Keep Escape as the browser's existing cancel shortcut.
  field.onkeydown=event=>{if(event.code==='Enter'||event.code==='NumpadEnter')event.preventDefault();
    else if(event.code==='Escape'){event.preventDefault();finish(cancel);}};
  field.onkeyup=event=>{if(event.code==='Enter'||event.code==='NumpadEnter'){event.preventDefault();submit();}};
}
const notImplemented=done=>originalPrompt(46,done);
let countryInfoReturn=null;
function closeCountryInfo(){menuAudio?.stop();countryInfoReturn?.();countryInfoReturn=null;}
function showCountryInfo(){
  countryInfoReturn=menuReturn();
  page='country-info';const countryKeys=['nederland','duitsland','engeland','frankrijk','spanje','italie'],entries=configs['ini/shellimg.dat']?.[countryKeys[selection.country]+'_overview']||{};
  menuAudio?.generic(nativeCountryInfoSound(selection.country));
  if(nativeMenu){
    const images={},text={},actions={btnOk:closeCountryInfo,btnMainHelp:showHelp};let index=0;
    for(const value of Object.values(entries)){
      const[image,label]=value.split(','),photo=index;index++;
      images['imgPhoto'+index]=image.trim();text['lblPhoto'+index]=label?.trim()||'';
      text['imgPhoto'+index]=label?.trim()||'';
      actions['imgPhoto'+index]=()=>menuAudio?.generic(nativeCountryInfoSound(selection.country,photo));
    }
    showNative('TFRMLANDINFO',{images,text,actions});return;
  }
  const {content,footer}=base('Landinfo','mn_2200x');
  const cards=document.createElement('div');cards.className='cards';
  for(const value of Object.values(entries)){const [image,label]=value.split(',');const card=document.createElement('figure');card.style.margin='10px';const img=document.createElement('img');img.src='assets/menu/'+image.trim().replace('(IMAGEBASE)','').replace('.bmp','.png');img.width=121;img.height=137;img.alt=label?.trim()||'';const caption=document.createElement('figcaption');caption.textContent=label?.trim();card.append(img,caption);cards.append(card);}content.append(cards);footer.replaceChildren(button('Terug',closeCountryInfo));
}
// recomp: no track viewer or race HUD to capture; the race is never under a menu.
function captureMenu(){
  return {page,mode,inputMode:input.mode,bindingCapture,nodes:[...screen.childNodes],
    scrollTop:screen.scrollTop,focus:document.activeElement,
    hidden:Object.fromEntries(['screen','intro','touch-controls'].map(id=>[id,$(id).hidden]))};
}
function restoreMenu(saved){
  page=saved.page;mode=saved.mode;bindingCapture=saved.bindingCapture;
  input.setMode(saved.inputMode);screen.replaceChildren(...saved.nodes);
  for(const [id,hidden]of Object.entries(saved.hidden))$(id).hidden=hidden;
  screen.scrollTop=saved.scrollTop;saved.focus?.focus({preventScroll:true});
}
function menuReturn(){const saved=captureMenu();return()=>restoreMenu(saved);}
let helpData=null,helpReturn=showMain,helpSession=null,helpViewer=null;
function closeHelp(){
  if(!helpSession)return;
  const saved=helpSession;helpSession=null;helpViewer=null;
  restoreMenu(saved);
}
async function showHelp(topicId){
  if(page==='help'){
    if(typeof topicId==='string')helpViewer?.visit(topicId);
    return;
  }
  const previous=page;
  const notice=nativeHelpNotice(previous);
  if(notice!==null){originalPrompt(notice,menuReturn());return;}
  // Native WinHelp opens separately. Keep the actual caller nodes and drafts
  // alive so closing Help does not reconstruct a form or change race results.
  const session=captureMenu();
  helpSession=session;helpReturn=closeHelp;
  page='help';base('Help',null);
  try{
    helpData||=await fetch('assets/help/topics.json').then(r=>{if(!r.ok)throw Error('Original help: '+r.status);return r.json();});
    if(helpSession!==session||page!=='help')return;
    const context=typeof topicId==='string'?topicId:nativeHelpContext(previous,{playMode})??1;
    helpViewer=new HelpViewer(helpData,context,{screen,button,onClose:closeHelp});
  }catch(error){
    console.error(error);
    if(helpSession===session){closeHelp();message('Help kon niet worden geladen.');}
  }
}
function showQuit(){
  const fresh=playMode==='adventure'&&page==='characters'&&newProfileSelection;
  const returnPage=menuReturn();
  originalPrompt(fresh?50:36,returnPage,async()=>{
    if(fresh)removeSelectedProfile();
    // Shell shutdown47925a waits for the active character's farewell.
    mode='quitting';
    for(const control of screen.querySelectorAll('button,input,select'))control.disabled=true;
    await menuAudio?.character(selection.character,27,true);
    window.close();if(!window.closed)showMain();
  });
}
function finishOptions(commit=false){
  if(commit&&optionsDraft){settings=commitNativeOptions(settings,optionsDraft);storeSettings();menuAudio?.setVolume();}
  optionsDraft=null;advancedSettingsActive=false;controlDialog=null;displayDraft=null;moreSettingsDraft=null;
  // recomp: from the menus or the flight panel ('race'; the JS port's 'viewer' was also its track viewer).
  returnFromSettings==='race'?resumeRace():showMain();
}
// recomp: the JS port's resumeViewer after settings over a race: the canvas again, the race given back to its runner,
// whose touch controls, FPS counter and flight panel (frame) show again; settings.freeFlight off lands the kart.
function resumeRace(){
  raceMenu=false;returnFromSettings='main';
  if(!runner?.active){showMain();return;}
  page='driving';mode='race';screen.hidden=true;$('game').hidden=false;runner.menu(false);
}
function showSettings(from=returnFromSettings){
  page='settings';returnFromSettings=from;advancedSettingsActive=false;
  optionsDraft??=nativeOptionsDraft(settings);
  const draft=optionsDraft;
  if(nativeMenu){
    const control=(type,sample)=>()=>{draft.controlType=type;menuAudio?.generic(sample);showSettings(from);};
    const quality=(resolution,sample)=>()=>{draft.resolution=resolution;menuAudio?.generic(sample);showSettings(from);};
    const resolutionArt={'640x480':'mn_0617x','800x600':'mn_0618x','1024x768':'mn_0619x'}[draft.resolution];
    showNative('TFRMOPTIONS',{actions:{...commonActions(),btnBack:()=>finishOptions(false),btnOk:()=>finishOptions(true),btnAdvanced:()=>showAdvancedSettings(from),btnControlsAdvanced:()=>{menuAudio?.generic(12);showControlSettings();},
      sldMusicVolume:v=>{draft.music=v/100;menuAudio?.generic(17);},sldEffectVolume:v=>{draft.effects=v/100;menuAudio?.generic(18);},
      rdoLowQual:quality('640x480',15),rdoHighQual:quality('800x600',16),
      rdoKeyboard:control(0,9),rdoJoystick:control(2,10),rdoGamepad:control(1,11),chkStartInfo:()=>{draft.startInfo=!draft.startInfo;showSettings(from);}},
      text:{sldMusicVolume:'Muziekvolume',sldEffectVolume:'Effectvolume'},values:{sldMusicVolume:settingsAudioPercent(draft.music),sldEffectVolume:settingsAudioPercent(draft.effects)},
      selected:[['rdoKeyboard','rdoGamepad','rdoJoystick'][draft.controlType],'chk3dCard',...({'640x480':['rdoLowQual'],'800x600':['rdoHighQual']}[draft.resolution]||[]),...(draft.startInfo?['chkStartInfo']:[])],disabled:['chk3dCard',...(draft.controlType===0?[]:['btnControlsAdvanced'])],hidden:resolutionArt?[]:['imgResPic'],
      properties:{chkStartInfo:{Top:376},lblStartInfo:{Top:392}},
      images:{imgControlPic:`(IMAGEBASE)${['mn_0601a','mn_0603a','mn_0602a'][draft.controlType]}.bmp`,imgResPic:resolutionArt?`(IMAGEBASE)${resolutionArt}.bmp`:''}});
    const card=screen.querySelector('[data-native="chk3dCard"]');if(card)card.title='De browser beheert de grafische kaart.';
    const more=button('Meer instellingen',()=>showBrowserSettings(from));
    more.dataset.native='btnMoreSettings';more.className='more-settings-button';
    const stage=screen.querySelector('.native-stage'),checkRow=stage.querySelector('[data-portrait=check-row]');
    // Original button art, below both volume sliders in either layout.
    stage.insertBefore(more,checkRow||null);
    return;
  }
  showBrowserSettings(from);
}
function showStartInfo(){
  saveSelection();if(nativeShowsStartInfo(settings))showControlSettings(true);else startSelectedRace();
}
// recomp: the JS port's showTrack(country,true,{countdown:true}) with the recompiled race. The selection and the
// context are taken now, as showTrack did (main.js:708); the loading screen is the JS port's (424360/424f70 art) with
// the runner's load percent; the result goes to finishRace unchanged.
async function startSelectedRace(){
  const raceSelection={...selection},raceContext={kind:playMode,slot:raceSave.selectedSlot};
  page='loading';const serial=++loadSerial;base(countries[raceSelection.country],null);mode='loading';racing=true;
  let loading=null,running=false;
  // recomp: the picture's letter is the race type, not the character (the JS port passes selection.character):
  // 0x424360 formats e0%d_%c_hi.tga with *(int*)0x53a4b0+'A', the race type object 0x42ac60 fills from race.ini
  // RACETYPEINFO RaceType, and the four pictures carry the flag, clock, star and duel icons. The game's own copy of
  // this screen follows this one when the race boots, so both must show the same picture.
  try{loading=createLoadingScreen(assetManifest,raceSelection.country,raceSelection.race);screen.replaceChildren(loading.root);}catch(error){console.error(error);}
  $('message').hidden=true;$('game').hidden=false;document.activeElement?.blur?.();
  const save=readRaceSave(),merged=configWithRaceSave({'race.ini':{player:{},'best times':{}}},save);
  const position=merged['race.ini'].player.position;
  const config={country:raceSelection.country,character:raceSelection.character,difficulty:raceSelection.difficulty,raceType:raceSelection.race,
    save:{bestTimes:{...merged['race.ini']['best times']},playerPosition:position===undefined?undefined:Number(position)},settings:{...settings},
    onProgress:percent=>{if(serial===loadSerial&&page==='loading')try{loading?.update(Math.max(0,Math.min(100,Number(percent)||0)));}catch(error){console.error(error);}},
    onRunning:()=>{if(serial===loadSerial&&page==='loading'){running=true;page='driving';mode='race';screen.hidden=true;}},
    // recomp: the JS port's main.js:716-719 after its load: 437560 repairs enabled FX_VOLUME0 to75 and writes it back
    // to Race.ini; the runner hands over the level the race plays with once it has booted. Taken here and not from the
    // race's result: a level changed during the race (Instellingen) is the player's, applied live (race-runner.js
    // applySettings, source/host/live-volume.js), and the result must not put the start's level back.
    onEffects:percent=>{if(serial===loadSerial&&settingsAudioPercent(settings.effects)!==percent){settings.effects=percent/100;storeSettings();}}};
  lastRunnerConfig={...config,onProgress:undefined,onRunning:undefined,onEffects:undefined};
  let outcome;
  try{
    if(!runner)throw Error(notRunnable?UNSUPPORTED_WHY[notRunnable.reason]:'de race kon niet worden gestart');
    outcome=await runner.start(config);
  }catch(error){outcome={patch:null,effectsPercent:null,exitCode:null,error};}
  racing=false;raceMenu=false;hideRace();input.resyncPad();
  if(serial!==loadSerial)return;
  // (outcome.effectsPercent is not adopted: onEffects took the race's level at its start, as the JS port does)
  if(outcome?.error||!outcome?.patch?.PLAYER){
    const error=outcome?.error;console.error(error);
    message((running?'De race is gestopt door een fout: ':'De race kon niet worden geladen: ')+(error?.message||error||'geen resultaat'));
    playMode=raceContext.kind;raceContext.kind==='adventure'?showBriefing():showCountries();return;
  }
  finishRace(outcome.patch,raceSelection,raceContext);
}
function startQuickRace(){playMode='quickrace';return startSelectedRace();}
function finishRace(patch,raceSelection,raceContext={kind:playMode,slot:raceSave.selectedSlot}){
  raceSave=readRaceSave();raceSave.locks??=[...adventureConfig.locks];applyRaceResult(raceSave,patch);
  if(patch.PLAYER.finished&&raceContext.kind==='adventure'&&raceSave.profiles[raceContext.slot]){
    const profile=raceSave.profiles[raceContext.slot];profile.country=raceSelection.country;profile.raceType=raceSelection.race;
    raceSave.selectedSlot=raceContext.slot;
  }
  writeRaceSave(raceSave);
  if(!patch.PLAYER.finished){showMain();return;}
  lastRace={patch,selection:raceSelection,...raceContext,savedProfile:raceContext.kind==='adventure'?structuredClone(raceSave.profiles[raceContext.slot]):null,random:new NativeMenuRandom(nativeMenuRandomSeed(new Date()))};playMode=raceContext.kind;showDebrief();
}
function showDebrief(){
  if(!lastRace){showMain();return;}
  page='debrief';
  const {patch,selection:chosen}=lastRace,lang=configs['ini/shellang.ini'].dutch;
  if(!lastRace.spoken){
    lastRace.spoken=true;
    menuAudio?.character(chosen.character,nativeDebriefRankVoice(Number(patch.PLAYER.position),lastRace.random));
  }
  const pictures=configs['ini/shellimg.dat'],languageImages=configs['ini/shellang.ini'].dutch_images;
  const available=configs['game.ini'].available_characters,images={
    imgBackGround:languageImages[lastRace.kind==='adventure'?26:27],imgReward:pictures.rewardpics[patch.PLAYER.position],
  };
  const entries=Object.entries(patch.RACERS),playerIndex=entries.length-1;
  const activeRanks=new Set();
  for(const [index,row]of entries){
    const [character,rank]=row.split(',').map(Number);
    const name=available[character].split(',')[0].toLowerCase();
    images[`imgPosition${rank+1}`]=pictures.debriefpics[name].split(',')[Number(index)===playerIndex?0:1].trim();
    images[`imgFinPos${rank+1}`]=languageImages[28+rank];activeRanks.add(rank);
  }
  showNative('TFRMDEBRIEF',{
    images,text:{lblPlayerName:lastRace.kind==='adventure'?raceSave.profiles[lastRace.slot].name:characters[chosen.character],
      lblTotal:`${lang[34]} ${formatNativeResultTime(patch.PLAYER.tracktime)}`,
      lblBestLap:`${lang[35]} ${formatNativeResultTime(patch.PLAYER.FASTEST_LAP)}`,
      btnBack:lang[58],btnOk:lang[lastRace.kind==='adventure'?14:63]},
    properties:{lblTotal:{Width:350},lblBestLap:{Width:350}},
    hidden:Array.from({length:5},(_,rank)=>rank).filter(rank=>!activeRanks.has(rank))
      .flatMap(rank=>[`imgPosition${rank+1}`,`imgFinPos${rank+1}`]),
    actions:{...commonActions(),btnBack:debriefBack,
      btnOk:()=>lastRace.kind==='adventure'?processAdventureResult(false):processHighscore(()=>{selection={...chosen};startQuickRace();})},
  });
  controlFocus(lastRace.kind==='adventure'?'btnOk':'btnBack');
}
// rcskmenu 0x471b8c: the debrief's Back also processes the result (0x471bc0).
// The form has no key handlers, so keyboard/controller Back uses this action.
function debriefBack(){lastRace.kind==='adventure'?processAdventureResult(true):processHighscore(showMain);}
function controlFocus(name){screen.querySelector(`[data-native=${name}]`)?.focus();}
function processHighscore(done){
  const {patch,selection:chosen}=lastRace;
  const index=nativeHighscoreIndex(raceSave.boards[chosen.country],patch.PLAYER.FASTEST_LAP);
  if(index<0){done();return;}
  const profile=lastRace.kind==='adventure'?raceSave.profiles[lastRace.slot]:null;
  const lang=configs['ini/shellang.ini'].dutch;
  menuAudio?.character(chosen.character,36);
  showNameEntry(`${lang[55]} ${index+1}${lang[78]}`,profile?.name??raceSave.quickRaceName,name=>{
    if(name){
      saveHighscore(raceSave,chosen.country,{name,character:chosen.character,
        totalRaceMs:patch.PLAYER.tracktime,bestLapMs:patch.PLAYER.FASTEST_LAP,difficulty:chosen.difficulty});
      if(profile)profile.name=name;
    }
    if(profile){
      const persisted={...raceSave,profiles:[...raceSave.profiles]};persisted.profiles[lastRace.slot]=lastRace.savedProfile;writeRaceSave(persisted);
    }else writeRaceSave(raceSave);
    done();
  },done);
}
async function processAdventureResult(backToMain){
  if(lastRace.processing)return;lastRace.processing=true;
  const {patch,selection:chosen}=lastRace,profile=raceSave.profiles[lastRace.slot];
  const lang=configs['ini/shellang.ini'].dutch;
  const result={rank:Number(patch.PLAYER.position),finished:Boolean(patch.PLAYER.finished),stars:Number(patch.PLAYER.EUROSTARS)};
  const qualification=nativeAdventureQualification(profile,result);
  if(qualification.qualified&&profile.raceType===3)await playAdventureReward('star',profile.country);
  if(qualification.qualified||qualification.reason==='rank')
    await menuAudio?.character(chosen.character,nativeAdventureOutcomeVoice(qualification.qualified,profile.raceType,lastRace.random),qualification.qualified);
  const outcome=applyNativeAdventureResult(profile,result,{...adventureConfig,locks:raceSave.locks});
  const notice=(text,icon)=>new Promise(resolve=>originalNotice(text,resolve,icon));
  if(outcome.qualified){
    if(!outcome.campaignCompleted)await notice(lang[61],21);
  }else{
    const reason=outcome.reason;
    const text=reason==='rank'?`${lang[59]} ${outcome.maximumRank+1}${lang[60]}`:
      reason==='stars'?`${lang[71]} ${result.stars} ${lang[72]} 12 ${lang[73]}`:
      reason==='duel'?lang[74]:lang[75];
    // Original >12-star mismatch returns false without its <12-star notice.
    if(reason!=='stars'||result.stars<12)await notice(text,24);
    if(reason!=='rank')menuAudio?.character(chosen.character,nativeAdventureOutcomeVoice(false,profile.raceType,lastRace.random));
  }
  if(outcome.unlockedCountry!==null){
    menuAudio?.character(chosen.character,[63,63,63,65,66,64][outcome.unlockedCountry]);
    await notice(`${lang[56]} ${countries[outcome.unlockedCountry]} ${lang[57]}`,21);
  }
  await new Promise(resolve=>processHighscore(resolve));
  if(outcome.campaignCompleted)await playAdventureReward('win',profile.character);
  writeRaceSave(raceSave);
  if(backToMain||outcome.campaignCompleted)showMain();else showBriefing();
}
function playAdventureReward(kind,index){
  const reward=nativeAdventureReward(configs,kind,index);
  menuAudio?.stop();page='reward';mode='reward';input.setMode('menu');
  screen.hidden=true;hideRace();
  moviePlayback.stop();$('intro').hidden=false;$('skip-movie').hidden=true;
  return new Promise(resolve=>{
    rewardDone=()=>{
      moviePlayback.stop();
      $('intro').hidden=true;$('skip-movie').hidden=true;rewardDone=null;resolve();
    };
    if(reward.image){
      showNative(reward.form,{images:{imgBackGround:reward.source}});mode='reward';
      setTimeout(()=>rewardDone?.(),reward.durationMs);
    }else{
      moviePlayback.start('assets/media/'+reward.source.replace(/\.[^.]+$/,'.mp4').toLowerCase(),NATIVE_MOVIE_GAIN);
    }
  });
}
let bindingCapture=null;
function finishControls(commit){
  if(!controlDialog)return;
  const startInfo=controlDialog.startInfo;
  if(commit){
    if(startInfo)settings.startInfo=controlDialog.showInfo;
    else settings.bindings=controlDialog.draft.commit();
    storeSettings();
  }else controlDialog.draft.cancel();
  controlDialog=null;bindingCapture=null;
  if(startInfo){if(commit)startSelectedRace();else playMode==='adventure'?showBriefing():showCountries();}
  else showSettings();
}
function showControlSettings(startInfo=false){
  controlDialog??={startInfo,showInfo:settings.startInfo,draft:new NativeControlDraft(settings.bindings)};
  const dialog=controlDialog,draft=dialog.draft;
  page=startInfo?'start-info':'controls';
  const language=configs['ini/shellang.ini'].dutch;
  const text={btnOk:language[14],btnCancel:language[15],lblShowStartInfo:language[62]},images={};
  const actions={btnOk:()=>finishControls(true),btnCancel:()=>finishControls(false),
    btnDefault:()=>{draft.defaults();showControlSettings();},btnHelp:showHelp,
    chkShowInfo:()=>{dialog.showInfo=!dialog.showInfo;showControlSettings(true);}};
  for(const[index,field]of NATIVE_CONTROL_FIELDS.entries()){
    text['lblKEY_'+field]=nativeBindingLabel(draft.keys[index]);
    text['imgKEY_'+field]=language[26+index]||field;
    images['imgKEY_'+field]=nativeBindingImage(index,draft.keys[index],draft.capture===index&&draft.captureImage);
    if(!startInfo)for(const prefix of ['img','lbl'])actions[prefix+'KEY_'+field]=()=>{
      if(draft.begin(index)){menuAudio?.generic(50);showControlSettings();}
    };
  }
  showNative('TFRMCONTROLSETTINGS',{text,images,actions,hidden:startInfo?['lblHelp','btnDefault','btnCancel']:['chkShowInfo','lblShowStartInfo'],
    disabled:draft.capture===null?[]:['btnOk'],properties:startInfo?{btnOk:{Left:384,Top:410}}:{},
    selected:dialog.showInfo?['chkShowInfo']:[]});
  if(!startInfo&&draft.capture!==null)bindingCapture={action:draft.capture};
  else screen.querySelector('[data-native=btnOk]')?.focus();
}
window.addEventListener('keydown',event=>{
  if(bindingCapture){event.preventDefault();event.stopImmediatePropagation();}
},true);
window.addEventListener('keyup',event=>{
  if(page!=='controls'||!controlDialog)return;
  if(bindingCapture){event.preventDefault();event.stopImmediatePropagation();}
  const result=controlDialog.draft.release(event.keyCode);
  for(const sample of result.samples)menuAudio?.generic(sample);
  if(result.decision==='duplicate'){
    originalNotice(configs['ini/shellang.ini'].dutch[54],showControlSettings,21);return;
  }
  if(result.decision==='inactive'||result.decision==='reject')return;
  bindingCapture=null;showControlSettings();
},true);
function showAdvancedSettings(from='main'){
  returnFromSettings=from;displayDraft??={...settings.display};
  showNative('TFRMOPTIONS',{});
  page='settings';advancedSettingsActive='display';
  const finish=commit=>{
    if(commit){settings.display={...displayDraft};storeSettings();}
    displayDraft=null;showSettings(from);
  };
  screen.replaceChildren(createNativeDisplaySettings(forms.TFRMDISPLAYSETTINGS,displayDraft,{
    onOk:value=>{displayDraft=value;finish(true);},onCancel:()=>finish(false),
  }));
}
function showBrowserSettings(from='main'){
  returnFromSettings=from;page='settings';advancedSettingsActive='browser';
  moreSettingsDraft??={...settings,...optionsDraft};
  const draft=moreSettingsDraft;
  const {content,footer}=base('Meer instellingen',null,'more-settings');
  const form=document.createElement('div');form.className='settings-form';
  form.innerHTML=`<h2>Beeld</h2><label>Resolutie<select id="resolution"><option value="auto">Automatisch</option><option value="native">Volle schermresolutie</option>${['640x480','800x600','1024x768','1280x720','1920x1080','2560x1440','3840x2160'].map(x=>`<option value="${x}">${x.replace('x',' × ')}</option>`).join('')}</select></label>
  <label>Renderschaal <output id="scale-value"></output><input id="scale" aria-label="Renderschaal" type="range" min="25" max="200" step="5"><small id="effective-resolution"></small></label>
  <p class="settings-detail">Automatisch beperkt het beeld op telefoons en tablets tot ongeveer 1 megapixel: vloeiender en zuiniger, iets minder scherp. Kies Volle schermresolutie voor elke schermpixel.</p>
  <label class="settings-toggle"><input id="show-fps" type="checkbox">FPS weergeven</label>
  <p class="settings-detail">Toon het aantal beelden per seconde tijdens het spelen.</p>
  <label class="settings-toggle"><input id="msaa-enabled" type="checkbox">Randen gladmaken (MSAA)</label>
  <label>MSAA-kwaliteit<select id="msaa-samples"><option value="2">2×</option><option value="4">4×</option><option value="8">8×</option></select></label>
  <p id="msaa-status" class="settings-detail" role="status"></p>
  <label class="settings-toggle"><input id="surface-shadows" type="checkbox">Schaduwen op het wegdek</label>
  <p class="settings-detail">Kartschaduwen liggen op het wegdek onder de kart. Uit: de oorspronkelijke schaduw, die op sommige plekken onder de weg verdwijnt.</p>
  <label class="settings-toggle"><input id="smooth-engine-lights" type="checkbox">Motorlicht volgt de kart</label>
  <p class="settings-detail">Het licht achter elke kart beweegt tussen spelstappen vloeiend mee en blijft achter de motor. Uit: het licht blijft op de laatste spelstap staan en verdwijnt bij hoge snelheid soms in de motor.</p>
  <h2>Cheats</h2>
  <div class="settings-toggle-action"><span>Vrij vliegen (no-clip)</span><div id="flight-toggle-host"></div></div>
  <p class="settings-detail">Vlieg na de start vrij door het circuit. De race pauzeert tijdens het vliegen. Uitschakelen brengt je terug naar de baan.</p>
  <div id="unlock-controls"></div><p id="unlock-status" class="settings-detail" role="status"></p>
  <h2>Bediening</h2>
  <label>Controller deadzone<input id="deadzone" type="range" min="0" max="50"></label>
  <label>Aanraakbediening<select id="touch"><option value="auto">Automatisch</option><option value="on">Aan</option><option value="off">Uit</option></select></label>
  <div id="save-section"><h2>Opslag</h2><div id="save-controls"></div><p id="save-status" class="settings-detail" role="status"></p></div>
  <p id="game-version" class="settings-detail settings-version">Versie ${GAME_VERSION}</p>`;
  content.append(form);
  $('resolution').value=draft.resolution;$('scale').value=draft.renderScale;$('deadzone').value=draft.deadzone*100;$('touch').value=draft.touch;
  $('msaa-enabled').checked=draft.msaaEnabled;$('msaa-samples').value=draft.msaaSamples;$('show-fps').checked=draft.showFps;$('surface-shadows').checked=draft.surfaceShadows;$('smooth-engine-lights').checked=draft.smoothEngineLights;
  const flightToggle=button(draft.freeFlight?'Aan':'Uit',()=>{
    flightToggle.setAttribute('aria-pressed',String(flightToggle.getAttribute('aria-pressed')!=='true'));update();
  },{'aria-label':'Vrij vliegen (no-clip)','aria-pressed':String(Boolean(draft.freeFlight))});
  flightToggle.id='free-flight';$('flight-toggle-host').append(flightToggle);
  const unlock=button('Alles ontgrendelen',()=>{
    const saved=readRaceSave();
    if(unlockAllCountries(saved)){
      raceSave=saved;$('unlock-status').textContent='Alle landen en circuits zijn ontgrendeld en opgeslagen. Je voortgang en scores zijn behouden.';
    }else $('unlock-status').textContent='Ontgrendelen kon niet worden opgeslagen. Probeer het opnieuw.';
  });
  unlock.id='unlock-all';unlock.classList.add('settings-wide-button');$('unlock-controls').append(unlock);
  // recomp: saves between sites (source/save-transfer.js). On one site the recomp shares the JS port's saves; on
  // another host or port, or from the JS port's desktop app, they move as a file. Not during a race (the import
  // reloads the page).
  if(runner?.active)$('save-section').hidden=true;
  else{
    const picker=document.createElement('input');picker.type='file';picker.accept='.json,application/json';picker.hidden=true;picker.id='save-file';
    picker.onchange=async()=>{
      const file=picker.files?.[0];picker.value='';if(!file)return;
      try{
        const {keys,summary}=parseSaves(await file.text());
        const what=[summary.profiles.length?`avonturen: ${summary.profiles.join(', ')}`:'geen avonturen',`${summary.scores} highscores`,summary.settings?'instellingen':'geen instellingen'].join(', ');
        if(!confirm(`Opslag importeren (${what})? De huidige opslag in deze browser wordt vervangen.`))return;
        importSaves(keys);location.reload();
      }catch(error){$('save-status').textContent=error.message||'Importeren is mislukt.';}
    };
    const exportButton=button('Opslag exporteren',()=>{try{exportSaves();$('save-status').textContent='De opslag is als bestand opgeslagen (redcat-superkarts-opslag.json).';}catch{$('save-status').textContent='Exporteren is mislukt.';}});
    const importButton=button('Opslag importeren',()=>picker.click());
    exportButton.id='save-export';importButton.id='save-import';
    for(const b of [exportButton,importButton])b.classList.add('settings-wide-button');
    $('save-controls').append(exportButton,importButton,picker);
    $('save-status').textContent='Neem avonturen, highscores en instellingen mee naar een andere website of browser. Importeren vervangt de opslag hier.';
  }
  $('unlock-status').textContent=raceSave.locks?.every(locked=>!locked)?'Alle landen en circuits zijn al ontgrendeld.':'Ontgrendelt direct alle landen en circuits. Voortgang en scores blijven behouden.';
  const update=()=>{
    Object.assign(draft,{resolution:$('resolution').value,renderScale:Number($('scale').value),deadzone:Number($('deadzone').value)/100,touch:$('touch').value,
      msaaEnabled:$('msaa-enabled').checked,msaaSamples:Number($('msaa-samples').value),showFps:$('show-fps').checked,surfaceShadows:$('surface-shadows').checked,smoothEngineLights:$('smooth-engine-lights').checked,
      freeFlight:flightToggle.getAttribute('aria-pressed')==='true'});
    flightToggle.textContent=draft.freeFlight?'Aan':'Uit';
    const size=renderDimensions({width:innerWidth,height:innerHeight,dpr:devicePixelRatio,...draft,autoPixels:autoPixelBudget()});
    $('scale-value').textContent=draft.renderScale+'%';$('effective-resolution').textContent=`Basis ${size.baseWidth} × ${size.baseHeight} → 3D ${size.width} × ${size.height} pixels`;
    $('msaa-samples').disabled=!draft.msaaEnabled;
    // recomp: the runner may report the sample counts its renderer supports (msaaStatus.supportedSamples, as the
    // JS port's viewer did); without it the general note shows.
    const supported=runner?.msaaStatus?.supportedSamples;
    const actual=Array.isArray(supported)?chooseMultisampleCount(draft.msaaSamples,supported):null;
    $('msaa-status').textContent=!draft.msaaEnabled?'MSAA staat uit.':
      actual!==null&&actual!==draft.msaaSamples?
        (actual?`${draft.msaaSamples}× is niet beschikbaar op je grafische kaart; ${actual}× wordt gebruikt.`:'Je grafische kaart ondersteunt geen MSAA. Randen gladmaken blijft uit.'):
        'De beschikbare kwaliteit hangt af van je grafische kaart.';
  };
  for(const el of form.querySelectorAll('input,select'))el.oninput=update;update();
  const accept=button('OK',()=>finishMoreSettings(true));accept.classList.add('more-settings-accept');
  // Load the original art eagerly: a CSS-only background below the scroll
  // viewport can otherwise appear after the caption on its first reveal.
  const acceptArt=document.createElement('img');acceptArt.alt='';acceptArt.src='assets/menu/mn_0217a.png';accept.prepend(acceptArt);
  for(const [event,state]of [['pointerenter','b'],['focus','b'],['pointerleave','a'],['blur','a'],['pointerdown','c'],['pointerup','b'],['pointercancel','a']])
    accept.addEventListener(event,()=>acceptArt.src=`assets/menu/mn_0217${state}.png`);
  footer.replaceChildren(button('Terug',()=>finishMoreSettings(false)),button('Volledig scherm',async()=>{try{if(document.fullscreenElement)await document.exitFullscreen();else await document.documentElement.requestFullscreen();}catch{message('Volledig scherm is niet beschikbaar in deze browser.');}}),accept);
}
function finishMoreSettings(commit){
  if(commit&&moreSettingsDraft){
    optionsDraft??=nativeOptionsDraft(settings);
    for(const key of ['resolution','renderScale','deadzone','touch','msaaEnabled','msaaSamples','showFps','surfaceShadows','smoothEngineLights','freeFlight'])optionsDraft[key]=moreSettingsDraft[key];
  }
  moreSettingsDraft=null;showSettings(returnFromSettings);
}
// recomp: the race's own Esc, P, pause and requester are the original code's (in the runner), so back() only
// serves the menus, the intro and the reward movies; focus loss in the menus changes nothing (as in the JS port).
function back(reason){
  if((racing||runner?.active)&&!raceMenu)return;
  if(mode==='reward'||mode==='quitting')return;
  if(mode==='intro'){if(reason!=='focus'&&!$('movie').paused)finishIntro();return;}
  if(reason==='focus')return;
  if(page==='settings'){
    if(advancedSettingsActive==='browser')finishMoreSettings(false);
    else if(advancedSettingsActive==='display'){displayDraft=null;showSettings();}
    else finishOptions(false);
    return;
  }
  if(page==='controls'||page==='start-info'){finishControls(false);return;}
  if(page==='help'){if(!helpViewer?.closePanel())helpReturn();return;}
  if(['prompt','score-name','profile-name'].includes(page)){promptReturn?.();return;}
  if(page==='debrief'){if(lastRace)debriefBack();return;}
  // rcskmenu 0x473c9f disables Back in Adventure character selection.
  if(page==='characters'&&playMode==='adventure')return;
  if(page==='countries')showCharacters();else if(page==='country-info')closeCountryInfo();else if(page==='start-info')playMode==='adventure'?showBriefing():showCountries();else showMain();
}
function menuKey(key,source){
  if((racing||runner?.active)&&!raceMenu)return;
  if((mode==='intro'||mode==='reward')&&document.activeElement===$('movie-audio')&&(key==='Enter'||key==='Space')){
    moviePlayback.activate();return;
  }
  if(mode==='reward'){if($('movie').paused&&(key==='Enter'||key==='Space'))moviePlayback.activate();return;}
  // Keyboard skips use the native key-press rule in the keydown listener
  // below; skipping with any controller button is a browser adaptation.
  if(mode==='intro'){if(!$('movie').paused){if(source!=='keyboard')finishIntro();}else if(key==='Enter'||key==='Space')moviePlayback.activate();return;}
  const items=nativeNavigationOrder([...screen.querySelectorAll('button,input,select,a[href],[role=button]')].filter(el=>!el.disabled&&el.tabIndex>=0&&el.getClientRects().length));
  const current=document.activeElement,index=items.indexOf(current);
  if(['ArrowRight','ArrowLeft'].includes(key)&&current instanceof HTMLInputElement&&current.type==='range'){
    // Controller left/right on an original slider uses its 0x45fb80 steps.
    if(current.nativeSlider){current.nativeSlider.key(key);return;}
    const step=Number(current.step)||1;current.value=Number(current.value)+(key==='ArrowRight'?step:-step);current.dispatchEvent(new Event('input'));return;
  }
  if(['ArrowRight','ArrowLeft'].includes(key)&&current instanceof HTMLSelectElement){
    current.selectedIndex=(current.selectedIndex+(key==='ArrowRight'?1:-1)+current.options.length)%current.options.length;current.dispatchEvent(new Event('input'));return;
  }
  if(key==='Enter'||key==='Space'){if(index>=0)current.click();else items[0]?.focus();return;}
  const next=items[(index+(['ArrowDown','ArrowRight'].includes(key)?1:-1)+items.length)%items.length];next?.focus();next?.scrollIntoView({block:'nearest'});
}
function playIntro(){
  menuAudio?.stop();
  page='intro';mode='intro';input.setMode('menu');screen.hidden=true;hideRace();$('intro').hidden=false;
  moviePlayback.start('assets/media/intro.mp4',NATIVE_MOVIE_GAIN);
}
function finishIntro(){moviePlayback.stop();showMain();}
$('skip-movie').onclick=e=>{e.stopPropagation();finishIntro();};
$('movie').onended=()=>rewardDone?rewardDone():finishIntro();$('movie').onpointerdown=()=>{if(mode==='intro'&&!$('movie').paused)finishIntro();};
window.addEventListener('keydown',e=>{
  if(e.target===$('movie-audio')&&(e.code==='Enter'||e.code==='Space'))return;
  if(mode==='intro'&&!$('movie').paused&&nativeIntroSkipKey(e)){e.preventDefault();finishIntro();}
});
// recomp: a hidden page suspends a running race (its clock, sound and input) and a shown one resumes it; blur and a
// lost pad are the runner's (it pauses with the original's P).
document.addEventListener('visibilitychange',()=>{
  if(!runner?.active)return;
  try{document.hidden?runner.suspend():runner.resume();}catch(error){console.error(error);}
});
let portrait=matchMedia('(orientation: portrait)').matches;
window.addEventListener('resize',()=>{if(racing||runner?.active)return;const now=matchMedia('(orientation: portrait)').matches;if(now!==portrait){portrait=now;({main:showMain,characters:showCharacters,countries:showCountries})[page]?.();}});
// recomp: the menu's frame loop only polls the pad for menu navigation (the runner draws the race and its FPS counter).
function frame(time){
  input.poll(time);
  // recomp: the JS port's flight panel rule (main.js:871-872), shown only while the kart flies and the game does not
  // wait in its own pause or requester (the JS port's mode 'paused') nor sits under the settings
  const flying=!!runner?.active&&runner.flying&&!runner.waiting&&!raceMenu&&mode==='race';
  if(flightPanel.hidden===flying){flightPanel.hidden=!flying;flightTouch.hidden=!flying;}
  requestAnimationFrame(frame);
}
requestAnimationFrame(frame);
// Read-only diagnostics are used by automated checks; no simulated race completion.
window.rcsk={get state(){return {mode,page,selection:{...selection},settings:{...settings},racing,lastRunnerConfig,menuAudio:menuAudio?.last};},get runner(){return runner;}};
try{const [r,m,c,a]=await Promise.all([fetch('assets/ui/forms.json'),fetch('assets/menu/manifest.json'),fetch('assets/config.json'),fetch('assets/manifest.json')]);if(r.ok&&m.ok){forms=await r.json();nativeMenu=new NativeMenu(forms,await m.json(),commonPress);}if(c.ok)configs=await c.json();if(a.ok)assetManifest=await a.json();}catch(error){console.error(error);}
menuAudio=new MenuAudio(configs,()=>settings.effects,assetManifest);
if(nativeMenu)nativeMenu.language=configs['ini/shellang.ini']?.dutch||{};
adventureConfig=nativeAdventureConfiguration(configs);raceSave.locks??=[...adventureConfig.locks];
// recomp: one runner for the page; it owns the canvas, the touch controls and the FPS counter while a race runs.
// recomp: ?cheats lets the original's debug and cheat keys answer in races (Ctrl+F+I finishes one: tools/check-menu-race.mjs);
// without it they read "up", as the JS port has none (source/host/safeguards.js).
// recomp: a browser the race cannot run in (source/web/support.js: no cross-origin isolation, WebAssembly features, no
// WebGL 2 on an OffscreenCanvas) is told so at once, in a notice that stays, with the old version (classic/, the JS port,
// when the server has it) offered; the menu, its saves and highscores still work there, a race does not start.
const notRunnable=unsupported();
if(notRunnable){console.warn(`[${notRunnable.reason}] ${notRunnable.detail}`);showUnsupported(notRunnable.reason);}
else try{runner=new RaceRunner({canvas:$('game'),touchRoot:$('touch-controls'),fpsElement:$('fps-counter'),settings:{...settings},cheats:new URLSearchParams(location.search).has('cheats')});}catch(error){console.error(error);message('De race kan in deze browser niet starten: '+error.message);}
const params=new URLSearchParams(location.search);
// recomp: ?drive=N starts a QuickRace in country N with the saved character, difficulty and race type (the JS port's
// ?drive=N); ?track=N (the JS port's track viewer) does not exist here.
if(params.has('drive')&&/^[0-5]$/.test(params.get('drive'))){selection.country=Number(params.get('drive'));playMode='quickrace';startSelectedRace();}
else if(params.has('skipIntro'))showMain();else playIntro();
