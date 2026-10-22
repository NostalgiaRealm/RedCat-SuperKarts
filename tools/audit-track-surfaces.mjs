import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import { createNativeTrack } from '../src/simulation/native-track.js';

// Inventory only. No rule is inferred from a texture filename or its pixels.
const root = new URL('../', import.meta.url);
const readJson = async file => JSON.parse(await fs.readFile(new URL(file, root)));
const config = await readJson('public/assets/config.json');
const rows = [];
for (let id = 0; id < 6; id++) {
  const file = `public/assets/tracks/etappe${id}.json`;
  const bytes = await fs.readFile(new URL(file, root));
  const track = JSON.parse(bytes), world = createNativeTrack(track);
  const triggerCounts = {};
  const driveTriggerCounts = {};
  for (const node of track.drive)
    driveTriggerCounts[node.unknown[1]] = (driveTriggerCounts[node.unknown[1]] ?? 0) + 1;
  for (const route of track.route) {
    for (const trigger of [route.trigger, route.unknown]) {
      triggerCounts[trigger] = (triggerCounts[trigger] ?? 0) + 1;
    }
  }
  const groups = ['road', 'land', 'extra', 'rail'].map((kind, textureIndex) => ({
    kind, textureIndex, texture: track.textures[textureIndex],
    triangles: track.groups.filter(g => g.kind === kind).reduce((n, g) => n + g.count / 3, 0),
    groundCandidates: kind === 'rail' ? 0 : world.sectors.reduce((n, s) =>
      n + s.triangles[kind].filter(triangle => triangle.normal[1] > Math.fround(.4)).length, 0),
    groundOrder: kind === 'rail' ? null : ['road', 'land', 'extra'].indexOf(kind),
  }));
  rows.push({
    id, name: track.name, source: track.source,
    convertedSha256: crypto.createHash('sha256').update(bytes).digest('hex'),
    sectors: track.sectorCount, groups, cmpBarriers: track.collision.length,
    triggerCounts, driveTriggerCounts,
    surfaceAndWeatherMarkers: Object.fromEntries([7, 67, 68, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88].map(id =>
      [id, { name: config[`etappe${track.id}.ini`].triggers[id], count: triggerCounts[id] ?? 0,
        driveCount: driveTriggerCounts[id] ?? 0 }])),
  });
}
const report = {
  format: 'superkarts-track-surface-audit-v1',
  scope: 'Source and shipped data inventory. Ground candidates are original triangle normal.y > float32(0.4); not every candidate is necessarily selected at runtime. RMP rail triangles are rendered geometry, separate from CMP collision barriers. No friction rule is inferred from pixels.',
  nativeFunctions: {
    rmpGroups: '00494d20', rmpQuad: '0049cc90', trianglePlanes: '00494f40',
    groundSelection: '00495fe0', height: '00496290', wheelGround: '00416650',
    playerForces: '00415990', playerTyres: '00415160', playerResistance: '00415520',
    npcLongitudinal: '00414470', npcLateral: '00414750',
  },
  tracks: rows,
};
const target = new URL('evidence/gameplay/track-surfaces.json', root);
await fs.writeFile(target, JSON.stringify(report, null, 2) + '\n');
for (const row of rows) console.log(`${row.name}: ${row.groups.map(g => `${g.kind} ${g.triangles}/${g.groundCandidates}`).join(', ')}; CMP ${row.cmpBarriers}`);
