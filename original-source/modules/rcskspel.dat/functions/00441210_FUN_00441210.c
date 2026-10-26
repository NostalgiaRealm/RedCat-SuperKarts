/*
 * FUN_00441210 at 00441210
 * undefined FUN_00441210(void)
 * Address ranges: 00441210-00441538
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441210(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcStack_54;
  char *pcStack_50;
  int *piStack_4c;
  char *pcStack_48;
  char *pcStack_44;
  int *piStack_40;
  char *pcStack_3c;
  char *pcStack_38;
  int *piStack_34;
  char *pcStack_30;
  char *pcStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  int *piStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (DAT_0053b9f0 != 0) {
    DAT_006a623c = 1;
    uStack_14 = 1;
    uStack_18 = 0x1c;
    piStack_1c = DAT_006a621c;
    uStack_20 = 0x441239;
    uStack_20 = (**(code **)(*DAT_006a621c + 0x5c))();
    if (uStack_20 != 0) {
      uStack_24 = 0x441243;
      uStack_24 = FUN_004aaa00();
      piStack_28 = (int *)0xf0;
      pcStack_2c = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_30 = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_34 = (int *)0x441258;
      FUN_004afee0();
    }
    uStack_20 = DAT_006a6240;
    uStack_24 = 0x22;
    piStack_28 = DAT_006a621c;
    pcStack_2c = (char *)0x44126f;
    pcStack_2c = (char *)(**(code **)(*DAT_006a621c + 0x5c))();
    if (pcStack_2c != (char *)0x0) {
      pcStack_30 = (char *)0x441279;
      pcStack_30 = (char *)FUN_004aaa00();
      piStack_34 = (int *)0xf3;
      pcStack_38 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_3c = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_40 = (int *)0x44128e;
      FUN_004afee0();
    }
    pcStack_2c = (char *)DAT_006a6248;
    pcStack_30 = (char *)0x7;
    piStack_34 = DAT_006a621c;
    pcStack_38 = (char *)0x4412a5;
    pcStack_38 = (char *)(**(code **)(*DAT_006a621c + 100))();
    if (pcStack_38 != (char *)0x0) {
      pcStack_3c = (char *)0x4412af;
      pcStack_3c = (char *)FUN_004aaa00();
      piStack_40 = (int *)0xf6;
      pcStack_44 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_48 = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_4c = (int *)0x4412c4;
      FUN_004afee0();
    }
    pcStack_38 = (char *)DAT_006a624c;
    pcStack_3c = (char *)0x5;
    piStack_40 = DAT_006a621c;
    pcStack_44 = (char *)0x4412db;
    pcStack_44 = (char *)(**(code **)(*DAT_006a621c + 100))();
    if (pcStack_44 != (char *)0x0) {
      pcStack_48 = (char *)0x4412e5;
      pcStack_48 = (char *)FUN_004aaa00();
      piStack_4c = (int *)0xf9;
      pcStack_50 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_54 = s__s__d_____FOG__error_setting_ren_004e3adc;
      FUN_004afee0();
    }
    pcStack_44 = (char *)DAT_006a6250;
    pcStack_48 = (char *)0x6;
    piStack_4c = DAT_006a621c;
    pcStack_50 = (char *)0x441311;
    pcStack_50 = (char *)(**(code **)(*DAT_006a621c + 100))();
    if (pcStack_50 != (char *)0x0) {
      pcStack_54 = (char *)0x44131b;
      pcStack_54 = (char *)FUN_004aaa00();
      FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0xfc);
    }
    pcStack_50 = (char *)DAT_006a6244;
    pcStack_54 = (char *)0x4;
    iVar1 = (**(code **)(*DAT_006a621c + 100))(DAT_006a621c);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0xff,uVar2);
    }
    pcStack_54 = (char *)((float)((int)DAT_006a6240 >> 0x10) * 0.003921569);
    pcStack_50 = (char *)((float)((int)DAT_006a6240 >> 8 & 0xff) * 0.003921569);
    piStack_4c = (int *)((float)(DAT_006a6240 & 0xff) * 0.003921569);
    FUN_004418e0(&pcStack_54);
    FUN_004418a0(&pcStack_54);
    iVar1 = *(int *)(DAT_006a6290 + DAT_004fda00 * 4);
    *(undefined4 *)(iVar1 + 0x4c) = 1;
    *(undefined4 *)(iVar1 + 0x58) = 1;
    FUN_00423930();
    FUN_00441810(*(undefined4 *)(iVar1 + 0x50));
    DAT_006a6240 = 0xb4b4c8;
    if (DAT_006a623c != 0) {
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x22,0xb4b4c8);
      if (iVar1 != 0) {
        uVar2 = FUN_004aaa00(iVar1);
        FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x7a,uVar2);
      }
      pcStack_54 = (char *)((float)((int)DAT_006a6240 >> 0x10) * 0.003921569);
      pcStack_50 = (char *)((float)((int)DAT_006a6240 >> 8 & 0xff) * 0.003921569);
      piStack_4c = (int *)((float)(DAT_006a6240 & 0xff) * 0.003921569);
      FUN_004418e0(&pcStack_54);
      FUN_004418a0(&pcStack_54);
    }
    DAT_006a624c = 0x40600000;
    if (DAT_006a623c != 0) {
      iVar1 = (**(code **)(*DAT_006a621c + 100))(DAT_006a621c,5,0x40600000);
      if (iVar1 != 0) {
        uVar2 = FUN_004aaa00(iVar1);
        FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0xa8,uVar2);
      }
    }
    FUN_00441920(0x447a0000);
  }
  return;
}

