/** Original shell45ae70 and race42c320 use Race.ini GAME_SETTINGS.
 * SndGfx MUSICVOLUME is an older setting, not the streamed race music level. */
export function nativeAudioPercent(value,fallback=0){
 const number=Number(value);return Number.isFinite(number)?Math.max(0,Math.min(100,Math.trunc(number))):fallback;
}
export function getNativeAudioSettings(config){
 const race=config['race.ini']?.game_settings??{};
 return {musicPercent:nativeAudioPercent(race.mx_volume),effectsPercent:nativeAudioPercent(race.fx_volume),
  effectsEnabled:nativeAudioPercent(race.effects)!==0,
  soundEnabled:nativeAudioPercent(config['sndgfx.ini']?.sound?.on)!==0,
  //429050 returns the legacy SFXVOLUME integer, not the SOUND.ON flag.
  skidEnabled:nativeAudioPercent(config['sndgfx.ini']?.sound?.sfxvolume)!==0};
}

/** 437560 load order: matching named groups replace source volume in sequence,
 * then437e30 replaces all non-MOTOR/non-MUSIC static sources with FX_VOLUME.
 * This changes local percentages; engine master49e0a0 remains100. */
export function nativeStaticSoundVolume(config,sound,{effectsPercent,effectsEnabled=true}={}){
 const groups=new Set(sound.fields[6].split('|').map(name=>name.trim().toLowerCase()));
 let volume=Number(sound.fields[3]);
 const overrides=config['rcrsound.ini']?.volumes??{};
 for(let index=0;index<Number(overrides.count??0);index++){
  const group=String(overrides[index]).toLowerCase();
  if(groups.has(group))volume=Number(overrides[group]);
 }
 if(effectsEnabled&&nativeEffectsAffectsSound(sound))volume=nativeAudioPercent(effectsPercent);
 return volume;
}
export function nativeSoundGroups(sound){return sound.fields[6].split('|').map(name=>name.trim().toLowerCase());}
/**49e970 uses any overlapping group bit, not an exclusion by event name. */
export function nativeEffectsAffectsSound(sound){
 return nativeSoundGroups(sound).some(group=>group!=='motor'&&group!=='music');
}

/**437e30 writes all matching current sources and clears voice queues at0.
 * Negative inputs clamp volume but retain the enable byte, as native code. */
export function nativeAudioControllerChange(enabled,requestedPercent){
 const percent=Math.trunc(requestedPercent);
 return {enabled:percent>0?true:percent===0?false:!!enabled,
  volumePercent:nativeAudioPercent(percent),clearQueues:percent===0};
}

/** The original loader repairs enabled effects at zero to75 in Race.ini.
 * Keep this explicit: a later437e30(0) instead disables/clears voice queues. */
export function nativeAudioLoadSettings(config,{effectsPercent,effectsEnabled}={}){
 const settings=getNativeAudioSettings(config);
 if(effectsPercent!==undefined)settings.effectsPercent=nativeAudioPercent(effectsPercent);
 if(effectsEnabled!==undefined)settings.effectsEnabled=!!effectsEnabled;
 if(settings.effectsEnabled&&settings.effectsPercent===0)settings.effectsPercent=75;
 settings.controllerEnabled=settings.effectsEnabled;
 return settings;
}

// Menu45c518/45c668 use sndPlaySound flags2/3, with no volume parameter or
// waveOut/mixer volume call. RCMovie uses SmackOpen with no SmackVolume call.
// The original race sliders do not change either of these playback paths.
export const NATIVE_MENU_GAIN=1;
export const NATIVE_MOVIE_GAIN=1;
