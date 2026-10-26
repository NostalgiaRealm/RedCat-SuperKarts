/*
 * FUN_0042f624 at 0042f624
 * undefined FUN_0042f624(void)
 * Address ranges: 0042f624-0042f66f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f624(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_20 [16];
  
  iVar1 = FUN_0044268c((int)param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      (**(code **)(*param_1 + 0x40))(param_1,auStack_20);
      piVar2 = (int *)FUN_00442650((int)param_1,iVar3);
      FUN_00403088(piVar2,param_1,auStack_20);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  FUN_0042b334(param_1);
  return;
}

