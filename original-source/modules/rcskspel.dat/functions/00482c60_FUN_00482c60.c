/*
 * FUN_00482c60 at 00482c60
 * undefined FUN_00482c60(void)
 * Address ranges: 00482c60-00483013
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00482c60(undefined4 *param_1,float *param_2,undefined4 param_3,undefined4 *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  float fVar11;
  undefined4 *unaff_retaddr;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d13b6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)*param_4)(param_1);
  if (param_4 != (undefined4 *)0xffffffff) {
    iVar9 = param_1[0x27];
    if (iVar9 != 0) {
      FUN_004be99e(iVar9,0x5c,*(undefined4 *)(iVar9 + -4),FUN_00484a60);
      FUN_004bc150(iVar9 + -4);
    }
    param_1[0x27] = 0;
    param_1[0x29] = param_4;
    param_1[0x28] = param_4;
    puVar4 = operator_new((int)param_4 * 0x5c + 4);
    puStack_8 = (undefined1 *)0x0;
    if (puVar4 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)0x0;
    }
    else {
      puVar10 = puVar4 + 1;
      *puVar4 = param_4;
      FUN_004be91c(puVar10,0x5c,param_4,FUN_00482340,FUN_00484a60);
    }
    puStack_8 = (undefined1 *)0xffffffff;
    param_1[0x27] = puVar10;
  }
  pvVar5 = operator_new(param_1[0x29] * 0xc0);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  param_1[0x37] = pvVar5;
  iVar9 = 0;
  if (0 < (int)param_1[0x28]) {
    iVar6 = 0;
    do {
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar6) = param_1[0x33];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar6) = param_1[0x35];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar6) = 0;
      iVar7 = iVar6 + 0x20;
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar7) = param_1[0x34];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar7) = param_1[0x35];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar7) = 0;
      iVar7 = iVar6 + 0x40;
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar7) = param_1[0x33];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar7) = param_1[0x36];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar7) = 0;
      iVar7 = iVar6 + 0x60;
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar7) = param_1[0x34];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar7) = param_1[0x35];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar7) = 0;
      iVar7 = iVar6 + 0x80;
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar7) = param_1[0x34];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar7) = param_1[0x36];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar7) = 0;
      iVar7 = iVar6 + 0xa0;
      iVar9 = iVar9 + 6;
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar7) = param_1[0x33];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar7) = param_1[0x36];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar7) = 0;
      iVar6 = iVar6 + 0xc0;
    } while (iVar9 < (int)param_1[0x28]);
  }
  if ((((float)param_1[7] == 0.0) && ((float)param_1[8] == 0.0)) && ((float)param_1[9] == 0.0)) {
    param_1[7] = *unaff_retaddr;
    param_1[8] = unaff_retaddr[1];
    param_1[9] = unaff_retaddr[2];
  }
  pfVar1 = (float *)(param_1 + 0x1f);
  if ((((float)param_1[0x1f] == 0.0) && ((float)param_1[0x20] == 0.0)) &&
     ((float)param_1[0x21] == 0.0)) {
    *pfVar1 = *param_2;
    param_1[0x20] = param_2[1];
    param_1[0x21] = param_2[2];
  }
  if ((*pfVar1 == 0.0) && ((float)param_1[0x21] == 0.0)) {
    fVar3 = (float)param_1[0x20];
    fVar11 = *pfVar1;
    uVar8 = param_1[0x21];
  }
  else {
    fVar3 = (float)param_1[0x21];
    fVar11 = *pfVar1;
    uVar8 = param_1[0x20];
  }
  pfVar2 = (float *)(param_1 + 0x3a);
  *pfVar2 = -fVar3;
  param_1[0x3b] = fVar11;
  iVar9 = 0;
  param_1[0x3c] = uVar8;
  param_1[0x3d] =
       (float)param_1[0x3b] * (float)param_1[0x21] - (float)param_1[0x20] * (float)param_1[0x3c];
  param_1[0x3e] = *pfVar1 * (float)param_1[0x3c] - *pfVar2 * (float)param_1[0x21];
  param_1[0x3f] = (float)param_1[0x20] * *pfVar2 - (float)param_1[0x3b] * *pfVar1;
  if (0 < (int)param_1[0x28]) {
    do {
      (**(code **)*param_1)(iVar9);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)param_1[0x28]);
  }
  *(undefined1 *)(param_1 + 0x2a) = 0;
  ExceptionList = pvStack_10;
  return;
}

