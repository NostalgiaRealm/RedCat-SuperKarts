/*
 * FUN_00430020 at 00430020
 * undefined FUN_00430020(void)
 * Address ranges: 00430020-0043046a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430020(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined4 auStack_d4 [8];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  int *piStack_ac;
  char *pcStack_a8;
  char *pcStack_a4;
  undefined8 uStack_a0;
  int *piStack_98;
  int *piStack_94;
  undefined4 auStack_44 [17];
  
  if (DAT_0053ba04 != 0) {
    piStack_94 = (int *)0x0;
    piStack_98 = (int *)0x4;
    uStack_a0 = (double)CONCAT44(DAT_006a64a4,0x430043);
    (**(code **)(*DAT_006a64a4 + 0x58))();
  }
  piStack_94 = (int *)0x3;
  if (DAT_0053b9f0 == 0) {
    piStack_98 = (int *)0x43005d;
    FUN_004ac7a0();
    piStack_94 = (int *)0x430065;
    FUN_004272c0();
  }
  else {
    piStack_98 = (int *)0x430053;
    FUN_004ac7a0();
  }
  piStack_94 = DAT_006a621c;
  piStack_98 = (int *)0x430070;
  piStack_98 = (int *)(**(code **)(*DAT_006a621c + 0x28))();
  if (piStack_98 != (int *)0x0) {
    uStack_a0 = (double)CONCAT44(0x43007a,(undefined4)uStack_a0);
    uVar1 = FUN_004aaa00();
    uStack_a0 = (double)CONCAT44(uVar1,0x3fc);
    pcStack_a4 = s_D__work_rcsk_Code_game_Gm_main_c_004eafc0;
    pcStack_a8 = s__s__d____D3DError_Begin_Scene_____004eafe4;
    piStack_ac = (int *)0x43008f;
    FUN_004afee0();
  }
  if (DAT_0053b9f0 == 0) {
    iVar2 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(undefined4 *)(iVar2 + 0x60) = 0;
    uVar1 = *DAT_006a5e80;
    *(undefined4 *)(iVar2 + 0x58) = 1;
    *(undefined4 *)(iVar2 + 0x48) = uVar1;
    if (*(int *)(iVar2 + 0x5c) == 1) {
      piStack_98 = (int *)0x4300cb;
      FUN_00423930();
    }
    if (DAT_006a6254 != 0) {
      DAT_006a6254 = 0;
      piStack_98 = (int *)*DAT_006a5e80;
      uStack_a0 = (double)CONCAT44(1,DAT_006a621c);
      pcStack_a4 = (char *)0x4300ee;
      piStack_98 = (int *)(**(code **)(*DAT_006a621c + 0x5c))();
      if (piStack_98 != (int *)0x0) {
        uStack_a0 = (double)CONCAT44(0x4300f8,(undefined4)uStack_a0);
        uVar1 = FUN_004aaa00();
        uStack_a0 = (double)CONCAT44(uVar1,0x122);
        pcStack_a4 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
        pcStack_a8 = s__s__d_____TEXTURE__error_setting_004e5fe4;
        piStack_ac = (int *)0x43010d;
        FUN_004afee0();
      }
    }
  }
  piStack_98 = (int *)DAT_0053b9d0;
  uStack_a0 = 4.24616112151237e-314;
  uVar1 = FUN_004304d0();
  uStack_a0 = (double)CONCAT44(uVar1,0x43012b);
  FUN_004971f0();
  piStack_98 = (int *)0x430130;
  FUN_00423010();
  if (DAT_0053b9f0 == 0) {
    iVar2 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(undefined4 *)(iVar2 + 0x60) = 0;
    *(undefined4 *)(iVar2 + 0x48) = *DAT_006a5e80;
    *(undefined4 *)(iVar2 + 0x58) = 1;
    if (*(int *)(iVar2 + 0x5c) == 1) {
      piStack_98 = (int *)0x430163;
      FUN_00423930();
    }
    if (DAT_006a6254 != 0) {
      DAT_006a6254 = 0;
      piStack_98 = (int *)*DAT_006a5e80;
      uStack_a0 = (double)CONCAT44(1,DAT_006a621c);
      pcStack_a4 = (char *)0x430186;
      piStack_98 = (int *)(**(code **)(*DAT_006a621c + 0x5c))();
      if (piStack_98 != (int *)0x0) {
        uStack_a0 = (double)CONCAT44(0x430190,(undefined4)uStack_a0);
        uVar1 = FUN_004aaa00();
        uStack_a0 = (double)CONCAT44(uVar1,0x122);
        pcStack_a4 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
        pcStack_a8 = s__s__d_____TEXTURE__error_setting_004e5fe4;
        piStack_ac = (int *)0x4301a5;
        FUN_004afee0();
      }
    }
  }
  piStack_98 = (int *)0x1;
  uStack_a0 = (double)CONCAT44(DAT_0053b9d4,DAT_0053b9d0);
  pcStack_a4 = (char *)0x2;
  pcStack_a8 = (char *)0x4301bd;
  pcStack_a4 = (char *)FUN_004304d0();
  pcStack_a8 = (char *)0x4301c6;
  FUN_00491670();
  if (DAT_0053b9f0 != 0) {
    piStack_98 = (int *)0x4301d7;
    FUN_00426e50();
  }
  piStack_98 = (int *)0x4301dc;
  FUN_00486370();
  piStack_98 = (int *)0x4301e3;
  FUN_00486420();
  piStack_98 = (int *)0x4301e8;
  FUN_00488a90();
  piStack_98 = (int *)0x4301ef;
  FUN_00488b40();
  piStack_98 = (int *)0x4301f4;
  FUN_0048a480();
  piStack_98 = (int *)0x4301fb;
  FUN_0048a530();
  piStack_98 = (int *)0x430200;
  FUN_00487950();
  piStack_98 = (int *)0x430207;
  FUN_00487aa0();
  piStack_98 = (int *)0x43020c;
  FUN_00485690();
  piStack_98 = (int *)0x430213;
  FUN_00485710();
  piStack_98 = (int *)0x430218;
  FUN_0048da90();
  piStack_98 = (int *)0x43021f;
  FUN_0048db30();
  piStack_98 = (int *)0x430224;
  FUN_00428a00();
  piStack_98 = (int *)0x430229;
  FUN_004235c0();
  if (DAT_0053b9f0 != 0) {
    puVar3 = (undefined4 *)
             (DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x10);
    puVar4 = auStack_d4;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_00482190();
  }
  if ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1) {
    puVar3 = &DAT_006a615c;
    puVar4 = auStack_44;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    piStack_98 = (int *)0x3;
    puVar3 = auStack_44;
    puVar4 = (undefined4 *)&stack0xffffff7c;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    uStack_a0 = (double)CONCAT44(0x16,DAT_006a621c);
    pcStack_a4 = (char *)0x4302d8;
    (**(code **)(*DAT_006a621c + 0x5c))();
    pcStack_a4 = (char *)&DAT_006a615c;
    puVar3 = (undefined4 *)&stack0xffffff70;
    puVar4 = &DAT_006a615c;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    pcStack_a8 = (char *)0x3;
    piStack_ac = DAT_006a621c;
    uStack_b0 = 0x4302fa;
    piStack_98 = (int *)(**(code **)(*DAT_006a621c + 0x68))();
    if (piStack_98 != (int *)0x0) {
      uStack_a0 = (double)CONCAT44(0x430304,(undefined4)uStack_a0);
      uVar1 = FUN_004aaa00();
      uStack_a0 = (double)CONCAT44(uVar1,0x59);
      pcStack_a4 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_a8 = s__s__d_____FOG__error_setting_tra_004e300c;
      piStack_ac = (int *)0x430316;
      FUN_004afee0();
    }
  }
  piStack_98 = (int *)0x430323;
  FUN_00467d30();
  if ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1) {
    puVar3 = &DAT_006a615c;
    puVar4 = auStack_44;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    piStack_98 = (int *)0x2;
    puVar3 = auStack_44;
    puVar4 = (undefined4 *)&stack0xffffff7c;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    uStack_a0 = (double)CONCAT44(0x16,DAT_006a621c);
    pcStack_a4 = (char *)0x430387;
    (**(code **)(*DAT_006a621c + 0x5c))();
    pcStack_a4 = (char *)&DAT_006a615c;
    puVar3 = (undefined4 *)&stack0xffffff70;
    puVar4 = &DAT_006a615c;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    pcStack_a8 = (char *)0x3;
    piStack_ac = DAT_006a621c;
    uStack_b0 = 0x4303a9;
    piStack_98 = (int *)(**(code **)(*DAT_006a621c + 0x68))();
    if (piStack_98 != (int *)0x0) {
      uStack_a0 = (double)CONCAT44(0x4303b3,(undefined4)uStack_a0);
      uVar1 = FUN_004aaa00();
      uStack_a0 = (double)CONCAT44(uVar1,0x59);
      pcStack_a4 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_a8 = s__s__d_____FOG__error_setting_tra_004e300c;
      piStack_ac = (int *)0x4303c5;
      FUN_004afee0();
    }
  }
  piStack_98 = DAT_006a621c;
  uStack_a0 = (double)CONCAT44(0x4303d3,(undefined4)uStack_a0);
  iVar2 = (**(code **)(*DAT_006a621c + 0x2c))();
  if (iVar2 != 0) {
    uStack_a0._0_4_ = 0x4303dd;
    uStack_a0._4_4_ = iVar2;
    uVar1 = FUN_004aaa00();
    uStack_a0 = (double)CONCAT44(uStack_a0._4_4_,uVar1);
    pcStack_a4 = (char *)0x443;
    pcStack_a8 = s_D__work_rcsk_Code_game_Gm_main_c_004eb00c;
    piStack_ac = (int *)s__s__d____D3DError_End_Scene____s_004eb030;
    uStack_b0 = 0x4303f2;
    FUN_004afee0();
  }
  if (DAT_0053ba6c != 0) {
    uStack_a0 = 2.61007652195401e-312;
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      uStack_a0 = (double)CONCAT44(0x430415,(undefined4)uStack_a0);
      fVar5 = (float10)FUN_0048f4e0();
      uStack_a0 = (double)((float10)1.0 / fVar5);
      pcStack_a4 = s_frameRate___f_004eb054;
      pcStack_a8 = (char *)0x50;
      piStack_ac = (int *)0xa;
      uStack_b0 = 0x43042f;
      uStack_b0 = FUN_00429210();
      uStack_b4 = 0x430435;
      FUN_004b1850();
      uStack_a0 = (double)CONCAT44(DAT_0053b9d0,s_vchunks___d_004eb064);
      pcStack_a4 = (char *)0x64;
      pcStack_a8 = (char *)0xa;
      piStack_ac = (int *)0x43044d;
      piStack_ac = (int *)FUN_00429210();
      uStack_b0 = 0x430453;
      FUN_004b1850();
    }
  }
  uStack_a0 = (double)CONCAT44(0x430460,(undefined4)uStack_a0);
  FUN_0048ef80();
  return;
}

