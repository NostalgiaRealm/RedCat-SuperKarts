const f32=Math.fround;

/** 0x42cff0. The native values select bilinear/nearest filtering without mipmaps. */
export function nativeGameRenderSettings({hardware=true,filter=2,mirrored=false}={}){
 return {
  textureBlend:hardware?'modulate':'copy',
  filter:filter===2?(hardware?'linear':null):'nearest',
  mipmaps:false,
  shade:hardware?'gouraud':null,
  // Ordinary CCW is the Direct3D default, corroborated by 0x430020's HUD restore.
  cull:mirrored?'clockwise':'counterclockwise',
  visibleChunksDefault:40,
 };
}

/** State-cache writes in 0x42cff0, used to validate the settings against x86. */
export function nativeGameRenderStateCalls({hardware,filter,blendCache,filterCache,shadeCache}){
 const calls=[],blend=hardware?2:7;
 if(blendCache!==blend)calls.push({state:21,value:blend});
 if(filter===2&&!hardware)return calls;
 const nextFilter=filter===2?2:0;
 if(filterCache!==nextFilter)calls.push({state:17,value:filter===2?2:1},{state:18,value:filter===2?2:1});
 if(hardware&&shadeCache!==2)calls.push({state:9,value:2});
 return calls;
}

/** 0x422ed0 consumes one random draw only for enabled fog on hardware. */
export function nativeFogSelection(fog,hardware,random){
 if(!hardware||!fog)return {enabled:false,draws:0};
 if((random.next()&1)===0)return {enabled:false,draws:1};
 return {enabled:true,draws:1,mode:'linear',color:0xb4b4c8,start:3.5,end:1000,
  textureBlend:fog===2?'modulate':'copy'};
}

/** 0x4304d0: camera-facing visibility window, with source float stores/order. */
export function nativeVisibleChunkStart({sector,routeCount,visibleChunks,forward,position,target,backOffset=2,precision=24}){
 const r=precision===24?f32:Number;
 const [x,y,z]=forward.map(f32);
 const length=r(Math.sqrt(r(r(r(z*z)+r(y*y))+r(x*x))));
 const direction=[f32(r(x/length)),f32(r(y/length)),r(z/length)];
 const delta=[r(f32(target[0])-f32(position[0])),f32(r(f32(target[1])-f32(position[1]))),
  f32(r(f32(target[2])-f32(position[2])))];
 const magnitude=f32(r(Math.sqrt(r(r(r(delta[2]*delta[2])+r(delta[1]*delta[1]))+r(delta[0]*delta[0])))));
 const dot=r(r(r(r(delta[2]/magnitude)*direction[2])+r(r(delta[1]/magnitude)*direction[1]))+
  r(r(delta[0]/magnitude)*direction[0]));
 let start;
 if(dot>f32(.5736))start=sector-backOffset;
 else if(dot<f32(-.5736)||Number.isNaN(dot))start=sector-visibleChunks+backOffset;
 else start=sector-Math.trunc(visibleChunks/2);
 if(start<0)start+=routeCount-1;
 return start;
}

/** 0x497ab0. Both returned ranges have inclusive ends, including count+1 chunks. */
export function nativeVisibleChunkRanges(start,count,chunkCount){
 if(!Number.isInteger(chunkCount)||chunkCount<1)throw new RangeError('Chunk count must be positive');
 const firstStart=Math.min(Math.max(start,0),chunkCount-1);
 const end=Math.max(start+count,0),wrapped=end>=chunkCount;
 return {wrapped,ranges:wrapped?[[firstStart,chunkCount-1],[0,end-chunkCount]]:[[firstStart,end]]};
}

/** 0x497b30, called by491530 with pre-update player sector and2*visibleChunks.
 * This update window is independent of the camera-facing render window. */
export function nativeObjectCallbackRanges(playerSector,visibleChunks,routeCount){
 const radius=visibleChunks*2;
 let start=playerSector-radius,end=playerSector+radius;
 if(start<0)return [[start+routeCount-1,routeCount-1],[0,end%routeCount]];
 if(end>routeCount-1)return [[start,routeCount-1],[0,end%routeCount]];
 return [[start,end]];
}

/** 0x42f470. Hardware minimum is25, software15; only active race phase0 adapts. */
export function nativeAdjustVisibleChunks(count,{phase,hardware,delta,precision=24}){
 const r=precision===24?f32:Number;
 return phase===0&&r(1/f32(delta))<10&&count>(hardware?25:15)?count-1:count;
}
