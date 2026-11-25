// Copied unchanged from the JavaScript reconstruction: ../RedCat Superkarts/source/native-help-context.js at commit 5bfe0b62 (1.0.3).
// Change it there first and copy it again; the recomp's menu keeps the JS port's code as it is.
// Numeric HELP_CONTEXT destinations from rcskmenu.dat's Help button handlers.
// The HLP's recovered string names are not authoritative; its numeric MAP is.
const contexts=Object.freeze({
  main:1,settings:2,controls:3,'start-info':3,
  adventure:5,briefing:7,countries:10,
  // Keep the port's direct Highscores topic access. The original HLP maps 4,
  // but TfrmHighscore has no Help button or corresponding click handler.
  highscores:4,
});

export function nativeHelpContext(page,{playMode='quickrace'}={}){
  // 0047429c: Quickrace mode 2 selects 9; adventure selection selects 6.
  if(page==='characters')return playMode==='adventure'?6:9;
  // 00473530: active Adventure mode 3 selects 11; Quickrace selects 12.
  if(page==='debrief')return playMode==='adventure'?11:12;
  return Object.hasOwn(contexts,page)?contexts[page]:null;
}

export function nativeHelpNotice(page){
  // 00477a60 opens localized notice 46 rather than invoking WinHelp.
  return page==='country-info'?46:null;
}
