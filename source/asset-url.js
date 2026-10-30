/** Absolute address of a game file below the page's own folder, so the site
 * also works from a URL folder such as /redcatsuperkarts/. Use it for url()
 * values placed in CSS custom properties: browsers resolve a relative url()
 * there against the style sheet that reads it (src/style.css), not the page. */
export const assetURL=path=>globalThis.document?.baseURI?new URL(path,document.baseURI).href:path;
