const lower=value=>String(value??'').trim().toLowerCase();

/** Original HUD registration is composites, elements, then strings (0045b450).
 * Add appends to each parent's child vector (00458900/00459170); rendering
 * walks that vector recursively in ascending order (00458760). Dynamic stars
 * join their parent afterward, so meshes and strings must not be separate passes.
 */
export function nativeHudDrawOrder(config,{extraElements=[]}={}){
  const overlay=new Map(Object.entries(config['overlay.ini']).map(([id,value])=>[lower(id),value]));
  const registry=name=>{
    const section=overlay.get(name)??{},count=Number(section.count??Infinity);
    return Object.entries(section).filter(([index])=>/^\d+$/.test(index)&&Number(index)<count)
      .sort(([a],[b])=>Number(a)-Number(b)).map(([,id])=>lower(id));
  };
  const composites=new Set(registry('composites'));
  const children=new Map(['screen',...composites].map(id=>[id,[]]));
  const registered=new Set();
  for(const id of [...composites,...registry('elements'),...registry('strings'),...extraElements.map(lower)]){
    if(registered.has(id))continue;
    const section=overlay.get(id);
    if(!section)throw new Error(`Missing original HUD component: ${id}`);
    const parent=lower(section.parent)||'screen';
    if(!children.has(parent))throw new Error(`Missing original HUD parent: ${parent}`);
    children.get(parent).push(id);registered.add(id);
  }
  const order=[],visiting=new Set(),visited=new Set();
  const visit=id=>{
    if(visiting.has(id))throw new Error(`Cyclic original HUD hierarchy: ${id}`);
    if(!composites.has(id)&&id!=='screen'){order.push(id);visited.add(id);return;}
    visiting.add(id);
    for(const child of children.get(id))visit(child);
    visiting.delete(id);visited.add(id);
  };
  visit('screen');
  if([...registered].some(id=>!visited.has(id)))throw new Error('Original HUD hierarchy is disconnected');
  return order;
}
