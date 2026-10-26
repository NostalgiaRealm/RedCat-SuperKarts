/** Shared CRT stream from 0x4be6bf/0x4be6c9. 4b14e0 seeds time() before
 * construction; 42f930 reseeds GetTickCount before startup/race actions. */
export class NativeRandom {
  constructor(seed = 1) { this.seed(seed); }
  seed(value) { this.state = value >>> 0; return this; }
  next() {
    this.state = (Math.imul(this.state, 214013) + 2531011) >>> 0;
    return (this.state >>> 16) & 32767;
  }
}
