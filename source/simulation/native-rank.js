const f32=Math.fround;

/**
 * 0x406be0 pairwise ranking. Actors are in CHARDATA order (NPCs then player).
 * Rank is zero based; progress uses signed integer sectors, not world distance.
 * Ties retain prior rank. Finished contestants compare their native finish time.
 *
 * Precision-independent: NPC progress is FILD then FSTP float (0x406c74/0x406c7f,
 * 0x406d74/0x406d78), player progress is FILD in ST0 (0x406c9e), and each
 * FSUB/FSUBR difference is compared from ST0 against 1.0 (0x406ca8..0x406cac,
 * 0x406d20, 0x406dc3, 0x406e03). Every operand is an integer sector count, so
 * the float conversions and differences are exact at PC=24 and PC=53 alike.
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
