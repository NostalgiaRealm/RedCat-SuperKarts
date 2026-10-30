import {integrateNativeEuler, quantizeNativePlanarVelocity} from './native-integrator.js';
import {nativeRotationMatrix, multiplyNativeMatrices, nativePlacementAngles} from './native-transform.js';
import {selectNativeSector} from './native-track.js';
import {getNativeScenerySounds, nativeObjectCallbackCount} from '../spatial-audio.js';
import {getSceneryAnimation, createNativeMeshAnimation, advanceNativeMeshAnimation} from '../asset-animation.js';
import {NATIVE_PRECISION} from './native-precision.js';

const f = Math.fround;
const solidTypes = new Set([5, 6, 8, 14, 15, 17, 19, 23, 24, 25, 45]);
const zeroForce = Object.freeze({lateralForce: 0, verticalForce: 0, longitudinalForce: 0, torque: 0});

/** 43e140 registration branches; textures and image alpha are not consulted. */
export function nativeSceneryIsSolid(type) { return solidTypes.has(type); }

/** 48fda0 and its scenery callers. INERTIA in 43d130 overrides the inverse
 * inertia directly; despite its INI name it is not inverted a second time. */
export function nativeSceneryPhysics(type, section = {}, {precision = NATIVE_PRECISION} = {}) {
  if (!nativeSceneryIsSolid(type)) return null;
  const r = precision === 24 ? f : Number;
  const configured = type === 6 || type === 45;
  const mass = f(configured ? Number(section.massa ?? 400)
    : type === 8 ? 13000 : type === 25 ? 400 : type === 23 || type === 24 ? 300 : 0);
  const restitution = f(configured || [5, 14, 15, 17, 19].includes(type) ? .1 : .2);
  const inverseMass = mass >= .1 ? f(r(1 / mass)) : 0;
  const inertia = r(r(mass * f(.083333336)) * 17);
  const inverseInertia = configured ? f(Number(section.inertia ?? 0))
    : mass >= .1 ? f(r(1 / inertia)) : 0;
  return {mass, inverseMass, inverseInertia, restitution,
    lateralSpeed: 0, verticalSpeed: 0, forwardSpeed: configured ? f(Number(section.snelheid ?? 0)) : 0,
    yawRate: 0, pitchRate: 0, rollRate: 0, heightOffset: configured ? f(Number(section.hoogte ?? 0)) : 0};
}

/** 499630: four mesh-bound corners, current frame, and signed away-from-zero yaw. */
export function nativeSceneryRectangle(body) {
  return {...body.bounds, position: body.position,
    angle: body.yaw > 0 ? Math.ceil(body.yaw) : Math.floor(body.yaw), body};
}

/** 494b90's continuous slope rotation (not the 4096-entry render-angle table). */
export function nativeScenerySlopeMatrix(forward, {precision = NATIVE_PRECISION} = {}) {
  const r = precision === 24 ? f : Number, [x, y, z] = forward;
  const length = r(Math.sqrt(r(r(z * z) + r(x * x))));
  const azimuth = f(Math.atan2(f(r(x / length)), r(z / length)));
  const slope = f(Math.atan2(y, r(Math.sqrt(r(r(x * x) + r(z * z))))));
  const rotY = angle => {
    const c = f(Math.cos(angle)), s = f(Math.sin(angle));
    return [c, 0, s, 0, 1, 0, -s, 0, c];
  };
  const c = f(Math.cos(slope)), s = f(Math.sin(slope));
  const rotX = [1, 0, 0, 0, c, -s, 0, s, c];
  // 4a2560 writes second * first in row-vector storage.
  return multiplyNativeMatrices(rotY(azimuth),
    multiplyNativeMatrices(rotX, rotY(-azimuth), precision), precision);
}

/** Registered scenery in OMP order. The supplied six tracks only use types5/6;
 * other original solid types need their object-specific controllers first. */
export class NativeSceneryBodies {
  constructor({track, config, manifest, world, collision, precision = NATIVE_PRECISION}) {
    Object.assign(this, {track, config, manifest, world, collision, precision});
    this.byPlacement = new Map();
    this.pathRevisions = new Map();
    this.animations = new Map();
    const always = new Set(getNativeScenerySounds(config, manifest, track).map(x => x.placementIndex));
    this.bodies = track.placements.flatMap((placement, placementIndex) => {
      if (!nativeSceneryIsSolid(placement.type)) return [];
      if (![5, 6].includes(placement.type)) {
        throw new RangeError(`Unimplemented scenery controller for native solid type ${placement.type}`);
      }
      const definition = track.objectDefinitions[placement.animation.toLowerCase()];
      const mesh = definition?.mesh.toLowerCase();
      if (!manifest.meshes[mesh]?.bounds) throw new Error(`Missing native collision bounds: ${mesh}`);
      const physics = nativeSceneryPhysics(placement.type,
        config['rotobj.ini']?.[placement.animation.toLowerCase()], {precision});
      const angles = nativePlacementAngles(placement.nativeRotationDegrees);
      const body = {...physics, placementIndex, type: placement.type, mesh,
        bounds: {...manifest.meshes[mesh].bounds}, position: placement.position.map(f),
        yaw: angles[1], pitch: angles[0], roll: angles[2], sector: placement.sector,
        previousSector: 0, active: true, alwaysUpdate: always.has(placementIndex), flags: 0,
        matrix: nativeRotationMatrix(angles, {precision}),
        get visible() { return this.active; },
        get x() { return this.position[0]; }, set x(v) { this.position[0] = v; },
        get y() { return this.position[1]; }, set y(v) { this.position[1] = v; },
        get z() { return this.position[2]; }, set z(v) { this.position[2] = v; }};
      this.byPlacement.set(placementIndex, body);
      if (placement.type === 6) {
        const animation = getSceneryAnimation(config, manifest, track.id, placement.animation);
        if (!animation || animation.sequences.length !== 1) {
          throw new Error(`Native solid scenery requires a verified single sequence: ${placement.animation}`);
        }
        this.animations.set(placementIndex, createNativeMeshAnimation(animation.sequences[0]));
      }
      return [body];
    });
    this.rests = this.bodies.map(() => null);
  }

  /** Call after pre-player mesh animation, before any body's collision sweep. */
  setMesh(placementIndex, mesh) {
    const body = this.byPlacement.get(placementIndex);
    if (!body) return;
    const key = mesh.toLowerCase().replace(/^.*[/\\]/, '').replace(/\.json$/, '.d3d');
    const bounds = this.manifest.meshes[key]?.bounds;
    if (!bounds) throw new Error(`Missing current-frame native collision bounds: ${mesh}`);
    body.mesh = key; body.bounds = {...bounds};
  }

  /** 43d010 advances and applies the type6 mesh before any body's integration.
   * This keeps collision bounds current even in a simulation without a renderer. */
  prepare(nowMs, ranges, placementIndex=null) {
    const entries=placementIndex===null?this.animations
      :this.animations.has(placementIndex)?[[placementIndex,this.animations.get(placementIndex)]]:[];
    for (const [index, state] of entries) {
      const body = this.byPlacement.get(index);
      const count = nativeObjectCallbackCount({visible: body.active, alwaysUpdate: body.alwaysUpdate,
        sector: body.sector, ranges});
      for (let step = 0; step < count; step++) {
        const mesh = advanceNativeMeshAnimation(state, nowMs);
        if (mesh) this.setMesh(index, mesh.source);
      }
    }
  }

  /** Call immediately after NativeSceneryPaths.step. A held active path still
   * writes sector, but does not overwrite displacement retained from an impact.
   * Activation can set +44 without a path tick when all ten slots are full. */
  syncPaths(paths) {
    for (const [index, state] of paths.objects) {
      const body = this.byPlacement.get(index);
      if (!body) continue;
      const previous = this.pathRevisions.get(index) ?? {pose: 0, update: 0, visible: true};
      if (previous.pose !== state.poseRevision) {
        body.position.splice(0, 3, ...state.position);
        body.yaw = state.yaw;
        body.matrix = nativeRotationMatrix([body.pitch, body.yaw, body.roll], {precision: this.precision});
      }
      if (previous.update !== state.updateRevision) body.sector = state.sector;
      if (previous.visible !== state.visible) body.active = state.visible;
      this.pathRevisions.set(index, {pose: state.poseRevision, update: state.updateRevision, visible: state.visible});
    }
  }

  /** 491d30, flags0: one Euler step per matching callback range, no second
   * sliding sweep and no wheel-ground callback. Run before player integration. */
  integrate(deltaSeconds, ranges) {
    const bodies = this.bodies, rests = this.rests;
    for (let index = 0; index < bodies.length; index++) {
      const body = bodies[index];
      if (!body.active) continue;
      const rest = rests[index];
      const count = nativeObjectCallbackCount({visible: body.active, alwaysUpdate: body.alwaysUpdate,
        sector: body.sector, ranges});
      // A motionless body's previous pass is a fixed point: its sweep returns
      // the resting result, zero force adds +0 to the four speeds, the sector
      // search returned its own hint and the matrix depends only on the pose.
      if (rest && body.lateralSpeed === 0 && body.forwardSpeed === 0 && body.yawRate === 0
        && body.matrix === rest.matrix && body.sector === rest.sector && body.pitch === rest.pitch
        && body.yaw === rest.yaw && body.roll === rest.roll
        && body.position[0] === rest.x && body.position[2] === rest.z) {
        if (count > 0) {
          body.lateralSpeed += 0; body.forwardSpeed += 0; body.verticalSpeed += 0; body.yawRate += 0;
          this.collision.finishStep?.(body, null); body.previousSector = body.sector;
        }
        continue;
      }
      quantizeNativePlanarVelocity(body, this.precision);
      rests[index] = null;
      for (let step = 0; step < count; step++) {
        const contact = this.collision.sweep(body, deltaSeconds);
        integrateNativeEuler(body, zeroForce, deltaSeconds, contact, this.precision);
        body.matrix = nativeRotationMatrix([body.pitch, body.yaw, body.roll], {precision: this.precision});
        if (contact.contact) this.collision.resolve(body, contact.contact);
        this.collision.finishStep?.(body, contact.contact);
        body.previousSector = body.sector;
        body.sector = selectNativeSector(this.world, body.sector, body.x, body.z);
        // 4936a0: ground-frame matrix pre-multiplied by the object's pose;
        // translation and the last column remain untouched.
        body.matrix = multiplyNativeMatrices(body.matrix,
          nativeScenerySlopeMatrix(this.world.sectors[body.sector].forward, {precision: this.precision}),
          this.precision);
        if (!contact.contact && contact.fraction === 0 && body.lateralSpeed === 0 && body.forwardSpeed === 0 && body.yawRate === 0
          && body.previousSector === body.sector) {
          rests[index] = {matrix: body.matrix, sector: body.sector, pitch: body.pitch, yaw: body.yaw, roll: body.roll,
            x: body.position[0], z: body.position[2]};
        }
      }
    }
    return this.bodies;
  }
}
