const f=Math.fround;

/** Original 43f740/440290/43bc70/43fab0 activation callbacks. The frame and
 * rotating angle are sampled AFTER that object's animation/rotation update.
 * Types44/46/47 read the preceding player callback's cached XZ, whereas43
 * reads its render object directly. Return actual target bodies, including
 * the executable's duplicate player and type44 self-target behavior. */
export function nativeSquashTargets(object,{player,opponents,playerPosition=player.position,
  frame=0,hitAngle=100,precision=24}){
  const r=precision===24?f:Number,type=object.type;
  if(![43,44,46,47].includes(type))return[];
  if(type===43){
    const phase=Math.trunc(f(object.angles?.[2]??object.roll??0)%1024);
    if(!(phase<=hitAngle||phase>=r(1024-f(hitAngle))))return[];
  }
  if(type===46&&frame>=17&&frame<=48)return[];
  if(type===47&&frame>=3&&frame<=38)return[];
  const range=type===43?70:type===44?32:type===46?95:44;
  const near=position=>Math.abs(Math.trunc(r(f(position[0])-f(object.position[0]))))
    +Math.abs(Math.trunc(r(f(position[2])-f(object.position[2]))))<range;
  const result=[];
  if(near(type===43?player.position:playerPosition))result.push(type===44?object:player);
  // The animated callbacks start at roster slot1 and include slot=count,
  // which 417e90 resolves to the player. The rotating callback starts at0.
  const first=type===46||type===47?1:0,last=type===46||type===47?opponents.length+1:opponents.length;
  for(let index=first;index<last;index++){
    const body=opponents[index]??player;
    if(near(body.position))result.push(type===44?object:body);
  }
  return result;
}
