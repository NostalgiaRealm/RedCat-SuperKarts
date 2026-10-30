/** Accelerated430020/4918f0 submission phases. The opaque object pass walks
 * engine creation order; each shadow callback immediately precedes its kart.
 * Nonzero blend modes are deferred by48f600, retaining that traversal order. */
export const NATIVE_RENDER_ORDER=Object.freeze({
  road:0,sky:1,objects:1000,skidmarks:10000,jets:11000,ribbons:12000,
  arms:13000,rescue:14000,smoke:15000,finishFlag:16000,weather:17000,explosions:18000,
});

/** The road index in its full-track draw order; the track data stays untouched.
 * Consecutive groups with one texture then form one draw with the same triangle order. */
export function nativeRoadIndex(track){
  const index=new(track.position.length/3>65535?Uint32Array:Uint16Array)(track.index.length),starts=new Map();
  let at=0;
  for(const group of nativeRoadDrawGroups(track)){
    starts.set(group,at);
    for(let i=0;i<group.count;i++)index[at++]=track.index[group.start+i];
  }
  return {index,starts};
}
export function mergeRoadDrawGroups(groups,starts){
  const merged=[];let last=null;
  for(const group of groups){
    const start=starts.get(group);
    if(last&&last.textureIndex===group.textureIndex&&last.start+last.count===start)last.count+=group.count;
    else merged.push(last={start,count:group.count,textureIndex:group.textureIndex});
  }
  return merged;
}

export function nativeObjectRenderOrder(index,{shadow=false,part=0}={}){
  return NATIVE_RENDER_ORDER.objects+index*2+(shadow?0:1+part/8);
}

/** 4971f0 invokes497270 once per wrapped visible interval. Each interval
 * batches ROAD, LAND, EXTRA, RAIL, preserving the triangles' sector order. */
export function nativeRoadDrawGroups(track,ranges=[[0,track.sectorCount-1]]){
  const groups=[];
  for(const [first,last]of ranges)for(const kind of ['road','land','extra','rail'])
    for(const group of track.groups)
      if(group.count&&group.kind===kind&&group.sector>=first&&group.sector<=last)groups.push(group);
  return groups;
}
