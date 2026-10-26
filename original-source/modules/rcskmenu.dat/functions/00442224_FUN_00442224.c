/*
 * FUN_00442224 at 00442224
 * undefined __register FUN_00442224(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00442224-004422e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442224(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar7;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  puStack_20 = (undefined1 *)0x44223c;
  piVar1 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
  puStack_24 = &LAB_004422e9;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  iVar2 = FUN_0043f0b0(param_1);
  iVar3 = FUN_0044268c((int)param_1);
  if (-1 < iVar3 + -1) {
    iVar6 = 0;
    do {
      piVar4 = (int *)FUN_00442650((int)param_1,iVar6);
      if (piVar4[1] == param_1[1]) {
        iVar5 = FUN_00442650((int)param_1,iVar6);
        FUN_0040f504(piVar1,iVar5);
        FUN_0043ee6c(piVar4,(iVar2 - piVar4[0xe]) - piVar4[0xc]);
      }
      iVar6 = iVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar2 = piVar1[2];
  if (-1 < iVar2 + -1) {
    iVar3 = 0;
    do {
      uVar7 = 0;
      iVar6 = FUN_0040f6b0(piVar1,iVar3);
      FUN_004405f0(iVar6,0xb03e,0,uVar7);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_004422f0;
  puStack_24 = (undefined1 *)0x4422e8;
  FUN_00402eac(piVar1);
  return;
}

