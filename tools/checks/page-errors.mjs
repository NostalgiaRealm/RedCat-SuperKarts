// What fails a browser check besides its own checks: tools/run-checks.mjs reads only exit codes, and a page that
// threw or crashed can still let every check of it pass (a later race, a picture taken before the error).
// watchPage(page, onError) hands onError one line for each of these on that page:
//   - an uncaught exception or unhandled rejection (Playwright 'pageerror');
//   - the page's renderer gone (Playwright 'crash');
//   - a console.error: the source writes one only from a catch or for a failure (source/race-runner.js:232, :746,
//     :751 the game worker's 'crash' message; source/main.js:86, :399, :468, :474, :491, :808, :824, :831), except a
//     resource the server does not have (the development page has no icon link, so Chromium asks for /favicon.ico,
//     which tools/serve.mjs answers with 404; the menu page names its icon, source/index.html:11);
//   - the render worker failing: its 'fatal' message (race-runner.js:772, console.warn 'render worker: ...') or its
//     uncaught error (race-runner.js:200, an event 'log' that source/dev/race.js:52 prints as '[game] render worker: ...').
// With { console: false } only the first two: for the JS reconstruction's pages, whose console is not this project's.
const MISSING = /^Failed to load resource: the server responded with a status of 404/;
const RENDER = /^(\[game\] )?render( worker)?: /;

export function watchPage(page, onError, { console: withConsole = true } = {}) {
  page.on('pageerror', (e) => onError('pageerror ' + e.message));
  page.on('crash', () => onError('page crashed'));
  if (withConsole) page.on('console', (m) => {
    const text = m.text();
    if ((m.type() === 'error' && !MISSING.test(text)) || RENDER.test(text)) onError(`console ${m.type()} ${text}`);
  });
}
