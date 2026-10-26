/*
 * FUN_0044ecb0 at 0044ecb0
 * undefined __register FUN_0044ecb0(int * param_1, int * param_2, int * param_3, undefined4 * param_4, char param_5, char param_6)
 * Address ranges: 0044ecb0-0044ef0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044ecb0(int *param_1,int *param_2,int *param_3,undefined4 *param_4,char param_5,
                 char param_6)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint *in_FS_OFFSET;
  RECT *pRVar9;
  RECT local_50;
  int local_40 [4];
  int local_30 [4];
  int *local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_18 = *param_4;
  local_14 = param_4[1];
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_1;
  if (param_3 == (int *)0x0) {
    FUN_00403b34("DaviDrawGlyph: aGlyph not assigned.");
  }
  cVar1 = (**(code **)(*param_3 + 0x28))();
  if (cVar1 == '\0') {
    FUN_00403b34("DaviDrawGlyph: aGlyph must be transparent.");
  }
  uVar2 = (**(code **)(*param_3 + 0x2c))();
  uVar3 = (**(code **)(*param_3 + 0x20))();
  if (param_5 != '\0') {
    uVar4 = uVar2 & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    if (uVar4 != 0) {
      FUN_00403b34("DaviDrawGlyph: aGlyph does not have a correct size.");
    }
    uVar4 = uVar2 & 1;
    uVar2 = (int)uVar2 >> 1;
    if ((int)uVar2 < 0) {
      uVar2 = uVar2 + (uVar4 != 0);
    }
  }
  FUN_0040ebe8(0,0,uVar2,local_30,uVar3);
  FUN_0040ebe8(uVar2,0,uVar2 * 2,local_40,uVar3);
  local_1c = (int *)0x0;
  local_20 = (int *)0x0;
  uVar4 = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&stack0xffffff98;
  local_1c = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
  (**(code **)(*local_1c + 0x40))(local_1c,uVar2);
  (**(code **)(*local_1c + 0x34))(local_1c,uVar3);
  if (param_6 == '\0') {
    piVar8 = local_30;
    piVar5 = (int *)FUN_0041cd5c(param_3);
    piVar6 = (int *)FUN_0041cd5c(local_1c);
    FUN_004183d0(piVar6,local_30,piVar5,piVar8);
  }
  else {
    if (param_5 == '\0') {
      local_20 = (int *)FUN_0044ea3c(param_3);
    }
    else {
      local_20 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_00);
      (**(code **)(*local_20 + 0x40))(local_20,uVar2 * 2);
      (**(code **)(*local_20 + 0x34))(local_20,uVar3);
      (**(code **)(*local_20 + 8))(local_20,param_3);
      piVar8 = local_40;
      piVar5 = (int *)FUN_0041cd5c(local_20);
      piVar6 = (int *)FUN_0041cd5c(local_20);
      FUN_004183d0(piVar6,local_30,piVar5,piVar8);
      (**(code **)(*local_20 + 0x40))(local_20,uVar2);
    }
    uVar4 = FUN_0041ce40(local_20);
    iVar7 = FUN_0041cd5c(local_1c);
    FUN_00417ea0(*(int **)(iVar7 + 0x14),uVar4);
    FUN_0040ebe8(0,0,uVar2,&local_50.left,uVar3);
    pRVar9 = &local_50;
    piVar8 = (int *)FUN_0041cd5c(local_1c);
    FUN_00418538(piVar8,pRVar9);
    iVar7 = FUN_0041cd5c(local_1c);
    FUN_00417ea0(*(int **)(iVar7 + 0x14),local_14);
    piVar8 = local_30;
    uVar2 = 0xffffff;
    piVar5 = (int *)FUN_0041cd5c(local_1c);
    FUN_00418110(piVar5,local_30,local_20,uVar2,piVar8);
    iVar7 = FUN_0041cd5c(local_1c);
    FUN_00417ea0(*(int **)(iVar7 + 0x14),local_18);
    uVar4 = 0x808080;
    piVar8 = (int *)FUN_0041cd5c(local_1c);
    FUN_00418110(piVar8,local_30,local_20,uVar4,local_30);
  }
  (**(code **)(*local_1c + 0x3c))(local_1c,1);
  FUN_00418458(local_8,local_10,local_c,local_1c);
  *in_FS_OFFSET = uVar4;
  FUN_00402eac(local_1c);
  FUN_00402eac(local_20);
  return;
}

