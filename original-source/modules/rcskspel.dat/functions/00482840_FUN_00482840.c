/*
 * FUN_00482840 at 00482840
 * undefined FUN_00482840(void)
 * Address ranges: 00482840-00482c5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00482840(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  float fVar11;
  int unaff_retaddr;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d13a1;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)*param_4)(param_1);
  if (param_4 != (undefined4 *)0xffffffff) {
    iVar8 = param_1[0x27];
    if (iVar8 != 0) {
      FUN_004be99e(iVar8,0x5c,*(undefined4 *)(iVar8 + -4),FUN_00484a60);
      FUN_004bc150(iVar8 + -4);
    }
    param_1[0x27] = 0;
    param_1[0x29] = param_4;
    param_1[0x28] = param_4;
    puVar4 = operator_new((int)param_4 * 0x5c + 4);
    puStack_8 = (undefined1 *)0x0;
    if (puVar4 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9 = puVar4 + 1;
      *puVar4 = param_4;
      FUN_004be91c(puVar9,0x5c,param_4,FUN_00482340,FUN_00484a60);
    }
    puStack_8 = (undefined1 *)0xffffffff;
    param_1[0x27] = puVar9;
  }
  pvVar5 = operator_new(param_1[0x29] * 0xc0);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  param_1[0x37] = pvVar5;
  iVar8 = 0;
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
      iVar8 = iVar8 + 6;
      *(undefined4 *)(param_1[0x37] + 0x18 + iVar7) = param_1[0x33];
      *(undefined4 *)(param_1[0x37] + 0x1c + iVar7) = param_1[0x36];
      *(undefined4 *)(param_1[0x37] + 0x14 + iVar7) = 0;
      iVar6 = iVar6 + 0xc0;
    } while (iVar8 < (int)param_1[0x28]);
  }
  if ((((float)param_1[7] == 0.0) && ((float)param_1[8] == 0.0)) && ((float)param_1[9] == 0.0)) {
    iVar6 = *(int *)(unaff_retaddr * 0xd0 + 0xc + DAT_0067ee20);
    iVar8 = DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8;
    param_1[7] = *(undefined4 *)(DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8);
    param_1[8] = *(undefined4 *)(iVar8 + 4);
    param_1[9] = *(undefined4 *)(iVar8 + 8);
  }
  pfVar1 = (float *)(param_1 + 0x1f);
  if ((((float)param_1[0x1f] == 0.0) && ((float)param_1[0x20] == 0.0)) &&
     ((float)param_1[0x21] == 0.0)) {
    pfVar2 = (float *)(param_2 * 0xd0 + 0x9c + DAT_0067ee20);
    *pfVar1 = *pfVar2;
    param_1[0x20] = pfVar2[1];
    param_1[0x21] = pfVar2[2];
  }
  param_1[0x22] = unaff_retaddr;
  param_1[0x23] = param_2;
  if ((*pfVar1 == 0.0) && ((float)param_1[0x21] == 0.0)) {
    fVar3 = (float)param_1[0x20];
    fVar11 = *pfVar1;
    uVar10 = param_1[0x21];
  }
  else {
    fVar3 = (float)param_1[0x21];
    fVar11 = *pfVar1;
    uVar10 = param_1[0x20];
  }
  pfVar2 = (float *)(param_1 + 0x3a);
  *pfVar2 = -fVar3;
  param_1[0x3b] = fVar11;
  iVar8 = 0;
  param_1[0x3c] = uVar10;
  param_1[0x3d] =
       (float)param_1[0x21] * (float)param_1[0x3b] - (float)param_1[0x20] * (float)param_1[0x3c];
  param_1[0x3e] = *pfVar1 * (float)param_1[0x3c] - (float)param_1[0x21] * *pfVar2;
  param_1[0x3f] = (float)param_1[0x20] * *pfVar2 - *pfVar1 * (float)param_1[0x3b];
  if (0 < (int)param_1[0x28]) {
    do {
      (**(code **)*param_1)(iVar8);
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)param_1[0x28]);
  }
  *(undefined1 *)(param_1 + 0x2a) = 0;
  FUN_004afcc0(0,1);
  FUN_004afce0(s_numbparticles___i_004f9a4c,param_1[0x29]);
  FUN_004afcc0(0,0);
  ExceptionList = pvStack_10;
  return;
}

