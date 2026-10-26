/*
 * FUN_0041e930 at 0041e930
 * undefined4 * __fastcall FUN_0041e930(undefined4 * param_1)
 * Address ranges: 0041e930-0041e95d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0041e930(undefined4 *param_1)

{
  *(undefined4 *)((int)param_1 + 5) = 0;
  *(undefined4 *)((int)param_1 + 9) = 0;
  *(undefined4 *)((int)param_1 + 0xd) = 0;
  *(undefined4 *)((int)param_1 + 0x15) = 0;
  *(undefined4 *)((int)param_1 + 0x19) = 0;
  *(undefined4 *)((int)param_1 + 0x1d) = 0;
  FUN_0041f0a0((CRect *)((int)param_1 + 0x21));
  *param_1 = &PTR_FUN_00429f10;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}

