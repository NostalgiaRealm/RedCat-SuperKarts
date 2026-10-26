/*
 * FUN_0041efc0 at 0041efc0
 * int * __thiscall FUN_0041efc0(void * this, int param_1)
 * Address ranges: 0041efc0-0041efce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __thiscall FUN_0041efc0(void *this,int param_1)

{
  *(int *)this = param_1;
  *(int *)((int)this + 4) = param_1 >> 0x1f;
  return this;
}

