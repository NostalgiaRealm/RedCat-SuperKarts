/*
 * FUN_00418c80 at 00418c80
 * undefined FUN_00418c80(void)
 * Address ranges: 00418c80-00418d64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00418c80(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[1] != 0) {
    FUN_0049dd20(param_1[2]);
    iVar1 = FUN_0049d870();
    if (iVar1 == 0) {
      if ((param_2 < 0) || (*param_1 <= param_2)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      FUN_00492fe0(uVar2,s__s___d__Invalid_gear_given__Nr__o_004e1798,
                   s_D__work_rcsk_Code_game_car_snd_c_004e1774,0x1ee,*param_1,param_2);
      if (param_1[4] == -1) {
        FUN_00418c50();
      }
      iVar1 = param_1[4];
      if (param_2 != iVar1) {
        if ((-1 < iVar1) && (iVar1 < *param_1)) {
          uVar2 = 0;
          FUN_0049dd20(param_1[3]);
          FUN_0049d780(uVar2);
        }
        FUN_00418750(param_2,param_3);
      }
      FUN_004189d0(param_1[9],param_1 + 10,param_3,param_2);
      FUN_004189d0(param_1[0xc],param_1 + 0xd,param_3,param_2);
      FUN_004189d0(param_1[0xf],param_1 + 0x10,param_3,param_2);
      FUN_00418ad0(param_3,param_2);
      param_1[4] = param_2;
    }
  }
  return;
}

