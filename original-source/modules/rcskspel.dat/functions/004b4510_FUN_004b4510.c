/*
 * FUN_004b4510 at 004b4510
 * undefined FUN_004b4510(void)
 * Address ranges: 004b4510-004b47b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b4510(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  FUN_004b3bc0();
  if (DAT_006ab7b4 != 0) {
    return 0;
  }
  if (DAT_006ab7b8 == 0) {
    if (DAT_00500160 == -1) {
      if (DAT_00500164 == -1) {
        FUN_004afce0(s_Using_default_driver_00500780);
        iVar1 = DirectSoundCreate(0,&DAT_006ab788,0);
        if (iVar1 != 0) {
          uVar2 = FUN_004b3910(iVar1);
          uVar3 = 0x34c;
          goto LAB_004b4614;
        }
        pcVar4 = s_Default_driver_init_failure___No_0050072c;
      }
      else {
        FUN_004afce0(s_Attempting_to_use_secondary_driv_005007d0);
        iVar1 = DirectSoundCreate(DAT_006ab794 + DAT_00500164 * 0xd8,&DAT_006ab788,0);
        if (iVar1 != 0) {
          uVar2 = FUN_004b3910(iVar1);
          uVar3 = 0x344;
LAB_004b4614:
          FUN_004afce0(s__s__d____error_creating_sound_ob_00500754,
                       s_C__libraries_dxdraw_Sound_cpp_00500494,uVar3,uVar2);
          return 0x2af9;
        }
        pcVar4 = s_Attempting_to_use_secondary__unk_00500798;
      }
    }
    else {
      FUN_004afce0(s_Attempting_to_use_sb16_driver_00500820);
      iVar1 = DirectSoundCreate(DAT_006ab794 + DAT_00500160 * 0xd8,&DAT_006ab788,0);
      if (iVar1 != 0) {
        uVar2 = FUN_004b3910(iVar1);
        uVar3 = 0x33b;
        goto LAB_004b4614;
      }
      pcVar4 = s_Attempting_to_use_sb16_driver_su_005007f4;
    }
    DAT_006ab7b8 = 1;
    FUN_004afce0(pcVar4);
  }
  if (DAT_006ab7bc == 0) {
    iVar1 = (**(code **)(*DAT_006ab788 + 0x18))(DAT_006ab788,DAT_006a64b4,3);
    if (iVar1 != 0) {
      uVar2 = FUN_004b3910(1);
      FUN_004afce0(s__s__d____error_setting_the_coop_l_005006fc,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x357,uVar2);
      return 0x2af9;
    }
    DAT_006ab7bc = 1;
  }
  if (DAT_006ab7c0 == 0) {
    DAT_006ab798 = LocalAlloc(0x40,param_1 * 0x44);
    if (DAT_006ab798 == (HLOCAL)0x0) {
      FUN_004afee0(s__s__d____not_enough_memory_to_cr_005006c4,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x35f);
    }
    DAT_006ab7c0 = 1;
  }
  DAT_006ab78c = param_1;
  if (0 < param_1) {
    iVar1 = 0;
    do {
      param_1 = param_1 + -1;
      *(undefined4 *)(iVar1 + 0x30 + (int)DAT_006ab798) = 0;
      *(undefined4 *)(iVar1 + 0x38 + (int)DAT_006ab798) = 0;
      *(undefined4 *)(iVar1 + 0x34 + (int)DAT_006ab798) = 0;
      *(undefined4 *)(iVar1 + 0x40 + (int)DAT_006ab798) = 0xffffffff;
      iVar1 = iVar1 + 0x44;
    } while (param_1 != 0);
  }
  if ((((-1 < param_2) && (param_2 < 0xe)) ||
      (FUN_004afee0(s__s__d____error_illegal_sound_mod_00500694), param_2 != 0xe)) &&
     (DAT_006ab7c4 == 0)) {
    param_2 = param_2 * 0x10;
    iVar1 = FUN_004b3be0(*(undefined4 *)(&DAT_00500080 + param_2),
                         *(undefined4 *)(&DAT_00500084 + param_2),
                         *(undefined4 *)(&DAT_0050008c + param_2),
                         *(undefined4 *)(&DAT_00500088 + param_2));
    if (iVar1 != 0) {
      return 0x2afa;
    }
    pcVar4 = s_STEREO_0050068c;
    if (*(int *)(&DAT_00500088 + param_2) == 0) {
      pcVar4 = &DAT_00500684;
    }
    FUN_004afce0(s_setting_sound_format__dHz__dbits_0050065c,
                 *(undefined4 *)(&DAT_00500080 + param_2),*(undefined4 *)(&DAT_00500084 + param_2),
                 pcVar4);
    DAT_006ab7c4 = 1;
  }
  DAT_006ab7b4 = 1;
  return 0;
}

