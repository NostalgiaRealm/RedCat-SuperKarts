// Responsive arrangement of the original DFM elements. No replacement art,
// strings, controls, or listeners are created here; landscape stays in DFM space.
const supported = new Set([
  'TFRMOPTIONS', 'TFRMCONTROLSETTINGS', 'TFRMREQUESTER', 'TFRMEDITBOX',
  'TFRMADVENTUREMAIN', 'TFRMADVENTBRIEF', 'TFRMHIGHSCORE', 'TFRMENTERNAME',
  'TFRMMAIN', 'TFRMSELECTCHAR', 'TFRMSELECTCOUNTRY', 'TFRMLANDINFO', 'TFRMDEBRIEF',
]);
const css = `
.native-portrait-group{display:contents}
@media (orientation:portrait){
 .native-wrap:has(.native-portrait){align-items:start}
 .native-stage.native-portrait{width:100%;aspect-ratio:auto!important;min-height:calc(100dvh - 32px);padding:14px 10px;display:flex;flex-direction:column;gap:16px;isolation:isolate;overflow:hidden}
 .native-portrait .native-portrait-group{display:flex;position:relative;gap:10px;align-items:center;justify-content:center;flex-wrap:wrap;min-width:0}
 .native-portrait [data-element]{position:relative!important;inset:auto!important;flex-shrink:0}
 .native-portrait .native-image{width:min(var(--portrait-native-width),100%)!important;height:auto!important;max-width:100%;object-fit:contain}
 .native-portrait .native-label{width:auto!important;height:auto!important;min-height:24px;max-width:100%;font-size:15px!important;line-height:1.4;white-space:normal!important;overflow-wrap:anywhere}
 .native-portrait .native-button{width:calc(var(--portrait-ratio) * 46px)!important;height:46px!important;min-height:46px;max-width:100%;font-size:14px!important;padding:0}
 .native-portrait .native-button>span{inset:0 0 0 24%!important;width:auto!important;height:auto!important;display:flex!important;align-items:center;justify-content:center;white-space:nowrap;font-size:inherit!important}
 .native-portrait .native-radio>span{left:12%!important}
 .native-portrait .native-slider{width:100%!important;max-width:260px;height:48px!important}
 .native-portrait .native-slider::-webkit-slider-thumb{width:40px;height:40px}
 .native-portrait .native-slider::-moz-range-thumb{width:40px;height:40px}
 .native-portrait .native-edit{width:100%!important;height:46px!important;padding:8px;font-size:16px!important}
 .native-portrait [data-portrait=backdrop]{position:absolute!important;inset:0!important;width:100%!important;height:100%!important;object-fit:cover;z-index:-2;pointer-events:none}
 .native-portrait [data-portrait=header]{justify-content:space-between}
 .native-portrait [data-portrait=brand]{width:161px!important}
 .native-portrait [data-portrait=title]{align-self:center;max-width:100%}
 .native-portrait [data-portrait=footer]{margin-top:auto;justify-content:space-between;padding-top:8px}
 .native-portrait [data-portrait=options-columns]{display:grid;grid-template-columns:repeat(2,minmax(0,1fr));align-items:stretch;gap:8px}
 .native-portrait [data-portrait=options-panel]{flex-direction:column;flex-wrap:nowrap;padding:8px 3px 18px;gap:6px;overflow:hidden;min-height:332px}
 .native-portrait [data-portrait=panel-art]{position:absolute!important;inset:0!important;width:100%!important;height:100%!important;object-fit:fill;z-index:-1;pointer-events:none}
 .native-portrait [data-portrait=panel-title]{max-width:none;width:262px!important;height:33px!important}
 .native-portrait [data-portrait=options-panel] .native-button{width:calc(var(--portrait-ratio) * 44px)!important;height:44px!important;min-height:44px;font-size:13px!important}
 .native-portrait [data-portrait=volume]{flex-direction:column;gap:0}
 .native-portrait [data-portrait=volume] .native-image{width:262px!important}
 .native-portrait [data-portrait=unused-track-art]{display:none}
 .native-portrait [data-portrait=check-row]{flex-wrap:nowrap;justify-content:flex-start}
 .native-portrait [data-portrait=check-row] .native-label{flex:1;min-width:0}
 .native-portrait [data-portrait=check-row] .native-button>span{display:none!important}
 .native-portrait [data-portrait=key-row]{display:grid;grid-template-columns:minmax(0,1fr) 106px;justify-content:stretch;gap:12px}
 .native-portrait [data-portrait=key-row]>.native-label{justify-content:flex-start!important}
 .native-portrait [data-portrait=key]{width:106px;height:54px;display:grid;place-items:center}
 .native-portrait [data-portrait=key] .native-image{width:auto!important;height:54px!important;max-width:106px}
 .native-portrait [data-portrait=key] .native-label{position:absolute!important;inset:0!important;margin:auto;justify-content:center!important;pointer-events:none;color:black!important}
 .native-portrait [data-portrait=request]{flex-wrap:nowrap;align-items:center;padding:24px 0}
 .native-portrait [data-portrait=request] .native-label{flex:1;min-width:0;font-size:17px!important}
 .native-portrait [data-portrait=request] .native-image{width:81px!important}
 .native-portrait[data-form=TFRMREQUESTER],.native-portrait[data-form=TFRMEDITBOX]{min-height:300px}
 .native-portrait [data-portrait=carousel]{display:block;width:100%;aspect-ratio:345/177;container-type:inline-size;flex-shrink:0}
 .native-portrait [data-portrait=carousel]>[data-element]{position:absolute!important;left:var(--portrait-x)!important;top:var(--portrait-y)!important;width:var(--portrait-w)!important;height:var(--portrait-h)!important;max-width:none;font-size:4.35cqw!important}
 .native-portrait [data-portrait=carousel]>.native-label{min-height:0;white-space:nowrap!important}
 .native-portrait [data-portrait=carousel]>.native-button{min-width:44px;min-height:44px}
 .native-portrait [data-portrait=carousel]>.native-button>span{display:none!important}
 .native-portrait [data-portrait=progress]{flex-direction:column;align-items:stretch;gap:8px}
 .native-portrait [data-portrait=country-row]{display:grid;grid-template-columns:52px repeat(4,minmax(0,1fr));justify-items:center;gap:6px}
 .native-portrait [data-portrait=country-row]>.native-image{width:auto!important;max-width:100%;height:41px!important}
 .native-portrait [data-portrait=country-row]>.native-image:not(:first-child){height:30px!important}
 .native-portrait [data-portrait=score]{display:grid;grid-template-columns:30px 44px minmax(0,1fr);gap:2px 10px;justify-items:start;align-items:center}
 .native-portrait [data-portrait=score]>.native-image{width:40px!important;height:40px!important;grid-column:2;grid-row:1/4}
 .native-portrait [data-portrait=rank]{grid-column:1;grid-row:1/4}
 .native-portrait [data-portrait=score]>.native-label:not([data-portrait=rank]){grid-column:3;justify-content:flex-start!important;font-size:14px!important}
 .native-portrait [data-portrait=score]>.native-label:empty{display:none}
 .native-portrait [data-portrait=briefing]{align-items:flex-start;flex-wrap:nowrap}
 .native-portrait [data-portrait=briefing]>.native-label{flex:1}
 .native-portrait [data-portrait=briefing]>.native-image{width:73px!important}
 .native-portrait [data-portrait=time-row]{justify-content:space-between}
 .native-portrait [data-portrait=main-cards]{display:grid;grid-template-columns:repeat(2,minmax(0,132px));gap:18px 12px;justify-content:center}
 .native-portrait [data-portrait=main-cards]>.native-button{width:100%!important;height:auto!important;aspect-ratio:132/162;max-width:132px}
 .native-portrait [data-portrait=main-cards]>.native-button:last-child{grid-column:1/3;justify-self:center;width:132px!important}
 .native-portrait [data-portrait=main-cards]>.native-button>span{inset:auto 0 0!important;height:22.222%!important;font-size:14px!important}
 .native-portrait [data-portrait=section-title]{width:min(262px,100%);height:49px;align-self:center}
 .native-portrait [data-portrait=section-title]>.native-image{position:absolute!important;left:50%!important;top:50%!important;transform:translate(-50%,-50%)}
 .native-portrait [data-portrait=choices]{flex-direction:column;gap:8px}
 .native-portrait [data-portrait=photos]{display:grid;grid-template-columns:repeat(2,121px);gap:18px 12px;justify-content:center}
 .native-portrait [data-portrait=photo]{width:121px;height:137px;display:block}
 .native-portrait [data-portrait=photo]>.native-image{position:absolute!important;inset:0!important;width:121px!important;height:137px!important}
 .native-portrait [data-portrait=photo]>.native-label{position:absolute!important;left:8px!important;right:0!important;bottom:0!important;top:auto!important;height:30px!important;min-height:0;display:flex;align-items:center;justify-content:center!important;text-align:center!important;line-height:1.1;font-size:12px!important;pointer-events:none}
 .native-portrait [data-portrait=finishers]{gap:16px 12px}
 .native-portrait [data-portrait=finisher]{width:89px;height:97px;display:block}
 .native-portrait [data-portrait=finisher]>.native-image:first-child{position:absolute!important;left:16px!important;top:0!important;width:73px!important;height:89px!important}
 .native-portrait [data-portrait=finisher]>.native-image:last-child:not(:first-child){position:absolute!important;left:0!important;bottom:0!important;top:auto!important;width:37px!important;height:33px!important}
 .native-portrait [data-portrait=result]{flex-wrap:nowrap;align-items:center;gap:10px}
 .native-portrait [data-portrait=result]>.native-image{width:100px!important}
 .native-portrait [data-portrait=result-details]{flex:1;flex-direction:column;align-items:flex-start;min-width:0;gap:10px}
 .native-portrait [data-portrait=result-details]>.native-label{font-size:14px!important}
}
@media (orientation:portrait) and (max-width:359px){
 .native-portrait [data-portrait=options-columns]{grid-template-columns:1fr;justify-items:center}
 .native-portrait [data-portrait=options-panel]{width:180px}
 .native-portrait [data-portrait=footer]{gap:6px}
 .native-portrait [data-portrait=footer]>.native-button{width:calc(var(--portrait-ratio) * 44px)!important;height:44px!important;min-height:44px}
}
`;

/** Reflow supported DFM forms in portrait, retaining every live control.
 * Call once after NativeMenu has created the stage. Safe to call repeatedly.
 * Returns whether a layout was installed; CSS handles subsequent rotation.
 */
export function adaptNativePortrait(stage, formName = stage.dataset.form) {
  if (!supported.has(formName)) return false;
  if (stage.classList.contains('native-portrait')) return true;
  const doc = stage.ownerDocument;
  if (!doc.getElementById('native-portrait-style')) {
    const style = doc.createElement('style');
    style.id = 'native-portrait-style'; style.textContent = css;
    doc.head.append(style);
  }
  const dimensions = stage.style.aspectRatio.split('/').map(Number);
  const [width, height] = dimensions.length === 2 ? dimensions : [640, 480];
  const elements = new Map([...stage.querySelectorAll('[data-element]')].map(e => [e.dataset.element, e]));
  const sourceRects = new Map();
  for (const element of elements.values()) {
    const rect = {x: parseFloat(element.style.left) * width / 100,
      y: parseFloat(element.style.top) * height / 100,
      w: parseFloat(element.style.width) * width / 100,
      h: parseFloat(element.style.height) * height / 100};
    sourceRects.set(element, rect);
    element.style.setProperty('--portrait-native-width', `${rect.w}px`);
    element.style.setProperty('--portrait-ratio', rect.h > 0 ? rect.w / rect.h : 1);
  }
  const mark = (name, role) => { const e = elements.get(name); if (e) e.dataset.portrait = role; return e; };
  const group = (role, names, parent = stage) => {
    const members = names.map(name => typeof name === 'string' ? elements.get(name) : name).filter(Boolean);
    if (!members.length) return null;
    const wrapper = doc.createElement('div');
    wrapper.className = 'native-portrait-group'; wrapper.dataset.portrait = role;
    parent.append(wrapper); wrapper.append(...members); return wrapper;
  };
  // Multiple native forms carry a duplicate full-size backdrop.
  for (const element of elements.values()) {
    const r = sourceRects.get(element);
    if (element.matches('img') && r.x === 0 && r.y === 0 && r.w >= width && r.h >= height)
      element.dataset.portrait = 'backdrop';
  }
  const brand = [...elements.values()].find(e => e.matches('img') && /mn_0003x\.png$/i.test(e.src));
  if (brand) brand.dataset.portrait = 'brand';
  group('header', [brand, 'btnMainOptions', 'btnMainHelp', 'btnHelp', 'btnMainStop', 'btnQuit']);
  for (const name of ['imgPhaseTitle', 'imgScreentitle', 'imgDebriefTitle']) {
    const title = mark(name, 'title'); if (title) stage.append(title);
  }
  const carousel = (names, x, y) => {
    const wrapper = group('carousel', names);
    if (!wrapper) return;
    for (const child of wrapper.children) {
      const r = sourceRects.get(child);
      child.style.setProperty('--portrait-x', `${(r.x - x) / 345 * 100}%`);
      child.style.setProperty('--portrait-y', `${(r.y - y) / 177 * 100}%`);
      child.style.setProperty('--portrait-w', `${r.w / 345 * 100}%`);
      child.style.setProperty('--portrait-h', `${r.h / 177 * 100}%`);
    }
  };
  const progress = () => {
    const rows = [];
    const countries = ['imgHOLLAND', 'imgGermany', 'imgUK', 'imgFRANCE', 'imgSPAIN', 'imgITALY'];
    for (let i = 0; i < countries.length; i++) rows.push(group('country-row',
      [countries[i], ...['NORMALRACE', 'TIMETRIAL', 'ITEMRACE', 'DUELRACE'].map(type => `img${i}${type}`)]));
    group('progress', rows);
  };
  if (formName === 'TFRMMAIN') {
    group('main-cards', ['btnAdventure', 'btnQuickRace', 'btnHighscore']);
  } else if (formName === 'TFRMSELECTCHAR') {
    carousel(['DaviImage3','imgPrevious','imgNext','imgCurrent','imgCharBorder','imgCharText',
      'lblCharname','btnPrevious','btnNext'],152,102);
    group('section-title',['DaviImage2','imgDifficulty']);
    group('choices',['rdoEasy','rdoMedium','rdoHard']);
  } else if (formName === 'TFRMSELECTCOUNTRY') {
    carousel(['DaviImage2','imgRightSelected','imgSelectedCountry','imgLeftSelected','DaviImage3',
      'imgCountryText','lblCountryName','btnLeft','btnRight'],152,102);
    group('section-title',['imgDiff','imgTypeText']);
    group('choices',['rdoCountry','rdoTime','rdoItem']);
  } else if (formName === 'TFRMLANDINFO') {
    const photos=[];
    for(let i=1;i<=4;i++)photos.push(group('photo',[`imgPhoto${i}`,`lblPhoto${i}`]));
    group('photos',photos);
  } else if (formName === 'TFRMDEBRIEF') {
    const character=elements.get('imgCharacter');if(character)stage.append(character);
    const finishers=[];
    for(let i=1;i<=5;i++)finishers.push(group('finisher',[`imgPosition${i}`,`imgFinPos${i}`]));
    group('finishers',finishers);
    const details=group('result-details',['lblPlayerName','lblTotal','lblBestLap']);
    group('result',['imgReward',details]);
  } else if (formName === 'TFRMOPTIONS') {
    const panels = [
      group('options-panel', ['DaviImage2', 'imgControlTitle', 'imgControlPic', 'rdoKeyboard', 'rdoJoystick', 'rdoGamepad', 'btnControlsAdvanced']),
      group('options-panel', ['DaviImage1', 'imgDisplayTitle', 'imgResPic', 'rdoLowQual', 'rdoHighQual', 'btnAdvanced', 'chk3dCard']),
    ];
    mark('DaviImage1', 'panel-art'); mark('DaviImage2', 'panel-art');
    mark('imgControlTitle', 'panel-title'); mark('imgDisplayTitle', 'panel-title');
    group('options-columns', panels);
    mark('DaviImage3', 'unused-track-art'); mark('DaviImage4', 'unused-track-art');
    group('volume', ['imgMusicText', 'sldMusicVolume']);
    group('volume', ['imgEffectText', 'sldEffectVolume']);
    group('check-row', ['chkStartInfo', 'lblStartInfo']);
  } else if (formName === 'TFRMCONTROLSETTINGS') {
    const help = elements.get('lblHelp'); if (help) stage.append(help);
    for (const [key, label] of [['ACCELERATE','Forward'],['BRAKE','Backwards'],['STEERLEFT','Left'],
      ['STEERRIGHT','Right'],['USEBONUS','Bonus'],['HANDBRAKE','Handbrake']]) {
      const control = group('key', [`imgKEY_${key}`, `lblKEY_${key}`]);
      group('key-row', [`lbl${label}`, control]);
    }
    group('actions', ['btnDefault']);
    group('check-row', ['chkShowInfo', 'lblShowStartInfo']);
  } else if (formName === 'TFRMREQUESTER' || formName === 'TFRMEDITBOX') {
    group('request', ['imgIcon', formName === 'TFRMREQUESTER' ? 'lblQuit' : 'lblNameText']);
    const edit = elements.get('edtName'); if (edit) stage.append(edit);
  } else if (formName === 'TFRMADVENTUREMAIN') {
    carousel(['DaviImage3','imgRightSelected','imgSelected','imgLeftSelected','DaviImage4',
      'imgPlayerText','lblPlayerName','btnLeft','btnRight'], 156, 70);
    group('actions', ['btnNewPlayer', 'btnDeletePlayer']); progress();
  } else if (formName === 'TFRMADVENTBRIEF') {
    group('actions', ['lblCountry', 'lblType']);
    group('briefing', ['lblBriefing', 'imgCountryRacer']); progress();
    group('time-row', ['lblTrackTime', 'lblTrackTimeString']);
    group('time-row', ['lblLapTime', 'lblLapTimeString']);
    group('actions', ['btnOverview']);
  } else if (formName === 'TFRMHIGHSCORE') {
    carousel(['DaviImage9','imgRightSelected','imgSelectedCountry','imgLeftSelected','DaviImage10',
      'imgCountryText','lblCountryName','btnLeft','btnRight'], 8, 118);
    for (let i = 1; i <= 5; i++) {
      const rank = `lbl${['One','Two','Three','Four','Five'][i-1]}`;
      mark(rank, 'rank'); group('score', [rank, `imgHigh${i}`, `lblName${i}`, `lblRound${i}`, `lblDiff${i}`]);
    }
  } else if (formName === 'TFRMENTERNAME') {
    for (let i = 1; i <= 5; i++) {
      const rank = `lbl${['One','Two','Three','Four','Five'][i-1]}`;
      mark(rank, 'rank'); group('score', [rank, `imgHigh${i}`, `lbl${['First','Second','Third','Fourth','Fifth'][i-1]}`]);
    }
    for (const name of ['Label3', 'DaviEdit21']) if (elements.has(name)) stage.append(elements.get(name));
  }
  group('footer', ['btnBack', 'btnCancel', 'btnOk']);
  stage.classList.add('native-portrait');
  return true;
}
