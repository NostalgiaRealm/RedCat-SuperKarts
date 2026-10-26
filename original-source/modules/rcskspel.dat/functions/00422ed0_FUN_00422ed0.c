/*
 * FUN_00422ed0 at 00422ed0
 * undefined FUN_00422ed0(void)
 * Address ranges: 00422ed0-00423002
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00422ed0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_0053b9f0 != 0) {
    FUN_00422d50(DAT_0050912c,DAT_00509128);
    if (DAT_0053ba00 != 0) {
      uVar1 = FUN_004be6c9();
      if ((uVar1 & 1) != 0) {
        if (DAT_0053ba00 != 2) {
          if (DAT_006a6264 != 7) {
            DAT_006a6264 = 7;
            iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x15,7);
            if (iVar2 != 0) {
              uVar3 = FUN_004aaa00(iVar2);
              FUN_004afee0(s__s__d_____BLENDING__error_settin_004e5f5c,
                           s____Libs_win3dlib_Include_d3dev_i_004e3040,0x235,uVar3);
            }
          }
          FUN_004b1d60(s__game_ini_004e5f07 + 1);
          iVar2 = FUN_004b1ed0(s_options_004e5f1c,s_FILTER_004e5f14);
          if ((iVar2 == 2) && (DAT_006a6274 != 2)) {
            DAT_006a6274 = 2;
            iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,2);
            if (iVar2 != 0) {
              uVar3 = FUN_004aaa00(iVar2);
              FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                           s____Libs_win3dlib_Include_d3dev_i_004e3040,0x169,uVar3);
            }
            iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,2);
            if (iVar2 != 0) {
              uVar3 = FUN_004aaa00(iVar2);
              FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                           s____Libs_win3dlib_Include_d3dev_i_004e3040,0x16c,uVar3);
            }
          }
        }
        FUN_00441210();
      }
    }
    DAT_00509154 = 1;
  }
  return;
}

