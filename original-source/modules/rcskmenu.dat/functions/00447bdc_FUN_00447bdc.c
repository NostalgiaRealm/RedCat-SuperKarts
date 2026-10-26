/*
 * FUN_00447bdc at 00447bdc
 * undefined __register FUN_00447bdc(int param_1, int param_2, int param_3, char param_4, undefined1 param_5)
 * Address ranges: 00447bdc-00447d61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447bdc(int param_1,int param_2,int param_3,char param_4,undefined1 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar4;
  undefined4 extraout_ECX_03;
  
  iVar2 = FUN_004471e4((int *)&LAB_0043c5c0,'\x01',param_1);
  *(undefined1 *)(iVar2 + 0x10) = param_5;
  if (param_3 == 0) {
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(*(int *)(param_1 + 100) + 0x20);
    *(undefined1 *)(param_1 + 0x48) = param_5;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0x3fe00000;
    if (param_4 == '\0') {
      *(int *)(iVar2 + 8) = param_2;
      iVar3 = *(int *)(param_1 + 100);
      *(int *)(iVar3 + 0x14) = iVar2;
      *(int *)(iVar3 + 0x18) = param_2;
      *(int *)(param_2 + 0xc) = iVar3;
      *(int *)(param_2 + 0x14) = iVar2;
      *(int *)(param_1 + 100) = iVar2;
      FUN_00447930(param_1,*(int *)(iVar2 + 8),extraout_ECX);
      uVar1 = *(uint *)(*(int *)(param_1 + 100) + 0x20);
      iVar3 = (int)uVar1 >> 1;
      if (iVar3 < 0) {
        iVar3 = iVar3 + (uint)((uVar1 & 1) != 0);
      }
      *(int *)(param_1 + 0x4c) = iVar3;
      FUN_00447930(param_1,*(int *)(iVar2 + 8),extraout_ECX_01);
      uVar1 = *(uint *)(*(int *)(param_1 + 100) + 0x20);
      iVar3 = (int)uVar1 >> 1;
      if (iVar3 < 0) {
        iVar3 = iVar3 + (uint)((uVar1 & 1) != 0);
      }
      *(int *)(param_2 + 0x20) = iVar3;
      uVar4 = extraout_ECX_02;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 100);
      iVar3 = *(int *)(param_1 + 100);
      *(int *)(iVar3 + 0x14) = iVar2;
      *(int *)(iVar3 + 0xc) = param_2;
      *(int *)(param_2 + 0x18) = iVar3;
      *(int *)(param_2 + 0x14) = iVar2;
      *(int *)(param_1 + 100) = iVar2;
      FUN_00447930(param_1,*(int *)(iVar2 + 8),extraout_ECX);
      uVar4 = extraout_ECX_00;
    }
    FUN_00447930(param_1,0,uVar4);
  }
  else {
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_3 + 0x20);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_3 + 0x14);
    iVar3 = *(int *)(param_3 + 0x18);
    *(int *)(iVar2 + 0x18) = iVar3;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0xc) = iVar2;
    }
    iVar3 = *(int *)(param_3 + 0xc);
    *(int *)(iVar2 + 0xc) = iVar3;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x18) = iVar2;
    }
    if (param_3 == *(int *)(*(int *)(iVar2 + 0x14) + 8)) {
      *(int *)(*(int *)(iVar2 + 0x14) + 8) = iVar2;
    }
    *(int *)(param_2 + 0x14) = iVar2;
    *(int *)(param_3 + 0x14) = iVar2;
    if (param_4 == '\0') {
      *(int *)(iVar2 + 8) = param_2;
      *(int *)(param_3 + 0x18) = param_2;
      *(undefined4 *)(param_3 + 0xc) = 0;
      *(int *)(param_2 + 0xc) = param_3;
    }
    else {
      *(int *)(iVar2 + 8) = param_3;
      *(undefined4 *)(param_3 + 0x18) = 0;
      *(int *)(param_3 + 0xc) = param_2;
      *(int *)(param_2 + 0x18) = param_3;
    }
  }
  FUN_004473c0(iVar2);
  FUN_00447930(param_1,0,extraout_ECX_03);
  return;
}

