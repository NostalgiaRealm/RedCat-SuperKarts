/*
 * FUN_004c33e9 at 004c33e9
 * undefined FUN_004c33e9(void)
 * Address ranges: 004c33e9-004c340b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004c33e9(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}

