// The same menu screens on the JS port (read-only server, 4173) and on the recomp (4190), side by side.
//   node tools/checks/menu/serve-js-readonly.mjs &   then   node tools/checks/menu/compare.mjs [OUTDIR]
import { mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..', '..');
const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
const OUT = process.argv[2] || join(ROOT, 'evidence', 'frames', 'menu', 'compare');
mkdirSync(OUT, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const screens = [
  ['main', async (p) => {}],
  ['characters', async (p) => { await p.locator('[data-native=btnQuickRace]').click(); await p.waitForSelector('[data-form=TFRMSELECTCHAR]'); }],
  ['countries', async (p) => { await p.locator('[data-native=btnQuickRace]').click(); await p.waitForSelector('[data-form=TFRMSELECTCHAR]'); await p.locator('[data-native=btnOk]').click(); await p.waitForSelector('[data-form=TFRMSELECTCOUNTRY]'); }],
  ['start-info', async (p) => { await p.locator('[data-native=btnQuickRace]').click(); await p.waitForSelector('[data-form=TFRMSELECTCHAR]'); await p.locator('[data-native=btnOk]').click(); await p.waitForSelector('[data-form=TFRMSELECTCOUNTRY]'); await p.locator('[data-native=btnOk]').click(); await p.waitForSelector('[data-form=TFRMCONTROLSETTINGS]'); }],
  ['adventure', async (p) => { await p.locator('[data-native=btnAdventure]').click(); await p.waitForSelector('[data-form=TFRMADVENTUREMAIN]'); }],
  ['highscores', async (p) => { await p.locator('[data-native=btnHighscore]').click(); await p.waitForSelector('[data-form=TFRMHIGHSCORE]'); }],
  ['settings', async (p) => { await p.locator('[data-native=btnMainOptions]').click(); await p.waitForSelector('[data-form=TFRMOPTIONS]'); }],
  ['geavanceerd', async (p) => { await p.locator('[data-native=btnMainOptions]').click(); await p.waitForSelector('[data-form=TFRMOPTIONS]'); await p.locator('[data-native=btnAdvanced]').click(); await p.waitForSelector('[data-form=TFRMDISPLAYSETTINGS]'); }],
  ['meer-instellingen', async (p) => { await p.locator('[data-native=btnMainOptions]').click(); await p.waitForSelector('[data-form=TFRMOPTIONS]'); await p.locator('[data-native=btnMoreSettings]').click(); await p.waitForSelector('.settings-form'); }],
  ['help', async (p) => { await p.locator('[data-native=btnMainHelp]').click(); await p.waitForSelector('.original-help'); }],
  ['quit', async (p) => { await p.locator('[data-native=btnMainStop]').click(); await p.waitForSelector('[data-form=TFRMREQUESTER]'); }],
];
const sites = { js: 'http://127.0.0.1:4173/', recomp: 'http://127.0.0.1:4190/' };
for (const [viewName, viewport] of [['1024x768', { width: 1024, height: 768 }], ['portrait', { width: 390, height: 844 }]]) {
  for (const [name, go] of screens) {
    if (viewName === 'portrait' && !['main', 'characters', 'settings', 'meer-instellingen'].includes(name)) continue;
    for (const [site, base] of Object.entries(sites)) {
      const context = await browser.newContext({ viewport });
      if (site === 'recomp') await context.route('**/source/race-runner.js', (route) => route.fulfill({ contentType: 'text/javascript', path: fileURLToPath(new URL('./skeleton-race-runner.js', import.meta.url)) }));
      const page = await context.newPage();
      // menu voices off for a quiet run; mouse parked outside the buttons
      await page.goto(base + '?skipIntro');
      await page.waitForSelector('[data-form=TFRMMAIN]');
      await go(page);
      await page.mouse.move(1, 1);
      await page.evaluate(() => document.activeElement?.blur?.());
      await page.waitForTimeout(700);
      await page.screenshot({ path: join(OUT, `${viewName}-${name}-${site}.png`) });
      await context.close();
    }
  }
}
await browser.close();
console.log('done');
