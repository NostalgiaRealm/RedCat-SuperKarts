/*
 * FUN_0042cff0 at 0042cff0
 * undefined FUN_0042cff0(void)
 * Address ranges: 0042cff0-0042d1c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042cff0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  FUN_004afce0(s_set_game_render_states_004ea5b0);
  if (DAT_0053b9f0 == 0) {
    if (DAT_006a6264 != 7) {
      DAT_006a6264 = 7;
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x15,7);
      goto joined_r0x0042d052;
    }
  }
  else if (DAT_006a6264 != 2) {
    DAT_006a6264 = 2;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x15,2);
joined_r0x0042d052:
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____BLENDING__error_settin_004e5f5c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x235,uVar2);
    }
  }
  FUN_004b1d60(s_game_ini_004ea5c8);
  iVar1 = FUN_004b1ed0(s_OPTIONS_004ea5dc,s_FILTER_004ea5d4);
  if (iVar1 == 2) {
    if (DAT_0053b9f0 == 0) {
      return;
    }
    if (DAT_006a6274 == 2) goto LAB_0042d17a;
    DAT_006a6274 = 2;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,2);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x169,uVar2);
    }
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,2);
    if (iVar1 == 0) goto LAB_0042d17a;
    uVar2 = FUN_004aaa00(iVar1);
    uVar3 = 0x16c;
  }
  else {
    if (DAT_006a6274 == 0) goto LAB_0042d17a;
    DAT_006a6274 = 0;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,1);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x162,uVar2);
    }
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,1);
    if (iVar1 == 0) goto LAB_0042d17a;
    uVar2 = FUN_004aaa00(iVar1);
    uVar3 = 0x165;
  }
  FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
               s____Libs_win3dlib_Include_d3dev_i_004e3040,uVar3,uVar2);
LAB_0042d17a:
  if ((DAT_0053b9f0 != 0) && (DAT_006a6280 != 2)) {
    DAT_006a6280 = 2;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,9,2);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____SHADE_MODE__error_sett_004eab8c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x1ba,uVar2);
    }
  }
  return;
}

