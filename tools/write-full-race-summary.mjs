import fs from 'node:fs';
import {fileURLToPath} from 'node:url';

const root=fileURLToPath(new URL('../',import.meta.url));
const matrix=JSON.parse(fs.readFileSync(`${root}evidence/full-race-matrix/race-matrix.json`));
const countries=['Nederland','Germany','England','France','Spain','Italy'];
const difficulties=['Easy','Medium','Hard'];
const time=ms=>{
  const minutes=Math.floor(ms/60000),seconds=Math.floor(ms%60000/1000),fraction=ms%1000;
  return `${minutes}:${String(seconds).padStart(2,'0')}.${String(fraction).padStart(3,'0')}`;
};
const place=rank=>['1st','2nd','3rd','4th','5th'][rank]??String(rank+1);
const cells=new Map(matrix.races.map(run=>[run.key,run]));
const rows=[];
for(let track=0;track<6;track++)for(let difficulty=0;difficulty<3;difficulty++){
  const values=[countries[track],difficulties[difficulty]];
  for(let mode=0;mode<4;mode++){
    const run=cells.get([track,difficulty,mode].join(','));
    values.push(run
      ?`[${time(run.lapTimes.reduce((sum,value)=>sum+value,0))} · ${place(run.rank)}${run.qualified?' ✓':''}](../${run.file})`
      :'**Unfinished check**');
  }
  rows.push(`| ${values.join(' | ')} |`);
}
const unitLog=fs.readFileSync(`${root}evidence/full-race-matrix/final-unit-tests.log`,'utf8');
const unitCount=Number(unitLog.match(/ℹ pass (\d+)/)?.[1]);
const franceReport='evidence/full-race-matrix/timed-france-whole-race-projected-seam.json';
const france=matrix.missing.includes('3,2,1')
  ?JSON.parse(fs.readFileSync(`${root}${franceReport}`)).runs[0]:null;
const text=`# Full-race results

${matrix.counts.completed} of 72 combinations have a verified five-lap finish.
${matrix.counts.qualified} of those runs also meet the original qualification
requirement. A completed race can be lost; opponents and qualification rules
remain unchanged. ${matrix.missing.length
  ?`The remaining check is ${matrix.missing.map(key=>{const[t,d,m]=key.split(',').map(Number);return `${countries[t]}, ${difficulties[d].toLowerCase()} difficulty, ${['normal','timed','star','duel'][m]} mode`;}).join('; ')}.`
  :'Every requested track, difficulty and race mode is represented.'}
${france?`
The [focused France run](../${franceReport}) completed ${france.race.lapCount} laps
and ${france.gateEvents.length} checkpoints, then expired at ${time(france.activeElapsedMs)}
in ${place(france.rank)} place. The kart was still moving, with no rescue or reverse
recovery. This remains a five-lap verification gap; an automated driving
failure does not establish that the original deadline is impossible.
`:''}

Times below are active race times. Each linked report records the full race,
the original playable character and startup seeds used, controls, lap events,
opponent count, original asset hashes and source hashes. ✓ means the original
qualification condition was met. Every accepted star race collected all 12
distinct stars; every accepted timed race finished before its original deadline.

| Track | Difficulty | Normal | Timed | Stars | Duel |
| --- | --- | --- | --- | --- | --- |
${rows.join('\n')}

## What changed

The comparison with original instructions restored mirrored presentation and
steering for England, France and Italy, and the original constructor reset of
player upgrade switches before physics, opponent and timer initialization.

Two new safeguards address reproduced failures that can stop a race:
returning opponents wait if their original return position overlaps the
player, and an opponent velocity component is reset only if original
preparation changes it from finite to nonfinite. Original finite physics,
opponent behavior, track geometry and checkpoint time awards are retained.
The existing player-return safeguard remains: after two seconds blocked,
it can select a safe original waypoint up to twelve sectors behind, and
checks overlap again as the kart returns to full size.

## Validation and scope

The current runtime passes ${unitCount} tests and 11 focused browser checks.
Original files were compared across all six tracks and all three difficulty
tables, alongside bounded execution of original game instructions.

The races use ordinary controls at the browser's 25 ms simulation interval.
Test-driver forecasts work on private copies and never write live race state.
Most matrix runs begin from the active starting grid; selected timed cases
also include the authored opening camera and countdown. These results cover
five-lap driving in the composed port, not complete startup coverage for every
case, an uninterrupted Adventure campaign, or every character and random seed.
WineD3D cannot render original races
reliably on this host, so no original Windows whole-race visual comparison is
claimed.

The [machine-checked matrix](../evidence/full-race-matrix/race-matrix.json)
is authoritative. [Research notes](research-full-race-matrix.md) explain the
original evidence, necessary exceptions, controller corrections and retained
failed attempts.
`;
fs.writeFileSync(`${root}docs/full-race-results.md`,text);
console.log(JSON.stringify({completed:matrix.counts.completed,qualified:matrix.counts.qualified,file:'docs/full-race-results.md'}));
