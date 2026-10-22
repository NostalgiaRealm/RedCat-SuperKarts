/** Data layouts verified by 0x4319f0 and labeled by the native tweak menus. */
function readRecords(bytes, stride, count) {
  const view = bytes instanceof DataView ? bytes : new DataView(bytes.buffer ?? bytes, bytes.byteOffset ?? 0, bytes.byteLength);
  if (view.byteLength !== stride * count) throw new RangeError(`Expected ${stride * count} bytes`);
  return Array.from({ length: count }, (_, record) => Array.from({ length: stride / 4 }, (_, field) => {
    const value = view.getFloat32(record * stride + field * 4, true);
    if (!Number.isFinite(value)) throw new RangeError(`Nonfinite field in record ${record}, field ${field}`);
    return value;
  }));
}

export function parsePhysicsTable(bytes) {
  return readRecords(bytes, 0xac, 20).map((raw, index) => ({
    index, raw,
    weight: raw[0], frontWeightShare: raw[1], rearWeightShare: raw[2], wheelRadius: raw[3],
    frontAxleDistance: raw[4], rearAxleDistance: raw[5], airSurface: raw[6],
    maxSteerAngle: raw[7], maxBrakeForce: raw[8],
    engineA: raw.slice(9, 11), engineB: raw.slice(11, 13), engineC: raw.slice(13, 15),
    transmission: [raw.slice(15, 21), raw.slice(21, 27)], maxRpm: raw.slice(27, 29),
    rearTireA: raw.slice(29, 31), rearTireB: raw.slice(31, 33), rearTireC: raw.slice(33, 35),
    frontTireA: raw.slice(35, 37), frontTireB: raw.slice(37, 39), frontTireC: raw.slice(39, 41),
    tireFriction: raw.slice(41, 43),
  }));
}

function racerRecords(records) {
  return records.map((raw, index) => ({
    index, raw,
    acceleration: raw.slice(6, 12),
    maxSpeed: raw.slice(18, 24),
    gearUpFraction: raw[24], gearDownFraction: raw[25],
    brakePower: raw[27], frictionPower: raw[28], steerSpeed: raw[30],
    // Fields 0..5, 12..17, 26 and 29 intentionally retain only raw names.
  }));
}

export function parseRacerTable(bytes) {
  return racerRecords(readRecords(bytes, 0x7c, 20));
}

/** 0x4319f0 calls0x4350d0 only for race type3, after loading cars[difficulty]. */
export function applyNativeRaceTypeTable(table, { raceType, difficulty }) {
  if (![0, 1, 2].includes(difficulty)) throw new RangeError('Native difficulty must be0,1 or2');
  if (table.length !== 20 || table.some(record => record.raw.length !== 31)) {
    throw new TypeError('Original20-record racer table required');
  }
  const rows = table.map(record => [...record.raw]);
  if (raceType === 3) {
    const steer = Math.fround([1.6, 1.7, 2.5][difficulty]);
    const speed = Math.fround([1.15, 1.2, 1.5][difficulty]);
    // The original end pointer covers only records0..9, not all20.
    for (const raw of rows.slice(0, 10)) {
      raw[30] = Math.fround(raw[30] * steer);
      for (let gear = 0; gear < 6; gear++) {
        raw[18 + gear] = Math.fround(raw[18 + gear] * speed);
        raw[6 + gear] = Math.fround(raw[6 + gear] * speed);
      }
    }
  }
  return racerRecords(rows);
}
