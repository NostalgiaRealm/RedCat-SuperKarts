/** Accelerated430020/4918f0 submission phases. The opaque object pass walks
 * engine creation order; each shadow callback immediately precedes its kart.
 * Nonzero blend modes are deferred by48f600, retaining that traversal order. */
export const NATIVE_RENDER_ORDER=Object.freeze({
  road:0,sky:1,objects:1000,skidmarks:10000,jets:11000,ribbons:12000,
  arms:13000,rescue:14000,smoke:15000,finishFlag:16000,weather:17000,explosions:18000,
});

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
