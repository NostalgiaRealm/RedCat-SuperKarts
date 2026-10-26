/*
 * FUN_0042f9c0 at 0042f9c0
 * undefined FUN_0042f9c0(void)
 * Address ranges: 0042f9c0-0043001d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042f9c0(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined1 *puVar12;
  undefined1 local_e8 [4];
  char *local_e4;
  uint local_e0;
  undefined4 local_dc;
  undefined1 local_d8 [12];
  undefined4 local_cc [16];
  undefined1 local_8c [64];
  undefined1 auStack_4c [64];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd0eb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_0053ba6c != 0) {
    ExceptionList = &pvStack_c;
    iVar3 = FUN_004b3830(0x76);
    if ((iVar3 != 0) &&
       (_DAT_0053a5f0 = FUN_0048bf80(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0x24 + DAT_0067ee20),1),
       -1 < _DAT_0053a5f0)) {
      iVar3 = _DAT_0053a5f0 * 0x50 + 8 + DAT_00680ae0;
      _DAT_0053be44 = *(undefined4 *)(_DAT_0053a5f0 * 0x50 + 8 + DAT_00680ae0);
      DAT_0053be48 = *(undefined4 *)(iVar3 + 4);
      DAT_0053be4c = *(undefined4 *)(iVar3 + 8);
      iVar1 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
      iVar3 = DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8;
      *(undefined4 *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8) = _DAT_0053be44;
      *(undefined4 *)(iVar3 + 4) = DAT_0053be48;
      *(undefined4 *)(iVar3 + 8) = DAT_0053be4c;
      iVar3 = DAT_0053be28 * 0xd0 + DAT_0067ee20;
      uVar4 = FUN_00450690(DAT_0053be28);
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      FUN_00493540(DAT_0053be28,*(undefined4 *)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20),0);
    }
    iVar3 = FUN_004b3830(0x77);
    if ((iVar3 != 0) &&
       (_DAT_0053a5f0 = FUN_0048bf80(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0x24 + DAT_0067ee20),0),
       -1 < _DAT_0053a5f0)) {
      puVar5 = (undefined4 *)(_DAT_0053a5f0 * 0x50 + 8 + DAT_00680ae0);
      _DAT_0053be44 = *puVar5;
      DAT_0053be48 = puVar5[1];
      DAT_0053be4c = puVar5[2];
      iVar1 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
      iVar3 = DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8;
      *(undefined4 *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8) = _DAT_0053be44;
      *(undefined4 *)(iVar3 + 4) = DAT_0053be48;
      *(undefined4 *)(iVar3 + 8) = DAT_0053be4c;
      iVar3 = DAT_0053be28 * 0xd0 + DAT_0067ee20;
      uVar4 = FUN_00450690(DAT_0053be28);
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      FUN_00493540(DAT_0053be28,*(undefined4 *)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20),1);
    }
    iVar3 = FUN_004b3830(0x51);
    if (iVar3 != 0) {
      FUN_00481e70(DAT_0053be28,DAT_0053be28);
    }
    iVar3 = FUN_004b3830(0x57);
    if (iVar3 != 0) {
      FUN_00481a60(DAT_0053be28,DAT_0053be28);
    }
    iVar3 = FUN_004b3830(0x45);
    if (iVar3 != 0) {
      FUN_00481e80(DAT_0053be28,DAT_0053be28);
    }
    iVar3 = FUN_004b3830(0x41);
    if (iVar3 != 0) {
      FUN_00481ec0(DAT_0053be28,DAT_0053be28);
    }
    iVar3 = FUN_004b3830(0x53);
    if (iVar3 != 0) {
      FUN_00481a50(DAT_0053be28,DAT_0053be28);
    }
  }
  iVar3 = FUN_004b3830(0x20);
  if (iVar3 != 0) {
    uVar6 = 0xffffffff;
    pcVar8 = s_CLAXON_004eafb0;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6 - 1;
    local_e4 = (char *)0x0;
    local_e0 = 0;
    local_dc = 0;
    cVar2 = FUN_0040b600(uVar6,1);
    if (cVar2 != '\0') {
      pcVar8 = s_CLAXON_004eafb0;
      pcVar9 = local_e4;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      local_e4[uVar6] = '\0';
      local_e0 = uVar6;
    }
    puVar12 = local_e8;
    local_4 = 0;
    uVar4 = FUN_00437ea0(DAT_0053bebc,puVar12);
    FUN_004371f0(uVar4);
    FUN_00437b40(uVar4,puVar12);
    local_4 = 0xffffffff;
    if (local_e4 != (char *)0x0) {
      cVar2 = local_e4[-1];
      if ((cVar2 == '\0') || (cVar2 == -1)) {
        FUN_004bc150(local_e4 + -1);
      }
      else {
        local_e4[-1] = cVar2 + -1;
      }
    }
    FUN_004be8cb(local_d8,10,&DAT_004eafb8,DAT_004ead60);
    FUN_0043b600(local_d8,0);
    DAT_004ead64 = DAT_004ead64 + -1;
    if ((DAT_004ead64 == 0) && (DAT_004ead64 = 3, DAT_004ead60 == 0xc)) {
      DAT_004ead60 = 1;
    }
  }
  if (DAT_0053ba6c != 0) {
    iVar3 = FUN_004b3830(0x4d);
    if (iVar3 != 0) {
      iVar3 = FUN_004b3830(0x4d);
      while (iVar3 != 0) {
        iVar3 = FUN_004b3830(0x4d);
      }
      DAT_0053baa0 = DAT_0053baa0 + 1;
      bVar11 = DAT_0053baa0 == DAT_00508610;
      if (DAT_00508610 < DAT_0053baa0) {
        DAT_0053baa0 = 0;
        bVar11 = DAT_00508610 == 0;
      }
      iVar3 = DAT_0053be28;
      if (!bVar11) {
        iVar3 = (&DAT_00503ef0)[DAT_0053baa0 * 0x47];
      }
      FUN_0041e0b0(iVar3);
    }
    iVar3 = FUN_004b3830(0x6b);
    if (iVar3 != 0) {
      _DAT_004ead68 = _DAT_004ead68 * 1.1;
      if (_DAT_004ead68 <= 0.0) {
        _DAT_004ead68 = 0.01;
      }
      puVar5 = (undefined4 *)
               FUN_004a1a40(local_8c,0.5 / _DAT_004ead68,0x46435000,_DAT_004ead68 * 3.1415927);
      puVar10 = local_cc;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar10 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar5 = local_cc;
      puVar10 = &DAT_006a615c;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar10 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar10 = puVar10 + 1;
      }
      iVar3 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
      if (iVar3 != 0) {
        uVar4 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar4);
      }
    }
    iVar3 = FUN_004b3830(0x6d);
    if (iVar3 != 0) {
      _DAT_004ead68 = _DAT_004ead68 * 0.9090909;
      if (_DAT_004ead68 <= 0.0) {
        _DAT_004ead68 = -0.01;
      }
      puVar5 = (undefined4 *)
               FUN_004a1a40(auStack_4c,0.5 / _DAT_004ead68,0x46435000,_DAT_004ead68 * 3.1415927);
      puVar10 = local_cc;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar10 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar5 = local_cc;
      puVar10 = &DAT_006a615c;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar10 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar10 = puVar10 + 1;
      }
      iVar3 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
      if (iVar3 != 0) {
        uVar4 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar4);
      }
    }
  }
  iVar3 = FUN_004b3830(0x44);
  if (iVar3 != 0) {
    DAT_0053ba44 = DAT_0053ba44 + 1;
    if (3 < DAT_0053ba44) {
      DAT_0053ba44 = 0;
    }
    iVar3 = FUN_004b3830(0x44);
    while (iVar3 != 0) {
      iVar3 = FUN_004b3830(0x44);
    }
  }
  iVar3 = FUN_004b3830(0x1b);
  if ((((iVar3 != 0) && (DAT_0053b9c0 != 6)) && (DAT_0053b9c0 != 3)) && (DAT_0053b9c0 != 1)) {
    DAT_0053b9f8 = 2;
  }
  iVar3 = FUN_004b3830(0x50);
  if (((iVar3 != 0) && (DAT_0053b9c0 != 6)) && (DAT_0053b9c0 != 3)) {
    FUN_00430610(1);
    DAT_0053b9f8 = 1;
  }
  ExceptionList = pvStack_c;
  return;
}

