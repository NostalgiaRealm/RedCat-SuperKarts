/*
 * FUN_0048ace0 at 0048ace0
 * undefined FUN_0048ace0(void)
 * Address ranges: 0048ace0-0048acf5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048ace0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return *(int *)(*(int *)(param_1 + 4) + 8) - iVar1 >> 5;
}

