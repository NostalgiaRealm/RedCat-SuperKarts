/*
 * FUN_00440f60 at 00440f60
 * undefined FUN_00440f60(void)
 * Address ranges: 00440f60-00441201
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440f60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piStack_54;
  char *pcStack_50;
  char *pcStack_4c;
  int *piStack_48;
  char *pcStack_44;
  char *pcStack_40;
  int *piStack_3c;
  char *pcStack_38;
  char *pcStack_34;
  int *piStack_30;
  char *pcStack_2c;
  char *pcStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  int *piStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (DAT_0053be28 == param_1) {
    DAT_006a623c = 0;
    uStack_10 = 0;
    uStack_14 = 0x1c;
    piStack_18 = DAT_006a621c;
    uStack_1c = 0x440f8d;
    uStack_1c = (**(code **)(*DAT_006a621c + 0x5c))();
    if (uStack_1c != 0) {
      uStack_20 = 0x440f97;
      uStack_20 = FUN_004aaa00();
      piStack_24 = (int *)0xf0;
      pcStack_28 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_2c = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_30 = (int *)0x440fac;
      FUN_004afee0();
    }
    uStack_1c = DAT_006a6240;
    uStack_20 = 0x22;
    piStack_24 = DAT_006a621c;
    pcStack_28 = (char *)0x440fc3;
    pcStack_28 = (char *)(**(code **)(*DAT_006a621c + 0x5c))();
    if (pcStack_28 != (char *)0x0) {
      pcStack_2c = (char *)0x440fcd;
      pcStack_2c = (char *)FUN_004aaa00();
      piStack_30 = (int *)0xf3;
      pcStack_34 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_38 = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_3c = (int *)0x440fe2;
      FUN_004afee0();
    }
    pcStack_28 = (char *)DAT_006a6248;
    pcStack_2c = (char *)0x7;
    piStack_30 = DAT_006a621c;
    pcStack_34 = (char *)0x440ff9;
    pcStack_34 = (char *)(**(code **)(*DAT_006a621c + 100))();
    if (pcStack_34 != (char *)0x0) {
      pcStack_38 = (char *)0x441003;
      pcStack_38 = (char *)FUN_004aaa00();
      piStack_3c = (int *)0xf6;
      pcStack_40 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_44 = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_48 = (int *)0x441018;
      FUN_004afee0();
    }
    pcStack_34 = (char *)DAT_006a624c;
    pcStack_38 = (char *)0x5;
    piStack_3c = DAT_006a621c;
    pcStack_40 = (char *)0x44102f;
    pcStack_40 = (char *)(**(code **)(*DAT_006a621c + 100))();
    if (pcStack_40 != (char *)0x0) {
      pcStack_44 = (char *)0x441039;
      pcStack_44 = (char *)FUN_004aaa00();
      piStack_48 = (int *)0xf9;
      pcStack_4c = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      pcStack_50 = s__s__d_____FOG__error_setting_ren_004e3adc;
      piStack_54 = (int *)0x44104e;
      FUN_004afee0();
    }
    pcStack_40 = (char *)DAT_006a6250;
    pcStack_44 = (char *)0x6;
    piStack_48 = DAT_006a621c;
    pcStack_4c = (char *)0x441065;
    pcStack_4c = (char *)(**(code **)(*DAT_006a621c + 100))();
    if (pcStack_4c != (char *)0x0) {
      pcStack_50 = (char *)0x44106f;
      pcStack_50 = (char *)FUN_004aaa00();
      piStack_54 = (int *)0xfc;
      FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040);
    }
    pcStack_4c = (char *)DAT_006a6244;
    pcStack_50 = (char *)0x4;
    piStack_54 = DAT_006a621c;
    iVar1 = (**(code **)(*DAT_006a621c + 100))();
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0xff,uVar2);
    }
    if (DAT_004fdee4 != -1) {
      FUN_00441840(DAT_006a62f0);
    }
    DAT_006a6240 = 0xc8c8ff;
    if (DAT_006a623c != 0) {
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x22,0xc8c8ff);
      if (iVar1 != 0) {
        uVar2 = FUN_004aaa00(iVar1);
        FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x7a,uVar2);
      }
      pcStack_44 = (char *)(DAT_006a6240 & 0xff);
      piStack_54 = (int *)((float)((int)DAT_006a6240 >> 0x10) * 0.003921569);
      pcStack_50 = (char *)((float)((int)DAT_006a6240 >> 8 & 0xff) * 0.003921569);
      pcStack_4c = (char *)((float)(int)pcStack_44 * 0.003921569);
      FUN_004418e0(&piStack_54);
      FUN_004418a0(&piStack_54);
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
    DAT_0053d1e0 = 0;
  }
  return;
}

