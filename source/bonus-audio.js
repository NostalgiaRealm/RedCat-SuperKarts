const pickupNames=['GOT_BONUS','GOT_ROCKET','GOT_SOAP','GOT_OIL','GOT_GUM','GOT_TURBO','GOT_EURO'];
const firingNames=['','FIRE_ROCKET','FIRE_SOAP','FIRE_OIL','FIRE_GUM','FIRE_TURBO'];
/**4540c0/4542c0 use the static pickup type, including random type7's
 * GOT_BONUS name absent from the original EFFECTS bank. Never substitute. */
export function nativePickupSoundRequest(staticType,{player=true}={}){
 return player?{voiceId:10,sample:pickupNames[staticType]??'GOT_BONUS',replace:false}:null;
}
/**455490 and451640 enqueue effects only when the shooter is the player. */
export function nativeFiringSoundRequest(type,level,{player=true}={}){
 if(!player||!firingNames[type])return null;
 if(!Number.isInteger(level)||level<1||level>3)throw new RangeError('Native bonus sound level must be1..3');
 return{voiceId:10,sample:firingNames[type]+level,replace:false};
}
