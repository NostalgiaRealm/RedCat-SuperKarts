import { NATIVE_PRECISION } from './native-precision.js';
const f=Math.fround;

/** 498c00 orientation tail, after position/target locks and dampening.
 * Native row-vector basis: right, corrected up, forward. Keep the explicit
 * float stores: the original retains several cross-product terms in x87. */
export function nativeCameraMatrix({position,target,up=[0,1,0]},{precision=NATIVE_PRECISION}={}){
 const r=precision===24?f:Number;
 const mul=(a,b)=>r(a*b),add=(a,b)=>r(a+b),sub=(a,b)=>r(a-b);
 const dx=sub(f(target[0]),f(position[0])),dy=f(sub(f(target[1]),f(position[1]))),
  dz=f(sub(f(target[2]),f(position[2])));
 const length=f(r(Math.sqrt(add(add(mul(dx,dx),mul(dz,dz)),mul(dy,dy)))));
 const fx=f(r(dx/length)),fy=f(r(dy/length)),fz=f(r(dz/length));
 const [ux,uy,uz]=up.map(f);
 const ul=r(Math.sqrt(add(add(mul(ux,ux),mul(uz,uz)),mul(uy,uy))));
 const nx=f(r(ux/ul)),ny=f(r(uy/ul)),nz=r(uz/ul);
 const rx=f(sub(mul(ny,fz),mul(nz,fy)));
 const ry=sub(mul(nz,fx),mul(fz,nx));
 const rz=sub(mul(fy,nx),mul(ny,fx)),storedRz=f(rz);
 const rl=f(r(Math.sqrt(add(add(mul(rz,storedRz),mul(ry,ry)),mul(rx,rx)))));
 const rightX=f(r(rx/rl)),rightY=f(r(ry/rl)),rightZ=r(storedRz/rl),storedRightZ=f(rightZ);
 const cx=sub(mul(rightZ,fy),mul(rightY,fz));
 const cy=f(sub(mul(fz,rightX),mul(storedRightZ,fx)));
 const cz=sub(mul(rightY,fx),mul(fy,rightX)),storedCz=f(cz);
 const cl=f(r(Math.sqrt(add(add(mul(cz,storedCz),mul(cy,cy)),mul(cx,cx)))));
 return [rightX,rightY,storedRightZ,f(r(cx/cl)),f(r(cy/cl)),f(r(storedCz/cl)),fx,fy,fz];
}
