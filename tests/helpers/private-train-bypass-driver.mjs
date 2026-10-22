import { RouteTestDriver as Base } from './private-projected-line-driver.mjs';

/** Test-only ordinary steering goals: choose a parallel authored lane at a crossing. */
export class RouteTestDriver extends Base {
  configureRacingLine(turnPenalty, { start = 79, end = 93, lane = 3 } = {}) {
    super.configureRacingLine(turnPenalty);
    this.originalRacingLine = [...this.racingLine];
    const changed = [];
    for (let sector = start; sector <= end; sector++) {
      const route = this.track.route[sector];
      const nodes = [...new Set([...route.driveIndices, ...route.driveLeftIndices])];
      const offset = Math.min(lane, sector - start + 1, end - sector + 1);
      const node = nodes[Math.min(nodes.length - 1, offset)];
      this.racingLine[sector] = node;
      changed.push({ sector, node });
    }
    const disconnected = [];
    for (let sector = 0; sector < this.racingLine.length; sector++) {
      const from = this.racingLine[sector], to = this.racingLine[(sector + 1) % this.racingLine.length];
      if (!this.links[from].includes(to)) disconnected.push({ sector, from, to });
    }
    if (disconnected.length) throw new Error(`Requested lane bypass is not connected by original road links: ${JSON.stringify(disconnected)}`);
    this.racingLineNext = new Map(this.racingLine.map((node, i) =>
      [node, this.racingLine[(i + 1) % this.racingLine.length]]));
    this.laneBypass = { start, end, lane, changed };
  }
}
