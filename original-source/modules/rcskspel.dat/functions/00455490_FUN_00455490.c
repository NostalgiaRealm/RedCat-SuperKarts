/*
 * FUN_00455490 at 00455490
 * undefined FUN_00455490(void)
 * Address ranges: 00455490-004559f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00455490(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  undefined4 uVar10;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float afStack_8c [3];
  char *pcStack_80;
  int local_7c [4];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [4];
  int iStack_58;
  undefined1 local_4c [16];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [16];
  undefined1 auStack_1c [12];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cde63;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = FUN_00417e90(param_1[8]);
  if (cVar2 != '\0') {
    uVar3 = FUN_0044fb50();
    switch(uVar3) {
    case 1:
      uVar3 = FUN_0044fbc0();
      uVar3 = FUN_004314a0(auStack_6c,uVar3);
      iStack_4 = 0;
      uVar3 = FUN_00412710(auStack_5c,s_AFIRE_ROCKET_004f1eb7 + 1,uVar3);
      uVar10 = 10;
      iStack_4._0_1_ = 1;
      FUN_004371f0(10,uVar3);
      FUN_00437b10(uVar10,uVar3);
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      FUN_0040b4f0(1);
      break;
    case 2:
      uVar3 = FUN_0044fbc0();
      uVar3 = FUN_004314a0(local_7c,uVar3);
      iStack_4 = 2;
      uVar3 = FUN_00412710(local_4c,s_FIRE_SOAP_004f1ec4,uVar3);
      uVar10 = 10;
      iStack_4._0_1_ = 3;
      FUN_004371f0(10,uVar3);
      FUN_00437b10(uVar10,uVar3);
      iStack_4 = CONCAT31(iStack_4._1_3_,2);
      FUN_0040b4f0(1);
      break;
    case 3:
      uVar3 = FUN_0044fbc0();
      uVar3 = FUN_004314a0(auStack_3c,uVar3);
      iStack_4 = 4;
      uVar3 = FUN_00412710(&fStack_90,s_FIRE_OIL_004f1ed0,uVar3);
      uVar10 = 10;
      iStack_4._0_1_ = 5;
      FUN_004371f0(10,uVar3);
      FUN_00437b10(uVar10,uVar3);
      iStack_4 = CONCAT31(iStack_4._1_3_,4);
      FUN_0040b4f0(1);
      break;
    case 4:
      uVar3 = FUN_0044fbc0();
      uVar3 = FUN_004314a0(auStack_1c,uVar3);
      iStack_4 = 6;
      uVar3 = FUN_00412710(auStack_2c,s_FIRE_GUM_004f1edc,uVar3);
      uVar10 = 10;
      iStack_4._0_1_ = 7;
      FUN_004371f0(10,uVar3);
      FUN_00437b10(uVar10,uVar3);
      iStack_4 = CONCAT31(iStack_4._1_3_,6);
      FUN_0040b4f0(1);
      break;
    default:
      goto switchD_004554d4_default;
    }
    iStack_4 = 0xffffffff;
    FUN_0040b4f0(1);
  }
switchD_004554d4_default:
  local_7c[0] = param_1[8];
  local_7c[1] = 0;
  pfVar4 = (float *)FUN_00456d10(local_4c,local_7c);
  fStack_90 = *pfVar4;
  afStack_8c[0] = pfVar4[1];
  piVar5 = (int *)FUN_00480350(&fStack_90,afStack_8c);
  iStack_58 = piVar5[1];
  *(int **)(*piVar5 + 0x10) = param_1;
  uVar3 = FUN_0044fbc0();
  uVar3 = FUN_0044fb50(uVar3);
  iVar6 = FUN_00456ad0(uVar3);
  cVar2 = FUN_00417e90(param_1[8]);
  iVar7 = DAT_0053be28;
  if (cVar2 == '\0') {
    iVar7 = (&DAT_005081bc)[param_1[8] * 0x1c];
  }
  piVar5 = (int *)(iVar7 * 0xd0 + 0x9c + DAT_0067ee20);
  param_1[0xc] = *piVar5;
  param_1[0xd] = piVar5[1];
  iVar7 = piVar5[2];
  param_1[9] = -2;
  param_1[0xe] = iVar7;
  if (*(char *)(iVar6 + 8) != '\0') {
    iVar7 = FUN_004561e0(param_1[8]);
    param_1[9] = iVar7;
  }
  if (param_1[9] == param_1[8]) {
    pcStack_80 = s_CShotBonus__Shoot__Shot_yourself_004f1ee8;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&pcStack_80,&DAT_004d5538);
  }
  FUN_004500d0();
  iVar7 = FUN_00490ce0();
  fStack_90 = *(float *)(DAT_006a5ee0 + 0x74 + iVar7 * 0xbc);
  cVar2 = FUN_00417e90(param_1[8]);
  iVar7 = DAT_0053be28;
  if (cVar2 == '\0') {
    iVar7 = (&DAT_005081bc)[param_1[8] * 0x1c];
  }
  iVar1 = *(int *)(iVar7 * 0xd0 + 0xc + DAT_0067ee20);
  iVar7 = DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8;
  fStack_9c = *(float *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8);
  fStack_98 = *(float *)(iVar7 + 4);
  fStack_94 = *(float *)(iVar7 + 8);
  iVar7 = FUN_004500d0();
  iVar7 = iVar7 * 0xd0 + DAT_0067ee20;
  uVar3 = FUN_00450500(&fStack_9c);
  *(undefined4 *)(iVar7 + 0x1c) = uVar3;
  FUN_00417e90(param_1[8]);
  uVar8 = __ftol();
  iVar7 = (DAT_004fc8f8 & uVar8) * 4;
  fStack_9c = fStack_9c - *(float *)(iVar7 + DAT_006a5c88) * (float)param_1[0xe];
  fStack_94 = *(float *)(iVar7 + DAT_006a5cd0) * (float)param_1[0xe] + fStack_94;
  cVar2 = FUN_00417e90(param_1[8]);
  iVar7 = DAT_0053be28;
  if (cVar2 == '\0') {
    iVar7 = (&DAT_005081bc)[param_1[8] * 0x1c];
  }
  fVar9 = (float10)FUN_00430ff0(iVar7);
  fStack_98 = (float)(fVar9 + (float10)fStack_90 + (float10)10.0);
  (**(code **)(*param_1 + 8))(&fStack_9c);
  cVar2 = FUN_00417e90(param_1[8]);
  iVar7 = DAT_0053be28;
  if (cVar2 == '\0') {
    iVar7 = (&DAT_005081bc)[param_1[8] * 0x1c];
  }
  FUN_0044fb20(DAT_006a5c38 + *(int *)(iVar7 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x74);
  FUN_004500c0();
  FUN_004a09e0();
  FUN_00456440(2);
  if (1 < *(int *)(iVar6 + 0x1c)) {
    FUN_004560c0(*(int *)(iVar6 + 0x1c) + -1);
  }
  ExceptionList = pvStack_10;
  return;
}

