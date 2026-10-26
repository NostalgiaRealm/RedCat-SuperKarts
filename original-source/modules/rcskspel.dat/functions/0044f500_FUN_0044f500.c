/*
 * FUN_0044f500 at 0044f500
 * undefined FUN_0044f500(void)
 * Address ranges: 0044f500-0044f52f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0044f500(int param_1)

{
  if (*(int *)(param_1 + 0x60) == 0) {
    return 0;
  }
  return **(undefined4 **)(param_1 + 0x40);
}

