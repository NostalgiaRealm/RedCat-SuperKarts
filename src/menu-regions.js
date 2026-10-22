const SVG = 'http://www.w3.org/2000/svg';
const caches = new WeakMap();

// Native 00453170 builds the union of nonblack runs; 0045e1c8 applies that region
// to the child window. SVG clipping constrains both painting and pointer hits.
// Supply the original control width/height, which may differ from bitmap size.
export function applyNativeMenuRegion(element, region, width = region?.width, height = region?.height) {
  if (!region || !width || !height) return;
  const document = element.ownerDocument;
  let cache = caches.get(document);
  if (!cache) {
    const svg = document.createElementNS(SVG, 'svg');
    svg.setAttribute('width', '0'); svg.setAttribute('height', '0');
    svg.style.cssText = 'position:absolute;pointer-events:none;overflow:hidden';
    svg.setAttribute('aria-hidden', 'true');
    const defs = document.createElementNS(SVG, 'defs');
    svg.append(defs); document.body.append(svg);
    cache = {defs, clips: new Map()}; caches.set(document, cache);
  }
  const cacheKey = `${region.sha256}:${width}:${height}`;
  let id = cache.clips.get(cacheKey);
  if (!id) {
    id = `native-menu-region-${cache.clips.size}`;
    const clip = document.createElementNS(SVG, 'clipPath');
    clip.id = id; clip.setAttribute('clipPathUnits', 'objectBoundingBox');
    const path = document.createElementNS(SVG, 'path');
    path.setAttribute('d', region.rectangles.map(([x, y, w, h]) =>
      `M${x / width} ${y / height}h${w / width}v${h / height}h${-w / width}Z`).join(''));
    clip.append(path); cache.defs.append(clip); cache.clips.set(cacheKey, id);
  }
  element.style.clipPath = `url("#${id}")`;
}
