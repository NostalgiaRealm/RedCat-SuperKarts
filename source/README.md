# Editable game source — not the running game

The files in this folder are the individual JavaScript modules, HTML template
and stylesheet used to **edit and maintain the port**. They are build inputs:
**the game does NOT load or execute these individual files directly.**

Normal browser and Electron launches execute the generated JavaScript in
[`../src/`](../src/), through the generated [`../index.html`](../index.html).
Three.js is included in those bundles. Separate chunks let the game load the
menu first and the race renderer when needed. The `.map` files contain debugging
information, not additional executable modules.

## Making changes

1. Edit files here, rather than the generated files in `src/`.
2. Run `npm run bundle` from the project root to refresh `src/`, `index.html`
   and `runtime-manifest.json`.
3. Reload the game. If starting it with `npm start`, `npm run dev` or
   `npm run desktop`, the runtime is refreshed automatically before launch.

There is no live watcher: edits made after the server starts need another
`npm run bundle` and a browser reload, or a restart. Refreshing the runtime does
not copy assets, create desktop packages or change saved games. `npm run build`
creates the separate static website in `dist/` with its assets.

Tests can import these modules directly. Browser diagnostics can explicitly
enable `--inspect-source` to inspect individual modules; ordinary launches
block requests to `/source/`. The game's entry point still uses the generated
bundles in that diagnostic mode. See the [test guide](../tests/README.md).

This folder contains the maintained JavaScript port. The distinct
[`original-source/`](../original-source/README.md) folder contains recovered
native-code reference material, not the port's editable implementation.

See [development instructions](../docs/development.md) and
[runtime layout](../docs/runtime-layout.md) for the complete workflow.
