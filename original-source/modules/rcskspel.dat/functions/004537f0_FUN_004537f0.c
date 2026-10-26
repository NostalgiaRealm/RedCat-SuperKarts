/*
 * FUN_004537f0 at 004537f0
 * undefined FUN_004537f0(void)
 * Address ranges: 004537f0-00453ac4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004537f0(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  DWORD DVar5;
  uint3 uVar7;
  int iVar6;
  uint extraout_ECX;
  uint3 uVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  float *pfVar11;
  uint uVar12;
  float *pfVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  float fStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cdd08;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_0044fbc0();
  if (iVar2 < 1) {
    param_1 = s_Error_in_COwnedBonus__ShootTurbo_004f1cb0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_004d5538);
  }
  uVar3 = FUN_0044fbc0();
  iVar4 = FUN_00453d70(uVar3);
  iVar2 = (int)param_1;
  cVar1 = FUN_00417e90(param_1);
  if (cVar1 == '\0') {
    cVar1 = FUN_00417e90(iVar2);
    iVar6 = DAT_0053be28;
    if (cVar1 == '\0') {
      iVar6 = (&DAT_005081bc)[iVar2 * 0x1c];
    }
    *(float *)(iVar6 * 0xd0 + 0xa4 + DAT_0067ee20) =
         (float)iVar4 * 0.01 * *(float *)(iVar6 * 0xd0 + 0xa4 + DAT_0067ee20);
  }
  else {
    *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20) =
         (float)iVar4 * 0.01 * *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20);
    uVar3 = FUN_00438310(auStack_1c);
    uStack_4 = 0;
    FUN_004387a0(DAT_00508610,uVar3);
    uStack_4 = 0xffffffff;
    if (iStack_18 != 0) {
      cVar1 = *(char *)(iStack_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(iStack_18 + -1));
      }
      else {
        *(char *)(iStack_18 + -1) = cVar1 + -1;
      }
    }
  }
  DVar5 = GetTickCount();
  (&DAT_0053a22c)[iVar2] = DVar5;
  cVar1 = FUN_00417e90(iVar2);
  iVar4 = DAT_0053be28;
  if (cVar1 == '\0') {
    iVar4 = (&DAT_005081bc)[iVar2 * 0x1c];
  }
  iVar6 = iVar4;
  FUN_0048a480(iVar4);
  FUN_0048a890(iVar6);
  uVar9 = FUN_0044fbc0();
  iVar6 = (int)uVar9;
  uVar8 = (uint3)((ulonglong)uVar9 >> 0x28);
  uVar7 = (uint3)(extraout_ECX >> 8);
  if (iVar6 == 1) {
    uVar15 = CONCAT31(uVar7,1);
    uVar12 = (uint)uVar8 << 8;
    uVar16 = 0;
    iVar6 = (uint)uVar7 << 8;
    iVar2 = iVar2 + 1;
    uVar3 = 0;
  }
  else if (iVar6 == 2) {
    uVar16 = (uint)uVar7 << 8;
    uVar15 = CONCAT31(uVar8,1);
    uVar3 = CONCAT31(uVar7,1);
    iVar6 = (uint)uVar8 << 8;
    uVar12 = 0;
    iVar2 = iVar2 + 2;
  }
  else {
    if (iVar6 + -3 == 0) {
      fStack_28 = DAT_0067da60 - 18.0;
      uVar3 = 1;
      fStack_24 = DAT_0067da64 + 2.0;
      pfVar13 = &fStack_34;
      uVar15 = 0x41200000;
      pfVar11 = &fStack_28;
      fStack_34 = DAT_0067da60 + 18.0;
      uStack_20 = 0xc1400000;
      uStack_2c = 0xc1400000;
      fStack_30 = DAT_0067da64 + 2.0;
      FUN_0048a480(iVar4,pfVar11,pfVar13,0x41200000,1);
      FUN_0048a6d0(iVar4,pfVar11,pfVar13,uVar15,uVar3);
      ExceptionList = pvStack_c;
      return;
    }
    uVar16 = (uint)((ulonglong)uVar9 >> 0x20) & 0xffffff00;
    uVar7 = (uint3)((uint)(iVar6 + -3) >> 8);
    uVar15 = CONCAT31(uVar7,1);
    uVar12 = extraout_ECX & 0xffffff00;
    uVar3 = 0;
    iVar6 = (uint)uVar7 << 8;
  }
  uVar14 = 0x41a00000;
  puVar10 = &DAT_0067da60;
  FUN_0048a480(iVar4,&DAT_0067da60,iVar6,iVar2,uVar3,uVar12,0x41a00000,uVar15,uVar16);
  FUN_0048a570(iVar4,puVar10,iVar6,iVar2,uVar3,uVar12,uVar14,uVar15,uVar16);
  ExceptionList = pvStack_c;
  return;
}

