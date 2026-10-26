/*
 * FUN_00450080 at 00450080
 * undefined FUN_00450080(void)
 * Address ranges: 00450080-004500a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00450080(int param_1)

{
  FUN_00450440();
  return DAT_006a5c38 + *(int *)(param_1 + 8) * 0xa9 + 0x95;
}

