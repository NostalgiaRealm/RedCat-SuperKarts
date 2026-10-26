/*
 * FUN_00415110 at 00415110
 * undefined FUN_00415110(void)
 * Address ranges: 00415110-00415160
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415110(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 != param_1[0xc]) {
    iVar2 = *(int *)(param_1[0x10] + 8);
    if (-1 < iVar2 + -1) {
      iVar3 = 0;
      do {
        piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
        (**(code **)(*piVar1 + 0x10))();
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    param_1[0xc] = param_4;
    param_1[0xd] = param_5;
    (**(code **)(*param_1 + 0x30))();
  }
  return;
}

