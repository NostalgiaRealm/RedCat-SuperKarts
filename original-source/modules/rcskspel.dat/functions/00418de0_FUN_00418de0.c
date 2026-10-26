/*
 * FUN_00418de0 at 00418de0
 * undefined FUN_00418de0(void)
 * Address ranges: 00418de0-00418df5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00418de0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return *(int *)(*(int *)(param_1 + 4) + 8) - iVar1 >> 4;
}

