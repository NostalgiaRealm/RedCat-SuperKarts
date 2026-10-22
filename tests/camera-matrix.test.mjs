import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeCameraMatrix} from '../src/simulation/native-camera-matrix.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/camera-matrix-fixtures.json',import.meta.url)));
test('camera basis matches 480 original orientation updates including body-up and x87 stores',()=>{
 for(const [index,row]of fixture.rows.entries()){
  assert.deepEqual(nativeCameraMatrix(row.input,{precision:row.precision}).map(v=>v===0?0:v),
   row.matrix.map(v=>v===0?0:v),`${index}:precision${row.precision}`);
 }
});
