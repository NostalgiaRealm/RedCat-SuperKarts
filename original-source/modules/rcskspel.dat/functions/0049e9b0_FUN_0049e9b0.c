/*
 * FUN_0049e9b0 at 0049e9b0
 * undefined FUN_0049e9b0(void)
 * Address ranges: 0049e9b0-0049e9e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049e9b0(int param_1,uint param_2)

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
        FUN_0049d7a0();
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

