const controls=new Set(['TDaviGraphicButton','TDaviGraphicRadioButton','TDaviGraphicCheckBox',
  'TDaviGraphicSlider','TDaviEdit2','TEdit','TButton','TCheckBox','TDaviRadioButton','TComboBox']);
const containers=new Set(['TTransparentControl','TPanel','TGroupBox','TDaviPageControl','TTabSheet']);
/** 4417fb initializes omitted TabOrder=-1;44246c appends each child.
 * 441980 then moves explicitly indexed children in ascending target order.
 * Containers without a published TabOrder retain their insertion position.
 */
export function nativeOrderedChildren(item){
  const list=item.children.filter(child=>controls.has(child.class)||containers.has(child.class));
  const targets=new Array(list.length);
  for(const child of list){const index=child.properties.TabOrder??-1;if(index>=0&&index<list.length)targets[index]=child;}
  for(const[index,child]of targets.entries())if(child){list.splice(list.indexOf(child),1);list.splice(index,0,child);}
  return list;
}
export function nativeFormTabOrder(form){
  const entries=[];
  function visit(item){
    for(const child of nativeOrderedChildren(item)){
      if(controls.has(child.class))entries.push({name:child.name,stop:child.properties.TabStop!==false});
      visit(child);
    }
  }
  visit(form);
  return new Map(entries.map((entry,index)=>[entry.name,entry.stop?index+1:-1]));
}

export function nativeNavigationOrder(elements){
  return elements.map((element,index)=>({element,index,order:Number(element.dataset.nativeTabOrder)||Infinity}))
    .sort((a,b)=>a.order-b.order||a.index-b.index).map(({element})=>element);
}
