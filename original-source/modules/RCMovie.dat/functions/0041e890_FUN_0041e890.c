/*
 * FUN_0041e890 at 0041e890
 * undefined __thiscall FUN_0041e890(void * this, undefined4 * param_1)
 * Address ranges: 0041e890-0041e8ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0041e890(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 8) = param_1[2];
  *(undefined4 *)((int)this + 4) = param_1[1];
  *(undefined4 *)((int)this + 0xc) = param_1[3];
  return;
}

