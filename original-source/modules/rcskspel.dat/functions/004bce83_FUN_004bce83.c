/*
 * FUN_004bce83 at 004bce83
 * undefined FUN_004bce83(void)
 * Address ranges: 004bce83-004bcea9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004bce83(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_004bf2c5(*(int *)(param_1 + 0x50));
    if (iVar1 == 0) {
      FUN_004bceaa(0,2);
      return param_1;
    }
  }
  return 0;
}

