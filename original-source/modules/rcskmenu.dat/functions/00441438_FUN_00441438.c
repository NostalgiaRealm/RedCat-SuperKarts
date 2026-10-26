/*
 * FUN_00441438 at 00441438
 * undefined FUN_00441438(void)
 * Address ranges: 00441438-004414e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00441438(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  double dStack_3c;
  double dStack_34;
  double dStack_2c;
  double dStack_24;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  iVar1 = *param_2;
  iStack_18 = param_2[1];
  uVar2 = 0;
  if (iVar1 < 1) {
    uVar2 = 3;
  }
  else if (iVar1 < *(int *)(param_1 + 0x38)) {
    if (iStack_18 < 1) {
      uVar2 = 1;
    }
    else if (iStack_18 < *(int *)(param_1 + 0x3c)) {
      iStack_14 = *(int *)(param_1 + 0x3c) - iStack_18;
      iStack_1c = *(int *)(param_1 + 0x38) - iVar1;
      dStack_3c = (double)iVar1;
      dStack_34 = (double)iStack_1c;
      dStack_2c = (double)iStack_18;
      dStack_24 = (double)iStack_14;
      iVar1 = FUN_004413fc(&dStack_3c,3);
      if (iVar1 == 0) {
        uVar2 = 3;
      }
      else if (iVar1 == 1) {
        uVar2 = 4;
      }
      else if (iVar1 == 2) {
        uVar2 = 1;
      }
      else if (iVar1 == 3) {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

