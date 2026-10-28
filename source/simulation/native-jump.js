import {nativeProjectileFacing} from './native-projectile.js';

const f32=Math.fround;

/**
 * 42bbf0 uses GetPrivateProfileIntA then converts unsigned integers to float
 * (FILD qword, FSTP float at 0x42bef6..0x42bf04 etc.): no x87 arithmetic.
 */
export function nativeJumpSettings(config) {
  const source=config['track.ini'].zipper_boost;
  const integer=key=>f32((Number.parseInt(source[key],10)||0)>>>0);
  return Object.fromEntries([[61,'high'],[62,'medium'],[63,'low']].map(([marker,name])=>[
    marker,{forward:integer(`${name}forward`),up:integer(`${name}up`)},
  ]));
}

/**
 * Registered player callbacks 441c50 (49) and441d50 (52), called by4938e0
 * before the movement-active gate. NPC406470 has no corresponding cases.
 * The source checks the current DMP node and direction, then reads the
 * CURRENT sector's secondary PMP marker, which may differ from the crossed
 * boundary when moving backwards. It adds velocity to each child wheel.
 * Precision-independent: each wheel is one FADD stored at once (0x441d27/
 * 0x441d2f) and the speed one FMUL stored at once (0x441d3c/0x441d43); the
 * 0x415be0 facing test takes routeOptions.precision.
 */
export function applyNativePlayerJump(marker,{track,body,wheels,settings,routeOptions}) {
  if(marker!==49&&marker!==52)return false;
  if(track.drive[body.waypoint]?.unknown[1]!==marker)return false;
  const forward=nativeProjectileFacing(track,body,routeOptions);
  if((marker===49&&!forward)||(marker===52&&forward))return false;
  const secondary=track.route[body.sector].unknown,boost=settings[secondary];
  if(!boost)throw new RangeError(`Native jump has undefined stack values for secondary marker${secondary}`);
  if(wheels.length!==4)throw new RangeError('The original jump requires four wheel children');
  for(const wheel of wheels)wheel.verticalSpeed=f32(f32(wheel.verticalSpeed)+boost.up);
  body.forwardSpeed=f32(f32(body.forwardSpeed)*boost.forward);
  return true;
}
