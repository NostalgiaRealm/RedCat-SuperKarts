// As in Spookkasteel: try immediate playback, retry muted when sound is
// blocked, and use the player's gesture to enable audio without rewinding.
export class MoviePlayback {
  constructor(video,audioButton,{onError=()=>{}}={}){
    this.video=video;this.audioButton=audioButton;this.onError=onError;
    this.serial=0;this.active=false;
    audioButton.onclick=event=>{event.stopPropagation();this.activate();};
  }
  start(source,volume){
    const serial=++this.serial;this.active=true;this.audioButton.hidden=true;
    this.video.muted=false;this.video.volume=volume;this.video.src=source;
    return this.play(serial,true);
  }
  async play(serial,retryMuted){
    const current=()=>this.active&&serial===this.serial;
    try{
      await this.video.play();
      if(current())this.audioButton.hidden=!this.video.muted;
    }catch(error){
      // A completed/skipped/replaced movie must not revive old controls or
      // mute a newer movie when its outstanding play promise settles.
      if(!current())return;
      if(error.name==='NotAllowedError'&&retryMuted&&!this.video.muted){
        this.video.muted=true;return this.play(serial,false);
      }
      if(error.name==='NotAllowedError'||error.name==='AbortError')this.audioButton.hidden=false;
      else this.onError(error);
    }
  }
  activate(){
    if(!this.active)return;
    const serial=++this.serial;this.audioButton.hidden=true;
    // Start audio before fullscreen consumes the trusted click/key gesture.
    this.video.muted=false;const playing=this.play(serial,false);
    const document=this.video.ownerDocument;
    if(document?.fullscreenEnabled&&!document.fullscreenElement){
      try{document.documentElement.requestFullscreen().catch(()=>{});}catch{}
    }
    // Unsupported or denied fullscreen must not interrupt the movie/audio.
    return playing;
  }
  stop(){
    this.active=false;++this.serial;this.audioButton.hidden=true;
    this.video.pause();this.video.removeAttribute('src');this.video.load();
    this.video.muted=false;
  }
}
