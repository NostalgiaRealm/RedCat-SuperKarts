/*
 * FUN_0041e960 at 0041e960
 * int * __thiscall FUN_0041e960(void * this, byte param_1)
 * Address ranges: 0041e960-0041e97d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __thiscall FUN_0041e960(void *this,byte param_1)

{
  FUN_0041e980(this);
  if ((param_1 & 1) != 0) {
    FUN_0042035e(this);
  }
  return this;
}

