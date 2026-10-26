/*
 * FUN_0041af21 at 0041af21
 * undefined __cdecl FUN_0041af21(int param_1)
 * Address ranges: 0041af21-0041b203
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041af21(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  iVar3 = piVar2[1] / 2;
  iVar4 = piVar2[2] / 2;
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_radiobutton__no_v_004366c4);
  }
  FUN_00404a0d();
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 4) {
    FUN_00411de7(iVar1,2);
    iVar5 = FUN_00412687(*piVar2,4);
    uVar7 = 1;
    iVar6 = FUN_00412a49(iVar1);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar1);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
  }
  else if (iVar5 == 0x10) {
    FUN_00411de7(iVar1,1);
    if (piVar2[8] == 4) {
      iVar5 = FUN_00412687(*piVar2,3);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
    else {
      iVar5 = FUN_00412687(*piVar2,1);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
  }
  else if (iVar5 == 0x11) {
    FUN_00411de7(iVar1,4);
    piVar2[8] = 4;
    iVar5 = FUN_00412687(*piVar2,3);
    uVar7 = 1;
    iVar6 = FUN_00412a49(iVar1);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar1);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    FUN_0041ad41(iVar1);
  }
  else {
    FUN_00411de7(iVar1,0);
    if (piVar2[8] == 4) {
      iVar5 = FUN_00412687(*piVar2,2);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
    else {
      iVar5 = FUN_00412687(*piVar2,0);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
  }
  if (piVar2[4] != 0) {
    FUN_0041258a(iVar1,piVar2[5],piVar2[6],piVar2[6],piVar2[7]);
  }
  FUN_00404a81();
  return;
}

