import * as THREE from 'three';

/** Transpose native row-vector 3x3 storage into Three's column-vector matrix. */
export function nativeMatrix(matrix,position=[0,0,0]){
  const m=matrix,p=position;
  return new THREE.Matrix4().set(m[0],m[3],m[6],p[0],m[1],m[4],m[7],p[1],m[2],m[5],m[8],p[2],0,0,0,1);
}
export function setNativeMatrix(object,matrix){
  object.matrixAutoUpdate=false;
  object.matrix.copy(nativeMatrix(matrix,object.position.toArray()));
  object.matrixWorldNeedsUpdate=true;
}

const cameraTarget=new THREE.Vector3();
/** 42d7d0 mirrors the world projection and cull direction;430020 restores
 * ordinary projection for the HUD. Reflecting both the world and camera pose
 * is equivalent here, and lets Three select the correct winding from each
 * mesh's world determinant. Only the world group is reflected: the camera is
 * its sibling in the scene. Camera-relative flag/weather meshes need their
 * own local reflection because their parent cancels the view matrix.
 * HUD layers have independent, untouched scenes.
 * Simulation, camera interpolation inputs and sound coordinates stay native.
 */
export function presentNativeRaceCamera(world,camera,previous,current,alpha,mirrored){
  const reflection=mirrored?-1:1;
  world.scale.x=reflection;
  for(const mesh of camera.children)mesh.scale.x=reflection;
  camera.position.lerpVectors(previous.position,current.position,alpha);
  cameraTarget.lerpVectors(previous.target,current.target,alpha);
  camera.up.copy(current.up);
  camera.position.x*=reflection;
  cameraTarget.x*=reflection;
  camera.up.x*=reflection;
  camera.lookAt(cameraTarget);
}
