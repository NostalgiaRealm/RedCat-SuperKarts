/*
 * FUN_00445cb8 at 00445cb8
 * undefined __register FUN_00445cb8(int param_1, int param_2, undefined4 param_3, undefined * param_4, undefined4 param_5)
 * Address ranges: 00445cb8-00445cfd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445cb8(int param_1,int param_2,undefined4 param_3,undefined *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0044268c(param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      iVar2 = FUN_00442650(param_1,iVar3);
      if (*(int *)(iVar2 + 4) == param_2) {
        (*(code *)param_4)(param_5,iVar2);
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

