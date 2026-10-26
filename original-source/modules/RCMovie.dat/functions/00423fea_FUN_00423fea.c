/*
 * FUN_00423fea at 00423fea
 * int __cdecl FUN_00423fea(int param_1, int * param_2)
 * Address ranges: 00423fea-0042400c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00423fea(int param_1,int *param_2)

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

