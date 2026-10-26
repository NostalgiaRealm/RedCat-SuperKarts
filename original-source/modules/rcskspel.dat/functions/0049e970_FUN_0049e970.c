/*
 * FUN_0049e970 at 0049e970
 * undefined FUN_0049e970(void)
 * Address ranges: 0049e970-0049e9a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049e970(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_0049dd20(iVar3);
      if ((*(uint *)(iVar2 + 8) & param_2) != 0) {
        FUN_0049d4d0(param_3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

