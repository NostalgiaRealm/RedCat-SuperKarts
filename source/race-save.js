import {insertNativeHighscore} from './simulation/native-results.js';

const key='rcsk.race-save.v1';
const emptyEntry=()=>({name:'',character:0,totalRaceMs:0,bestLapMs:0,difficulty:0});
const empty=()=>({boards:Array.from({length:6},()=>Array.from({length:5},emptyEntry)),
  bestTimes:{},lastResult:null,quickRaceName:'Speler 1',
  profiles:Array(30).fill(null),selectedSlot:-1,locks:null});
const validPosition=value=>Number.isInteger(value)&&value>=0&&value<=9;
// Race.ini PLAYER.position survives unfinished races. Saves from before this
// field only kept it inside a finished lastResult.
const savedPlayerPosition=save=>validPosition(save.playerPosition)?save.playerPosition
  :save.lastResult?.PLAYER?.finished&&validPosition(save.lastResult.PLAYER.position)
    ?save.lastResult.PLAYER.position:undefined;

/** Browser persistence adapter. Original records stay separate from source INIs. */
export function readRaceSave(storage){
  const result=empty();
  try{
    if(storage===undefined)storage=globalThis.localStorage;
    const value=JSON.parse(storage.getItem(key));
    if(!value||typeof value!=='object')return result;
    if(typeof value.quickRaceName==='string')result.quickRaceName=value.quickRaceName;
    if(value.bestTimes&&typeof value.bestTimes==='object')
      for(const [name,time]of Object.entries(value.bestTimes))
        if(/^(lap_record|race_record|time_check_count)_e[0-5]$|^time_check_e[0-5]_c[0-8]$/.test(name)
          &&Number.isInteger(time)&&time>=0)result.bestTimes[name]=time;
    if(Array.isArray(value.boards))value.boards.slice(0,6).forEach((board,country)=>{
      if(!Array.isArray(board)||board.length!==5)return;
      board.forEach((entry,index)=>{
        if(entry&&typeof entry.name==='string'&&Number.isInteger(entry.character)
          &&entry.character>=0&&entry.character<=9&&Number.isInteger(entry.difficulty)
          &&entry.difficulty>=0&&entry.difficulty<=2
          &&Number.isInteger(entry.totalRaceMs)&&entry.totalRaceMs>=0
          &&Number.isInteger(entry.bestLapMs)&&entry.bestLapMs>=0)
          result.boards[country][index]={name:entry.name,character:entry.character,
            totalRaceMs:entry.totalRaceMs,bestLapMs:entry.bestLapMs,difficulty:entry.difficulty};
      });
    });
    if(value.lastResult&&typeof value.lastResult==='object')result.lastResult=value.lastResult;
    if(validPosition(value.playerPosition))result.playerPosition=value.playerPosition;
    if(Array.isArray(value.locks)&&value.locks.length===6&&value.locks.every(v=>typeof v==='boolean'))
      result.locks=[...value.locks];
    if(Array.isArray(value.profiles))value.profiles.slice(0,30).forEach((profile,slot)=>{
      if(profile&&typeof profile.name==='string'&&profile.name.length<=20
        &&Number.isInteger(profile.character)&&profile.character>=0&&profile.character<4
        &&Number.isInteger(profile.difficulty)&&profile.difficulty>=0&&profile.difficulty<3
        &&Number.isInteger(profile.adventure)&&profile.adventure>=0&&profile.adventure<30
        &&Array.isArray(profile.matrix)&&profile.matrix.length===6
        &&profile.matrix.every(row=>Array.isArray(row)&&row.length===5&&row.every(v=>v===0||v===1)))
        result.profiles[slot]={...structuredClone(profile),slot};
    });
    if(Number.isInteger(value.selectedSlot)&&result.profiles[value.selectedSlot])
      result.selectedSlot=value.selectedSlot;
  }catch{}
  return result;
}

export function writeRaceSave(save,storage){
  try{
    if(storage===undefined)storage=globalThis.localStorage;
    storage.setItem(key,JSON.stringify(save));return true;
  }catch{return false;}
}

/** Explicit extra-settings action; never reset profiles, records or progress. */
export function unlockAllCountries(save,storage){
  const unlocked={...save,locks:Array(6).fill(false)};
  if(!writeRaceSave(unlocked,storage))return false;
  save.locks=unlocked.locks;
  return true;
}

export function applyRaceResult(save,patch){
  const position=validPosition(patch.PLAYER?.position)?patch.PLAYER.position:savedPlayerPosition(save);
  if(position!==undefined)save.playerPosition=position;
  save.lastResult=structuredClone(patch);
  for(const [name,value]of Object.entries(patch['BEST TIMES']??{}))save.bestTimes[name.toLowerCase()]=value;
}

export function saveHighscore(save,country,record){
  const result=insertNativeHighscore(save.boards[country],record);
  save.boards[country]=result.entries;
  save.quickRaceName=record.name;
  return result.index;
}

export function configWithRaceSave(config,save){
  const position=savedPlayerPosition(save);
  return {...config,'race.ini':{...config['race.ini'],
    player:{...config['race.ini'].player,...(position===undefined?{}:{position:String(position)})},
    'best times':{...config['race.ini']['best times'],...save.bestTimes}}};
}
