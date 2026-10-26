/*
 * FUN_0048ad70 at 0048ad70
 * undefined FUN_0048ad70(void)
 * Address ranges: 0048ad70-0048ad95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048ad70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return (*(int *)(*(int *)(param_1 + 4) + 8) - iVar1) / 0x120;
}

