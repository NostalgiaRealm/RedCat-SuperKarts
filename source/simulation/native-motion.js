import { createNativeInputState, updateNativeInput, updateNativeAnalogInput } from './native-input.js';
import { calculateNativePlayerForces } from './native-player.js';
import { integrateNativeEuler, nativeIntegrationSchedule, quantizeNativePlanarVelocity } from './native-integrator.js';
import { applyNativeRailContact } from './native-collision.js';
import { createNativeGroundState, NativeGroundClock, nativeYawTrig, updateNativeGround, updateNativeWheelPose } from './native-ground.js';
import { nativeSectorAt, nativeTrackHeight } from './native-track.js';
import { nativeRotationMatrix, nativeRotationMatrix53 } from './native-transform.js';
import { resetNativeInactivePlayer } from './native-game-timers.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;
const registerRounding = precision => {
  if (precision !== 24 && precision !== 53) throw new RangeError('Native x87 precision must be 24 or 53');
  return precision === 24 ? f32 : Number;
};

/**
 * 0x48fda0, called by 0x415f90 (0x416161) with mass, restitution .2, length and
 * width from 0x4e02a0 + car*300; the nine standard records are identical.
 * 1/mass is one FDIV stored at 0x48fdf4. L*L, W*W, their sum, mass*(1/12),
 * the product and the FDIVR reciprocal all stay in ST0 until FSTP float +0x94
 * (0x48fdfa..0x48fe1e); the inertia itself is never stored.
 */
export function nativeStandardKartInertia(carIndex = 0, { precision = NATIVE_PRECISION } = {}) {
  if (!Number.isInteger(carIndex) || carIndex < 0 || carIndex > 8) {
    throw new RangeError('Only native standard car records 0..8 have verified mass and inertia');
  }
  const r = registerRounding(precision);
  const mass = f32(600);
  const length = f32(4.5), width = f32(1.7);
  const inverseInertia = f32(r(1 / r(r(r(length * length) + r(width * width)) * r(mass * f32(0.083333336)))));
  const inverseMass = f32(1 / mass);
  return { mass: 1 / inverseMass, inverseMass, inverseInertia, restitution: f32(0.2) };
}

function yawMatrix(yaw, precision) {
  const { sin, cos } = nativeYawTrig(yaw, precision);
  return [cos, 0, sin, 0, 1, 0, -sin, 0, cos];
}

/**
 * Connected active player movement, using the original update order.
 * Collision detection must be supplied explicitly; it is never guessed here.
 * Race progression, opponents, items and menus are separate systems.
 */
export class NativePlayerMotion {
  constructor({ physics, geometry, world, start, collision, groundClock = new NativeGroundClock(),
    carIndex = 0, upgrades = {}, mirrored = false, precision = NATIVE_PRECISION }) {
    if (!collision || typeof collision.sample !== 'function') {
      throw new TypeError('An explicit native collision adapter is required');
    }
    registerRounding(precision);
    this.precision = precision;
    this.physics = physics;
    this.world = world;
    this.collision = collision;
    this.groundClock = groundClock;
    this.upgrades = upgrades;
    this.mirrored = mirrored;
    this.controls = { ...createNativeInputState(), throttle: 20, steering: 30 };
    this.body = {
      ...nativeStandardKartInertia(carIndex, { precision }),
      position: start.position.map(f32), yaw: f32(start.yaw),
      matrix: yawMatrix(start.yaw, precision), sector: start.sector, previousSector: start.sector,
      lateralSpeed: 0, verticalSpeed: 0, forwardSpeed: 0, yawRate: 0,
      pitchRate: 0, rollRate: 0, pitch: 0, roll: 0,
      get x() { return this.position[0]; }, set x(value) { this.position[0] = value; },
      get y() { return this.position[1]; }, set y(value) { this.position[1] = value; },
      get z() { return this.position[2]; }, set z(value) { this.position[2] = value; },
    };
    this.ground = {
      wheels: geometry.wheelOffsets.map((local, i) => ({
        local: local.map(f32), radius: i < 2 ? geometry.frontRadius : geometry.rearRadius,
        verticalSpeed: 0, spin: 0, steeringAngle: 0,
      })),
    };
    this.groundInitialized = false;
    this.rpm = 800;
    this.gear = 0;
    this.slipMagnitude = 0;
    this.lowSpeedTurn = false;
    this.updates = 0;
  }

  // 0x496290 returns the height in ST0. Each consumer (0x41c0b0 wheel pose,
  // 0x416650 ground callback) rounds where the original stores.
  sampleGround = (x, y, z) => nativeTrackHeight(this.world, this.body.sector, x, z, this.precision);

  /** 0x491530 updates every object's callback before 0x491d30 integrates any. */
  prepare(buttons, deltaSeconds, { active = true, phase = 0, analog = null, onBonus, matrix } = {}) {
    if (!Number.isFinite(deltaSeconds) || deltaSeconds <= 0) throw new RangeError('Motion requires a positive finite update interval');
    if (this.prepared) throw new Error('Integrate the prepared native frame before preparing another');
    const body = this.body, precision = this.precision, options = { precision };
    // `matrix` is the body render matrix as 0x4325b0 finds it: 0x41c48d
    // rebuilds only the wheels, so a rescue scale applied at 0x42f618 on the
    // previous tick still holds until integration (0x491d30) rebuilds it.
    const pose = { precision, matrix: matrix ?? body.matrix };
    // 0x4325b0 first calls 0x41b790, which itself updates the four wheels.
    // The active-race branch calls the wheel updater again after input/forces.
    updateNativeWheelPose(body, this.ground, deltaSeconds, this.controls.steering, this.sampleGround, pose);
    if (!active) {
      // The countdown branch retains input state, updates wheels once and
      // clears speeds. Engine integration and its ground callback still run.
      resetNativeInactivePlayer(this);
      const force = { lateralForce: 0, verticalForce: 0, longitudinalForce: 0, torque: 0 };
      this.prepared = { force, deltaSeconds };
      return force;
    }
    // 432acc -> 41b790 advances wheels before the input routine fires a bonus.
    // A turbo therefore changes the second wheel pass, never this first one.
    if (analog) updateNativeAnalogInput(this.controls, analog, this.mirrored, onBonus);
    else updateNativeInput(this.controls, buttons, deltaSeconds, this.mirrored, onBonus, options);
    const force = calculateNativePlayerForces(body, this.physics, this.controls, deltaSeconds, {
      ...this.upgrades, rpm: this.rpm, gear: this.gear,
      // 0x415520 reads +0x14/+0x34 of the same matrix (0x41566b/0x415646).
      matrix14: pose.matrix[1], matrix34: pose.matrix[7],
      phase, slipMagnitude: this.slipMagnitude, precision,
    });
    this.rpm = force.rpm;
    this.gear = force.gear;
    this.slipMagnitude = force.slipMagnitude;
    this.lowSpeedTurn = this.slipMagnitude !== 0;
    updateNativeWheelPose(body, this.ground, deltaSeconds, this.controls.steering, this.sampleGround, pose);
    this.prepared = { force, deltaSeconds };
    return force;
  }

  integrate(snapshot = true) {
    if (!this.prepared) throw new Error('Prepare the native frame before integrating');
    const { force, deltaSeconds } = this.prepared;
    const body = this.body, precision = this.precision;
    quantizeNativePlanarVelocity(body, precision);
    this.occupancy?.remove(body);
    const schedule = nativeIntegrationSchedule(deltaSeconds, { player: true, flags: 3 });
    for (let step = 0; step < schedule.count; step++) {
      const collision = this.collision.sample(body, schedule.dt);
      integrateNativeEuler(body, force, schedule.dt, collision, precision);
      // Native rebuilds render-object matrix 0x4a09e0 before contact response.
      body.matrix = precision === 24 ? nativeRotationMatrix([body.pitch, body.yaw, body.roll], { precision })
        : nativeRotationMatrix53(body.pitch, body.yaw, body.roll);
      if (collision?.contact) {
        if(this.collision.resolve)this.collision.resolve(body,collision.contact);
        else applyNativeRailContact(body, collision.contact, { precision });
      }
      this.collision.finishStep?.(body, collision?.contact);
    }
    // 0x4932e0 stores current into previous before selecting the new sector.
    // Rescue relocation also calls it, so this is not interchangeable with
    // the last sector observed by the race/HUD callback.
    body.previousSector = body.sector;
    body.sector = nativeSectorAt(this.world, body.sector, body.x, body.z, precision);
    // 0x491d30 selects the waypoint (0x4937e0) before the +0x58 ground
    // callback 0x416650, as the NPC path does.
    this.occupancy?.insert(body);
    if (!this.groundInitialized) {
      const initial = createNativeGroundState(body, this.ground.wheels, { precision });
      initial.wheels.forEach((wheel, i) => { this.ground.wheels[i].position = wheel.position; });
      this.groundInitialized = true;
    }
    updateNativeGround(body, this.ground, deltaSeconds, this.sampleGround, { clock: this.groundClock, precision });
    this.prepared = null;
    this.updates++;
    return snapshot ? this.snapshot() : undefined;
  }

  step(buttons, deltaSeconds) {
    this.prepare(buttons, deltaSeconds);
    return this.integrate();
  }

  snapshot() {
    return {
      position: [...this.body.position], yaw: this.body.yaw, matrix: [...this.body.matrix],
      lateralSpeed: this.body.lateralSpeed, verticalSpeed: this.body.verticalSpeed,
      forwardSpeed: this.body.forwardSpeed, yawRate: this.body.yawRate,
      rpm: this.rpm, gear: this.gear, controls: { ...this.controls },
      sector: this.body.sector, groundCount: this.ground.groundCount ?? 0,
      wheels: this.ground.wheels.map(wheel => ({
        local: [...wheel.local], spin: wheel.spin, steeringAngle: wheel.steeringAngle,
        verticalSpeed: wheel.verticalSpeed, position: wheel.position && [...wheel.position],
      })),
      updates: this.updates,
    };
  }
}
