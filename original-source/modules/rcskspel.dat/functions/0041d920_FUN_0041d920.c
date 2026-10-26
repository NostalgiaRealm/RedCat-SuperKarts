/*
 * FUN_0041d920 at 0041d920
 * undefined FUN_0041d920(void)
 * Address ranges: 0041d920-0041deac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d920(void)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  float *pfVar5;
  uint uVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  iVar2 = FUN_004b3830(0x31);
  if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
    FUN_0041e280(1);
  }
  iVar2 = FUN_004b3830(0x32);
  if (iVar2 != 0) {
    FUN_0041e280(3);
  }
  if (DAT_0053b9c0 == 0) {
    iVar2 = FUN_004b3830(0x33);
    if (iVar2 == 0) {
      iVar2 = FUN_0041e270();
      uVar4 = DAT_004e2ac8;
      if (iVar2 != 5) goto LAB_0041d9a5;
    }
    else {
      iVar2 = FUN_0041e270();
      if (iVar2 == 5) goto LAB_0041d9a5;
      DAT_004e2ac8 = FUN_0041e270();
      uVar4 = 5;
    }
    FUN_0041e280(uVar4);
  }
LAB_0041d9a5:
  iVar2 = FUN_004b3830(0x34);
  if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
    FUN_0041e280(0);
  }
  if (DAT_0053ba6c != 0) {
    iVar2 = FUN_004b3830(0x35);
    if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
      FUN_0041e280(4);
    }
    iVar2 = FUN_004b3830(0x37);
    if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
      FUN_0041e280(6);
    }
    iVar2 = FUN_004b3830(0x38);
    if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
      FUN_0041e280(7);
    }
    iVar2 = FUN_004b3830(0x39);
    if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
      FUN_0041e280(8);
    }
    iVar2 = FUN_004b3830(0x30);
    if ((iVar2 != 0) && (DAT_0053b9c0 == 0)) {
      FUN_0041e280(9);
    }
    if ((((&DAT_00508620)[DAT_00508670] != 7) && (DAT_0053b9c0 == 0)) && (DAT_0053ba6c != 0)) {
      FUN_00431750();
      puVar3 = (undefined4 *)FUN_00431830();
      local_64 = *puVar3;
      local_60 = (float)puVar3[1];
      local_5c = puVar3[2];
      puVar3 = (undefined4 *)FUN_00498a80(local_4c);
      local_58 = *puVar3;
      local_54 = (float)puVar3[1];
      local_50 = puVar3[2];
      fVar1 = local_60 * 0.5 + local_54;
      uVar4 = __ftol();
      FUN_0049a5c0(&local_70,&local_58,uVar4);
      local_6c = fVar1;
      iVar2 = FUN_004b3830(0x49);
      if (iVar2 != 0) {
        fVar1 = _DAT_004e2abc + 1.0;
        local_70 = fVar1 * local_70;
        local_6c = fVar1 * local_6c;
        local_68 = local_68 * fVar1;
      }
      iVar2 = FUN_004b3830(0x4b);
      if (iVar2 != 0) {
        fVar1 = 1.0 - _DAT_004e2abc;
        local_70 = fVar1 * local_70;
        local_6c = fVar1 * local_6c;
        local_68 = local_68 * fVar1;
      }
      iVar2 = FUN_004b3830(0x4a);
      if (iVar2 != 0) {
        local_70 = local_70 - _DAT_004e2ab8;
      }
      iVar2 = FUN_004b3830(0x4c);
      if (iVar2 != 0) {
        local_70 = _DAT_004e2ab8 + local_70;
      }
      iVar2 = FUN_004b3830(0x41);
      if (iVar2 != 0) {
        local_6c = _DAT_004e2ab8 + local_6c;
      }
      iVar2 = FUN_004b3830(0x5a);
      if (iVar2 != 0) {
        local_6c = local_6c - _DAT_004e2ab8;
      }
      iVar2 = FUN_004b3830(0x52);
      if (iVar2 != 0) {
        pfVar5 = (float *)FUN_0041cc70(local_4c);
        local_70 = *pfVar5;
        local_6c = pfVar5[1];
        local_68 = pfVar5[2];
      }
      iVar2 = FUN_004b3830(0x54);
      if (iVar2 != 0) {
        FUN_0041cd50(local_70,local_6c,local_68);
      }
      FUN_00498ad0(local_70,local_6c,local_68);
    }
  }
  if ((&DAT_00508620)[DAT_00508670] == 7) {
    FUN_0041ecd0();
  }
  puVar3 = (undefined4 *)(DAT_00680ba0 + 8 + (&DAT_00508620)[DAT_00508670] * 0x178);
  DAT_00508674 = FUN_004977d0((&DAT_00508648)[DAT_00508670],*puVar3,puVar3[1],puVar3[2]);
  (&DAT_00508648)[DAT_00508670] = DAT_00508674;
  FUN_00498c00();
  iVar2 = DAT_00680ba0 + (&DAT_00508620)[DAT_00508670] * 0x178;
  if (DAT_006a5f28 == 0) {
    puVar3 = (undefined4 *)FUN_004a1ad0(local_40,iVar2 + 8,iVar2 + 0x54,iVar2 + 0x60,0);
  }
  else {
    puVar3 = (undefined4 *)FUN_004a1df0(local_40,iVar2 + 8,iVar2 + 0x54,iVar2 + 0x60);
  }
  puVar7 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar3 = local_40;
  puVar7 = &DAT_006a619c;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar2 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,2,&DAT_006a619c);
  if (iVar2 != 0) {
    uVar4 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x36,uVar4);
  }
  iVar2 = (&DAT_00508620)[DAT_00508670];
  fVar1 = *(float *)(DAT_00680ba0 + 0x54 + iVar2 * 0x178) -
          *(float *)(DAT_00680ba0 + 8 + iVar2 * 0x178);
  iVar2 = DAT_00680ba0 + iVar2 * 0x178;
  local_6c = *(float *)(iVar2 + 0x58) - *(float *)(iVar2 + 0xc);
  local_68 = *(float *)(iVar2 + 0x5c) - *(float *)(iVar2 + 0x10);
  fVar8 = SQRT((float10)fVar1 * (float10)fVar1 + (float10)local_68 * (float10)local_68);
  local_70 = (float)((float10)fVar1 / fVar8);
  fpatan((float10)local_68 / fVar8,(float10)local_70);
  uVar6 = __ftol();
  FUN_004273f0(*(undefined4 *)(DAT_006a5cd0 + (uVar6 & DAT_004fc8f8) * 4));
  return;
}

