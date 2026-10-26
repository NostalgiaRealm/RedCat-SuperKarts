/*
 * FUN_00489400 at 00489400
 * undefined FUN_00489400(void)
 * Address ranges: 00489400-004894b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00489400(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined1 local_d;
  
  *param_1 = &PTR_FUN_004d2fc4;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_d;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  param_1[1] = puVar1;
  param_1[0x3c] = 0;
  param_1[0x3a] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  param_1[0x3d] = 0;
  param_1[0x3f] = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  param_1[0x3e] = 0;
  *(undefined1 *)((int)param_1 + 0x101) = 0;
  *(undefined1 *)((int)param_1 + 0x102) = 1;
  param_1[0x41] = 0x41a00000;
  *(undefined1 *)(param_1 + 0x42) = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 200;
  *(undefined1 *)(param_1 + 0x47) = 0;
  return param_1;
}

