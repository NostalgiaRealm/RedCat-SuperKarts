import fs from 'node:fs/promises';
import {getSoundSpec} from '../source/asset-animation.js';
import {getNativeScenerySounds,getNativeReactiveSounds} from '../source/spatial-audio.js';
import {NativeVoiceController} from '../source/native-voice-controller.js';
import {NATIVE_DIRECT_RACE_SOUNDS} from '../source/native-race-audio.js';

const read = path => fs.readFile(path,'utf8').then(JSON.parse);
const [config,manifest,decode,voices,menu,media,race,mixing] = await Promise.all([
  read('public/assets/config.json'),read('public/assets/manifest.json'),
  ...['all-assets-decode','browser-voices','menu-playback','media-playback','race-trigger-playback','browser-mixing']
    .map(name=>read(`evidence/audio/${name}.json`)),
]);
const sourceFixture = await read('evidence/native/audio-mixing-fixtures.json');
const records = Object.entries(config['sound.ini'].sndtypes).filter(([key])=>/^\d+$/.test(key))
  .map(([index,value])=>{
    const fields=value.split(/[,=:]/).map(v=>v.trim()),resolved=getSoundSpec(config,manifest,fields[0]);
    return {index:Number(index),event:fields[0],source:fields[1],file:resolved?.file??null,
      groups:fields[6].split('|'),sourceVolume:Number(fields[3])};
  });
const tracks = [];
for(const entry of manifest.tracks){
  const track=await read(`public/assets/${entry.file}`);
  tracks.push({id:track.id,
    attached:getNativeScenerySounds(config,manifest,track).map(sound=>({
      placementIndex:sound.placementIndex,event:sound.sound.event,file:sound.sound.file})),
    reactive:getNativeReactiveSounds(config,manifest,track).map(sound=>({
      placementIndex:sound.placementIndex,event:sound.sound.event,file:sound.sound.file})),
  });
}
const voiceBanks = [];
for(const roster of [[4,5,6,7,0],[5,6,7,8,1],[6,7,8,9,2],[4,6,8,9,3]]){
  const controller=new NativeVoiceController(config,manifest,roster);
  controller.banks.forEach((bank,voiceId)=>{
    if(bank.length&&!voiceBanks.some(entry=>entry.voiceId===voiceId))
      voiceBanks.push({voiceId,samples:bank.map(({sample,event,sound})=>({sample,event,file:sound.file}))});
  });
}
const targets=new Set(['0049d780','0043b600','00437b10','00437b40','0048f010']);
const callsites=(await fs.readFile('evidence/native/rcskspel.dat/calls.tsv','utf8')).trimEnd().split('\n')
  .map(line=>line.split('\t')).filter(columns=>targets.has(columns[2]))
  .map(([caller,address,target,,kind])=>({caller:caller||null,address,target,kind}));
const coverage=[
  {category:'Menu navigation, selection, options, country information and debrief voices',
    native:['rcskmenu45c518','rcskmenu45c668','rcskmenu45c720'],
    runtime:['source/menu-audio.js','source/main.js'],evidence:['menu-playback.json'],
    limits:'Five referenced menu WAV names are absent from both supplied sources; menu-sources.json retains them without substitutes.'},
  {category:'Movies and six looping race music streams',
    native:['RCMovie SmackOpen','42d7d0','48ec20','48ef80','431610','48f010'],
    runtime:['source/main.js','source/game-audio.js'],evidence:['media-playback.json'],
    limits:'Music follows original DirectShow gain conversion; movie sound uses its original full source level. Browser codec output is not an original sound-card recording.'},
  {category:'Player starter, engine layers and gear effect',
    native:['418950','418c10','418c80'],runtime:['source/engine-audio.js','source/native-race-audio.js'],
    evidence:['browser-engine.json','browser-mixing.json'],limits:'Original car0 settings are used for all karts. Cylinder scheduler418ad0 is gated off by the empty shipped Cylinders sample list.'},
  {category:'Tyre loop and pitch',
    native:['432240','432190'],runtime:['source/skid-audio.js','source/driving-view.js'],
    evidence:['browser-engine.json'],limits:'SFXVOLUME gates the handler; controller enable gates a new start. Existing loop pitch/stop order is preserved.'},
  {category:'Ambient attached and moving scenery',
    native:['43f020','43b790','49da60','447210'],runtime:['source/spatial-audio.js','source/native-race-audio.js'],
    evidence:['browser-spatial.json'],limits:'311 independent attached sources; hidden callbacks preserve already playing audio, path stop explicitly stops it. Previous listener snapshot is used.'},
  {category:'Reactive cones and props',
    native:['43e140','43b760','43fe80','43b790'],runtime:['source/simulation/native-scenery-reactions.js','source/native-race-audio.js'],
    evidence:['browser-spatial.json','race-trigger-playback.json'],limits:'174 independent PION_HIT_CAR clones, one nonloop spatial update at launch. No shared global impact source.'},
  {category:'Pickup and five weapon firing effects',
    native:['4540c0','4542c0','455490','451640'],runtime:['source/bonus-audio.js','source/simulation/native-bonus.js','source/simulation/native-combat.js'],
    evidence:['race-trigger-playback.json','browser-voices.json'],limits:'Player-only EFFECTS queue. Static random type7 requests absent GOT_BONUS; collectible type6 requests absent GOT_EURO. These are preserved original missing names.'},
  {category:'Hits, passing, catchup, boost, pickup and attacker/victim character speech',
    native:['40d9c0','4106b0','40d260','40de60','411830','411b40','411e50','412090','437c40','437ff0..4387e0','440a90'],
    runtime:['source/simulation/native-character-voice.js','source/native-voice-controller.js','source/native-race-audio.js'],
    evidence:['browser-voices.json','race-trigger-playback.json'],limits:'Native selector/chance RNG and request ordering are tested separately against original instructions; 327 logical bank entries reach actual sources. Not every random speech branch is reached by a complete driven race.'},
  {category:'Lap and record announcements, countdown and time gates',
    native:['430610','464a70','42f170','441e70','442570'],
    runtime:['source/simulation/native-character-voice.js','source/simulation/native-countdown.js','source/race-simulation.js'],
    evidence:['browser-voices.json'],limits:'COMM announcements use effects FIFO10; STARTSE1..4,TIME_TICK,CHECKPOINT are direct effects with native repeat suppression.'},
  {category:'Player contact and scrape',
    native:['434c40','4350b0','434ea0','434f20'],runtime:['source/native-crash-audio.js','source/race-simulation.js'],
    evidence:['browser-voices.json'],limits:'840 original selector cases and192 contact-latch cases verify shared RNG and duplicate callbacks. Seven direct effect sources preload before contact.'},
  {category:'Recovery disappearance/reappearance',
    native:['48ca60','437ea0','437b10'],runtime:['source/simulation/native-rescue.js','source/simulation/native-character-voice.js'],
    evidence:['race-trigger-playback.json'],limits:'DISAPP/REAPP go to recovered racer logical voice FIFO at pre-update frame3, with no chance or RNG draw.'},
  {category:'Homing-rocket warning beeps',
    native:['456440','486b20','486ea0','4879c0'],runtime:['source/simulation/native-homing-arm.js','source/arm-audio.js'],
    evidence:['race-trigger-playback.json'],limits:'Actual target-player arm ratio, strict float32 .1 timer and .4/.7 thresholds;1200 instruction cases includeNaN/Infinity. Queues after current voice service.'},
  {category:'Hardwired Space sound',
    native:['42f9c0'],runtime:['source/native-key-audio.js','source/race-simulation.js'],
    evidence:['race-trigger-playback.json'],limits:'Native available-character-index to racer-index mismatch, missing CLAXON replacement and directKT4 preserved, outside debug guard.'},
];
const report={
  format:'superkarts-audio-coverage-v1',sourceSha256:sourceFixture.sourceSha256,
  scope:'Inventory distinguishes decoded assets, original-instruction fixtures, browser transport and controlled live gameplay dispatch. It does not claim every random branch was reached during a complete race or auditory equality with an original sound-card recording.',
  assets:{wav:decode.wav,streams:decode.streams,silentPCM:decode.silent,records:records.length,
    uniqueEvents:new Set(records.map(x=>x.event.toLowerCase())).size,missingSoundTypeFiles:records.filter(x=>!x.file)},
  directEvents:NATIVE_DIRECT_RACE_SOUNDS,records,tracks,voiceBanks,callsites,coverage,
  originalMissingLogicalNames:[
    {name:'CLAXON',scope:'all character banks',callers:['40d9c0','42f9c0']},
    {name:'GOT_BONUS',scope:'effects',callers:['4542c0 default/random']},
    {name:'GOT_EURO',scope:'effects',callers:['4542c0 type6']},
    {name:'SOAP_UP1..3',scope:'effects',callers:['411b40'],note:'Bank has SOAP_UP without numeric suffix; not substituted.'},
    {name:'FIRE_TURBO',scope:'effects',callers:['440a90'],note:'Bank has FIRE_TURBO1..3; not substituted.'},
  ],
  excludedSourceBranches:[
    {native:['418ad0'],reason:'Car_Snd.ini car0 has no Cylinders list; scheduler returns before RNG/playback.'},
    {native:['41f7e0','41f870','41f900'],reason:'Legacy police chase/arrest code references START_CHASE/QUIT_CHASE/ARREST events absent from active Sound.ini and active race roster; not synthesized.'},
    {native:['432460'],reason:'Legacy super-traction routine has no recorded incoming call and initial sound ID-1; no active trigger established.'},
  ],
  verification:{
    decodedAssets:decode.total,logicalVoiceStarts:voices.banks.length,directTransportStarts:voices.direct.length,
    liveFixtureCount:race.rows.length,liveSourceStarts:race.rows.reduce((n,row)=>n+row.starts.length,0),
    reports:['all-assets-decode.json','menu-playback.json','media-playback.json','settings-playback.json','browser-engine.json',
      'browser-spatial.json','browser-voices.json','race-trigger-playback.json','browser-mixing.json'],
    browser:mixing.browser,
  },
};
await fs.writeFile('evidence/audio/coverage.json',JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({records:records.length,uniqueEvents:report.assets.uniqueEvents,
  banks:voiceBanks.length,logicalSamples:voiceBanks.reduce((n,b)=>n+b.samples.length,0),
  ambient:tracks.reduce((n,t)=>n+t.attached.length,0),reactive:tracks.reduce((n,t)=>n+t.reactive.length,0),
  callsites:callsites.length,liveFixtures:race.rows.length,missing:report.assets.missingSoundTypeFiles.length}));
