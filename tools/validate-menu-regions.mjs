import {chromium} from 'playwright';
import {writeFile} from 'node:fs/promises';

const browser = await chromium.launch({executablePath: process.env.CHROME || '/usr/bin/google-chrome', headless: true});
try {
  const page = await browser.newPage({viewport: {width: 800, height: 600}});
  await page.goto(process.env.PORT_URL || 'http://127.0.0.1:4173');
  await page.setContent('<!doctype html><html><body style="margin:0"></body></html>');
  const results = await page.evaluate(async () => {
    const {applyNativeMenuRegion} = await import('/src/menu-regions.js');
    const {regions} = await (await fetch('/assets/ui/regions.json')).json();
    const results = [];
    for (const [name, region] of Object.entries(regions)) {
      const im = new Image(); im.src = `/assets/menu/${name.replace(/\.bmp$/, '.png')}`;
      await im.decode();
      const canvas = document.createElement('canvas');
      canvas.width = im.width; canvas.height = im.height;
      const context = canvas.getContext('2d');
      context.drawImage(im, 0, 0);
      const rgba = context.getImageData(0, 0, im.width, im.height).data;
      const button = document.createElement('button');
      button.style.cssText = `position:absolute;left:10px;top:10px;width:${im.width * 2}px;height:${im.height * 2}px;margin:0;border:0;padding:0;background:red`;
      document.body.append(button);
      applyNativeMenuRegion(button, region);
      let checked = 0;
      for (let y = 0; y < im.height; y++) for (let x = 0; x < im.width; x++) {
        const p = (y * im.width + x) * 4;
        const expected = !!(rgba[p] || rgba[p + 1] || rgba[p + 2]);
        const hit = document.elementFromPoint(10 + x * 2 + 1, 10 + y * 2 + 1) === button;
        if (hit !== expected) throw new Error(`${name}: hitmask mismatch at ${x},${y}`);
        checked++;
      }
      results.push({name, checkedPixels: checked, solidPixels: region.solidPixels});
      button.remove();
    }
    return results;
  });
  const report = {status: 'passed', browser: browser.version(), scale: 2, regions: results,
    checkedPixels: results.reduce((sum, item) => sum + item.checkedPixels, 0)};
  await writeFile('docs/evidence/menu-region-validation.json', JSON.stringify(report, null, 2) + '\n');
  console.log(`${results.length} original bitmap masks matched browser pointer coverage at ${report.checkedPixels} pixel centers`);
} finally {
  await browser.close();
}
