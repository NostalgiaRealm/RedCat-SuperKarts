const f32=Math.fround;

/**
 * 0x406be0 pairwise ranking. Actors are in CHARDATA order (NPCs then player).
 * Rank is zero based; progress uses signed integer sectors, not world distance.
 * Ties retain prior rank. Finished contestants compare their native finish time.
 */
export function updateNativeRankings(actors) {
  const count=actors.length-1,player=actors[count],ranks=Array(actors.length).fill(0),events=[];
  const passed=(behind,ahead)=>events.push({type:'overtake',behind,ahead});
  for(let i=0;i<count;i++){
    const a=actors[i];
    if(!a.finished){
      if(!player.finished){
        if(a.rank<player.rank){
          if(f32(player.distance)-f32(a.distance)>=1){passed(i,count);ranks[i]++;}
          else ranks[count]++;
        }else{
          if(f32(a.distance)-f32(player.distance)<1)ranks[i]++;
          else{passed(count,i);ranks[count]++;}
        }
      }else ranks[i]++;
      for(let j=i+1;j<count;j++){
        const b=actors[j];
        if(b.finished){ranks[i]++;continue;}
        if(a.rank<b.rank){
          if(f32(b.distance)-f32(a.distance)>=1){passed(i,j);ranks[i]++;}
          else ranks[j]++;
        }else{
          if(f32(a.distance)-f32(b.distance)<1)ranks[i]++;
          else{passed(j,i);ranks[j]++;}
        }
      }
    }else{
      if(!player.finished||a.finishTimeMs<=player.finishTimeMs)ranks[count]++;
      else ranks[i]++;
      for(let j=i+1;j<count;j++){
        const b=actors[j];
        if(!b.finished||a.finishTimeMs<=b.finishTimeMs)ranks[j]++;
        else ranks[i]++;
      }
    }
  }
  actors.forEach((actor,i)=>{actor.rank=ranks[i];});
  return events;
}
