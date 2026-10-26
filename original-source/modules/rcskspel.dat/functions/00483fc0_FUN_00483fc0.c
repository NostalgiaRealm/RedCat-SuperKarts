/*
 * FUN_00483fc0 at 00483fc0
 * undefined FUN_00483fc0(void)
 * Address ranges: 00483fc0-0048426c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00483fc0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  float fVar8;
  int iVar9;
  int unaff_retaddr;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d142b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)*param_4)(param_1);
  puVar5 = (undefined4 *)0x0;
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
    if (puVar4 != (undefined4 *)0x0) {
      puVar5 = puVar4 + 1;
      *puVar4 = param_4;
      FUN_004be91c(puVar5,0x5c,param_4,FUN_00484a40,FUN_00484a60);
    }
    puStack_8 = (undefined1 *)0xffffffff;
    param_1[0x27] = puVar5;
  }
  if ((((float)param_1[7] == 0.0) && ((float)param_1[8] == 0.0)) && ((float)param_1[9] == 0.0)) {
    iVar7 = *(int *)(unaff_retaddr * 0xd0 + 0xc + DAT_0067ee20);
    iVar9 = DAT_006a5c38 + iVar7 + 0x50 + iVar7 * 0xa8;
    param_1[7] = *(undefined4 *)(DAT_006a5c38 + iVar7 + 0x50 + iVar7 * 0xa8);
    param_1[8] = *(undefined4 *)(iVar9 + 4);
    param_1[9] = *(undefined4 *)(iVar9 + 8);
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
    fVar8 = *pfVar1;
    uVar6 = param_1[0x21];
  }
  else {
    fVar3 = (float)param_1[0x21];
    fVar8 = *pfVar1;
    uVar6 = param_1[0x20];
  }
  pfVar2 = (float *)(param_1 + 0x3a);
  *pfVar2 = -fVar3;
  param_1[0x3b] = fVar8;
  iVar9 = 0;
  param_1[0x3c] = uVar6;
  param_1[0x3d] =
       (float)param_1[0x3b] * (float)param_1[0x21] - (float)param_1[0x20] * (float)param_1[0x3c];
  param_1[0x3e] = (float)param_1[0x3c] * *pfVar1 - *pfVar2 * (float)param_1[0x21];
  param_1[0x3f] = (float)param_1[0x20] * *pfVar2 - (float)param_1[0x3b] * *pfVar1;
  if (0 < (int)param_1[0x28]) {
    iVar7 = 0;
    do {
      (**(code **)*param_1)(iVar9);
      iVar9 = iVar9 + 1;
      *(undefined4 *)(param_1[0x27] + 0xc + iVar7) = param_1[0x2b];
      iVar7 = iVar7 + 0x5c;
    } while (iVar9 < (int)param_1[0x28]);
  }
  *(undefined1 *)(param_1 + 0x2a) = 0;
  ExceptionList = pvStack_10;
  return;
}

