/*
 * FUN_004422f8 at 004422f8
 * undefined __register FUN_004422f8(int * param_1)
 * Address ranges: 004422f8-004423de;00442430-00442436
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004422f8(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar5;
  undefined4 extraout_ECX_03;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar6;
  undefined4 extraout_EDX_02;
  undefined3 uVar7;
  int iVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  puStack_20 = (undefined1 *)0x44230f;
  iVar1 = FUN_0044268c((int)param_1);
  if (iVar1 != 0) {
    puStack_20 = (undefined1 *)0x442323;
    piVar2 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX);
    puStack_20 = (undefined1 *)0x44232e;
    FUN_004421f4((int)param_1);
    puStack_24 = &LAB_004423df;
    uStack_28 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_28;
    puStack_20 = &stack0xfffffffc;
    iVar1 = FUN_0044268c((int)param_1);
    uVar5 = extraout_ECX_00;
    uVar6 = extraout_EDX;
    if (-1 < iVar1 + -1) {
      iVar8 = 0;
      do {
        iVar3 = FUN_00442650((int)param_1,iVar8);
        uVar5 = extraout_ECX_01;
        uVar6 = extraout_EDX_00;
        if ((byte)(*(char *)(iVar3 + 0x4b) - 3U) < 2) {
          iVar3 = FUN_00442650((int)param_1,iVar8);
          FUN_0040f504(piVar2,iVar3);
          uVar5 = extraout_ECX_02;
          uVar6 = extraout_EDX_01;
        }
        iVar8 = iVar8 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    FUN_00403088(param_1,uVar6,uVar5);
    *in_FS_OFFSET = uStack_28;
    puStack_20 = &DAT_004423e6;
    while (0 < piVar2[2]) {
      puStack_24 = (undefined1 *)0x44239f;
      piVar4 = (int *)FUN_0040f6b0(piVar2,piVar2[2] + -1);
      uVar7 = (undefined3)((uint)extraout_EDX_02 >> 8);
      if (*(char *)((int)piVar4 + 0x4b) == '\x03') {
        puStack_24 = (undefined1 *)0x4423ac;
        FUN_0043ec64(piVar4,CONCAT31(uVar7,4),extraout_ECX_03);
      }
      else {
        puStack_24 = (undefined1 *)0x4423b5;
        FUN_0043ec64(piVar4,CONCAT31(uVar7,3),extraout_ECX_03);
      }
      puStack_24 = (undefined1 *)0x4423c4;
      FUN_0040f550(piVar2,piVar2[2] + -1);
    }
    puStack_24 = (undefined1 *)0x4423d6;
    FUN_00402eac(piVar2);
    puStack_24 = (undefined1 *)0x4423de;
    FUN_004421fc((int)param_1);
    return;
  }
  return;
}

