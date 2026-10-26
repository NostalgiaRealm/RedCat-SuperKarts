/*
 * FUN_00439290 at 00439290
 * undefined FUN_00439290(void)
 * Address ranges: 00439290-004392b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00439290(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return (*(int *)(*(int *)(param_1 + 4) + 8) - iVar1) / 0x14;
}

