/*
 * FUN_0041f030 at 0041f030
 * int * __thiscall FUN_0041f030(void * this, byte param_1)
 * Address ranges: 0041f030-0041f04d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __thiscall FUN_0041f030(void *this,byte param_1)

{
  thunk_FUN_0041e980(this);
  if ((param_1 & 1) != 0) {
    FUN_0042035e(this);
  }
  return this;
}

