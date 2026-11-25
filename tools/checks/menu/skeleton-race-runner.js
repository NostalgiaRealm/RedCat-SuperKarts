// SKELETON (2026-11-25), the interface's original stand-in: start() resolves after 300 ms with an unfinished result.
export class RaceRunner {
  constructor({ canvas, touchRoot = null, fpsElement = null, settings = null } = {}) {
    this.canvas = canvas;
    this.active = false;
  }

  applySettings() {}
  suspend() {}
  resume() {}

  async start(config) {
    this.active = true;
    if (config.onProgress) config.onProgress(100);
    if (config.onRunning) config.onRunning();
    await new Promise((r) => setTimeout(r, 300));
    this.active = false;
    return { patch: { PLAYER: { finished: 0 } }, effectsPercent: null, exitCode: 0, error: null };
  }
}
