/*
 * FUN_0041e8b0 at 0041e8b0
 * undefined __thiscall FUN_0041e8b0(void * this, undefined4 * param_1)
 * Address ranges: 0041e8b0-0041e8ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0041e8b0(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  *(undefined4 *)((int)this + 8) = param_1[2];
  *(undefined4 *)((int)this + 0xc) = param_1[3];
  return;
}

