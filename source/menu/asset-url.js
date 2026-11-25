// Copied unchanged from the JavaScript reconstruction: ../RedCat Superkarts/source/asset-url.js at commit 5bfe0b62 (1.0.3).
// Change it there first and copy it again; the recomp's menu keeps the JS port's code as it is.
/** Absolute address of a game file below the page's own folder, so the site
 * also works from a URL folder such as /redcatsuperkarts/. Use it for url()
 * values placed in CSS custom properties: browsers resolve a relative url()
 * there against the style sheet that reads it (src/style.css), not the page. */
export const assetURL=path=>globalThis.document?.baseURI?new URL(path,document.baseURI).href:path;
