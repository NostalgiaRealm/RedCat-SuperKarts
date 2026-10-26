/*
 * FUN_00429a90 at 00429a90
 * undefined FUN_00429a90(void)
 * Address ranges: 00429a90-0042a1a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429a90(void)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  float *pfVar4;
  float local_80 [4];
  float fStack_70;
  float fStack_60;
  float local_40 [16];
  
  iVar1 = FUN_004b3830(0x57);
  if (((iVar1 != 0) && (iVar1 = FUN_004b3830(0x11), iVar1 != 0)) &&
     (iVar1 = FUN_004b3830(0x44), iVar1 != 0)) {
    if (DAT_0053a264 == '\0') {
      pfVar2 = (float *)FUN_004a1a40(local_80,0x41200000,0x46435000,0x4020d97c);
      pfVar4 = local_40;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      pfVar2 = local_40;
      pfVar4 = (float *)&DAT_006a615c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
    }
    else {
      pfVar2 = (float *)FUN_004a1a40(local_80,0x41200000,0x46435000,0x3fb4f4ab);
      pfVar4 = local_40;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      pfVar2 = local_40;
      pfVar4 = (float *)&DAT_006a615c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
    }
    if (iVar1 != 0) {
      uVar3 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar3);
    }
    DAT_0053a264 = DAT_0053a264 == '\0';
    while (((iVar1 = FUN_004b3830(0x57), iVar1 != 0 || (iVar1 = FUN_004b3830(0x11), iVar1 != 0)) ||
           (iVar1 = FUN_004b3830(0x44), iVar1 != 0))) {
      FUN_004baf80();
    }
    if ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1) {
      pfVar2 = (float *)&DAT_006a615c;
      pfVar4 = local_40;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      pfVar2 = local_40;
      pfVar4 = local_80;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      local_80[0] = -local_40[0];
      fStack_70 = -fStack_70;
      fStack_60 = -fStack_60;
      pfVar2 = local_80;
      pfVar4 = (float *)&DAT_006a615c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
      if (iVar1 != 0) {
        uVar3 = FUN_004aaa00(iVar1);
        FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar3);
      }
    }
  }
  iVar1 = FUN_004b3830(0x55);
  if (((iVar1 != 0) && (iVar1 = FUN_004b3830(0x11), iVar1 != 0)) &&
     (iVar1 = FUN_004b3830(0x50), iVar1 != 0)) {
    if (DAT_0053a264 == '\0') {
      pfVar2 = (float *)FUN_004a1a40(local_80,0x41200000,0x46435000,0x4091c519);
      pfVar4 = local_40;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      pfVar2 = local_40;
      pfVar4 = (float *)&DAT_006a615c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
    }
    else {
      pfVar2 = (float *)FUN_004a1a40(local_80,0x41200000,0x46435000,0x3fb4f4ab);
      pfVar4 = local_40;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      pfVar2 = local_40;
      pfVar4 = (float *)&DAT_006a615c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar4 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar4 = pfVar4 + 1;
      }
      iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
    }
    if (iVar1 != 0) {
      uVar3 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar3);
    }
    DAT_0053a264 = DAT_0053a264 == '\0';
    while (((iVar1 = FUN_004b3830(0x55), iVar1 != 0 || (iVar1 = FUN_004b3830(0x11), iVar1 != 0)) ||
           (iVar1 = FUN_004b3830(0x50), iVar1 != 0))) {
      FUN_004baf80();
    }
  }
  iVar1 = FUN_004b3830(0x11);
  if (((iVar1 != 0) && (iVar1 = FUN_004b3830(0xd), iVar1 != 0)) &&
     (iVar1 = FUN_004b3830(0x20), iVar1 != 0)) {
    FUN_0040c790();
    while (((iVar1 = FUN_004b3830(0x11), iVar1 != 0 || (iVar1 = FUN_004b3830(0xd), iVar1 != 0)) ||
           (iVar1 = FUN_004b3830(0x20), iVar1 != 0))) {
      FUN_004baf80();
    }
    pfVar2 = local_80;
    FUN_00435a30(pfVar2);
    FUN_00435aa0(pfVar2);
  }
  iVar1 = FUN_004b3830(0x11);
  if (((iVar1 != 0) && (iVar1 = FUN_004b3830(0x46), iVar1 != 0)) &&
     (iVar1 = FUN_004b3830(0x49), iVar1 != 0)) {
    while (((iVar1 = FUN_004b3830(0x11), iVar1 != 0 || (iVar1 = FUN_004b3830(0x46), iVar1 != 0)) ||
           (iVar1 = FUN_004b3830(0x49), iVar1 != 0))) {
      FUN_004baf80();
    }
    FUN_0042f740(3);
  }
  iVar1 = FUN_004b3830(0x11);
  if (((iVar1 != 0) && (iVar1 = FUN_004b3830(0x57), iVar1 != 0)) &&
     (iVar1 = FUN_004b3830(0x46), iVar1 != 0)) {
    while (((iVar1 = FUN_004b3830(0x11), iVar1 != 0 || (iVar1 = FUN_004b3830(0x46), iVar1 != 0)) ||
           (iVar1 = FUN_004b3830(0x57), iVar1 != 0))) {
      FUN_004baf80();
    }
    DAT_0053a268 = DAT_0053a268 + 1 & 0x80000001;
    if ((int)DAT_0053a268 < 0) {
      DAT_0053a268 = (DAT_0053a268 - 1 | 0xfffffffe) + 1;
    }
    if (DAT_0053a268 == 1) {
      if (DAT_006a6284 == 2) goto LAB_00429fb7;
      DAT_006a6284 = 2;
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,8,2);
    }
    else if (DAT_0053a268 == 2) {
      if (DAT_006a6284 == 1) goto LAB_00429fb7;
      DAT_006a6284 = 1;
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,8,1);
    }
    else {
      if (DAT_006a6284 == 3) goto LAB_00429fb7;
      DAT_006a6284 = 3;
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,8,3);
    }
    if (iVar1 != 0) {
      uVar3 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FILL_MODE__error_setti_004e8950,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x1ce,uVar3);
    }
  }
LAB_00429fb7:
  iVar1 = FUN_004b3830(0x11);
  if (((iVar1 != 0) && (iVar1 = FUN_004b3830(0x45), iVar1 != 0)) &&
     (iVar1 = FUN_004b3830(0x4e), iVar1 != 0)) {
    while (((iVar1 = FUN_004b3830(0x11), iVar1 != 0 || (iVar1 = FUN_004b3830(0x45), iVar1 != 0)) ||
           (iVar1 = FUN_004b3830(0x4e), iVar1 != 0))) {
      FUN_004baf80();
    }
    while (iVar1 = FUN_004b3830(0x31), iVar1 == 0) {
      iVar1 = FUN_004b3830(0x32);
      if (iVar1 != 0) {
        DAT_0053be2c = 1;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x33);
      if (iVar1 != 0) {
        DAT_0053be2c = 2;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x34);
      if (iVar1 != 0) {
        DAT_0053be2c = 3;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x35);
      if (iVar1 != 0) {
        DAT_0053be2c = 4;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x36);
      if (iVar1 != 0) {
        DAT_0053be2c = 5;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x37);
      if (iVar1 != 0) {
        DAT_0053be2c = 6;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x38);
      if (iVar1 != 0) {
        DAT_0053be2c = 7;
        goto LAB_0042a108;
      }
      iVar1 = FUN_004b3830(0x39);
      if (iVar1 != 0) {
        DAT_0053be2c = 8;
        goto LAB_0042a108;
      }
      FUN_004baf80();
    }
    DAT_0053be2c = 0;
LAB_0042a108:
    while (((((((iVar1 = FUN_004b3830(0x11), iVar1 != 0 || (iVar1 = FUN_004b3830(0x31), iVar1 != 0))
               || (iVar1 = FUN_004b3830(0x32), iVar1 != 0)) ||
              ((iVar1 = FUN_004b3830(0x33), iVar1 != 0 || (iVar1 = FUN_004b3830(0x34), iVar1 != 0)))
              ) || ((iVar1 = FUN_004b3830(0x35), iVar1 != 0 ||
                    ((iVar1 = FUN_004b3830(0x36), iVar1 != 0 ||
                     (iVar1 = FUN_004b3830(0x37), iVar1 != 0)))))) ||
            (iVar1 = FUN_004b3830(0x38), iVar1 != 0)) || (iVar1 = FUN_004b3830(0x39), iVar1 != 0)))
    {
      FUN_004baf80();
    }
  }
  return;
}

