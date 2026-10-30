/** 0x431610/0x48f010: DirectShow volume uses hundredths of a decibel. */
export function originalMusicGain(percent){
  if(!Number.isFinite(percent))throw new RangeError('Music percentage must be finite');
  percent=Math.max(0,Math.min(100,percent));
  return percent===0?0:10**((Math.trunc(percent*4900/100)-5000)/2000);
}

export class TrackMusic{
  constructor(file,percent=100){
    this.audio=new Audio('assets/'+file);
    // 0x48ec20(1), 0x48ef80: reset/restart on a game-thread completion poll.
    // An autonomous HTML loop would incorrectly restart during P/quit pause.
    this.audio.loop=false;this.setVolume(percent);this.blocked=false;
  }
  setVolume(percent){this.audio.volume=originalMusicGain(percent);if(!percent)this.audio.pause();}
  async resume(){if(!this.audio.volume)return;try{await this.audio.play();this.blocked=false;}catch{this.blocked=true;}}
  pollCompletion(){if(this.audio.ended&&this.audio.volume){this.audio.currentTime=0;return this.resume();}}
  pause(){this.audio.pause();}
  stop(){this.audio.pause();this.audio.currentTime=0;}
}
