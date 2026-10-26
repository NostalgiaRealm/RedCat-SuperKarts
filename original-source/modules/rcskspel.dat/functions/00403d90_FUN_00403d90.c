/*
 * FUN_00403d90 at 00403d90
 * undefined FUN_00403d90(void)
 * Address ranges: 00403d90-00404121
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403d90(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (DAT_004dda34 == -1) {
    DAT_004dda34 = FUN_00440e50();
  }
  iVar2 = DAT_00504fa0;
  if (DAT_00504fa4 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s____Libs_win3dlib_Include_array_h_004de7b4,0xb9,&DAT_00504fac,DAT_00504f9c,
                 &DAT_00504fc5);
    iVar2 = DAT_00504fa0;
  }
  for (; iVar2 < DAT_00504f9c; iVar2 = iVar2 + 1) {
    if (*(char *)(DAT_00504fa8 + iVar2) == '\0') goto LAB_00403f05;
  }
  iVar2 = 0;
  if (0 < DAT_00504fa0) {
    do {
      if (*(char *)(DAT_00504fa8 + iVar2) == '\0') goto LAB_00403f05;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00504fa0);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s____Libs_win3dlib_Include_array_h_004de7b4,0xce,&DAT_00504fac,DAT_00504f9c,
               &DAT_00504fc5);
  iVar2 = -1;
LAB_00403e3b:
  iVar3 = iVar2 * 0x6c;
  *(undefined4 *)(iVar3 + 0x5c + DAT_00504f98) = 0x3f800000;
  iVar4 = param_1 * 0xd0;
  uStack_4 = 8;
  iVar1 = *(int *)(iVar4 + 0x38 + DAT_0067ee20);
  if ((iVar1 != 1) && (iVar1 != 0)) {
    FUN_004afee0(s__s__d___obj_side__d_____d_is_ill_004dda94,
                 s_D__work_rcsk_Code_game_ai_main_C_004dda70,0x2fc,param_1,iVar1);
  }
  if (*(int *)(iVar4 + 0x38 + DAT_0067ee20) == 1) {
    uStack_8 = 0x12;
  }
  if (*(int *)(iVar4 + 0x38 + DAT_0067ee20) == 0) {
    uStack_8 = 0x28;
  }
  FUN_004afce0(s_Adding_ai_to_object__d__at_waypo_004ddabc,param_1,param_3,iVar2,param_2);
  *(int *)(iVar3 + 0x24 + DAT_00504f98) = param_2;
  *(undefined4 *)(iVar3 + DAT_00504f98) = param_3;
  *(undefined4 *)(iVar3 + 4 + DAT_00504f98) = param_3;
  if (param_2 == 0) {
    *(undefined4 *)(iVar3 + 0x18 + DAT_00504f98) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 0x18 + DAT_00504f98) = 0x43fa0000;
  }
  *(undefined4 *)(iVar3 + 0x20 + DAT_00504f98) = 0xf;
  FUN_004afce0(s_bh_top_speed_p_behavior_____f__004ddb04,
               (double)*(float *)(param_2 * 0x2c + 0x14 + DAT_00504fe0));
  *(undefined4 *)(iVar3 + 0x1c + DAT_00504f98) =
       *(undefined4 *)(param_2 * 0x2c + 0x14 + DAT_00504fe0);
  FUN_004afce0(s_ai_chosen_speed_l_ai_____f__004ddb24,
               (double)*(float *)(iVar3 + 0x1c + DAT_00504f98));
  *(undefined4 *)(iVar3 + 0x14 + DAT_00504f98) = param_4;
  *(undefined4 *)(iVar3 + 0x10 + DAT_00504f98) = 10;
  *(undefined4 *)(iVar3 + 8 + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0xc + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x2c + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x30 + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x34 + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x38 + DAT_00504f98) = 1;
  *(undefined4 *)(iVar3 + 0x40 + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x3c + DAT_00504f98) = 2;
  *(int *)(iVar4 + 0x10 + DAT_0067ee20) = iVar2;
  *(undefined4 *)(iVar4 + 0x48 + DAT_0067ee20) = 1;
  if ((1 < param_2) && (param_2 < 6)) {
    FUN_004057f0(param_1,&uStack_4,&uStack_8);
    FUN_00405380(iVar2,*(undefined4 *)(iVar4 + 0x38 + DAT_0067ee20),uStack_4);
    FUN_00405380(iVar2,*(undefined4 *)(iVar4 + 0x38 + DAT_0067ee20),uStack_8);
    iVar2 = iVar3 + DAT_00504f98;
    iVar1 = FUN_004be6c9();
    *(float *)(iVar2 + 0x5c) = (float)iVar1 * 3.051851e-05 * 0.2 + 0.9;
  }
  *(undefined4 *)(iVar3 + 0x44 + DAT_00504f98) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x48 + DAT_00504f98) = *(undefined4 *)(iVar4 + 0x18 + DAT_0067ee20);
  *(undefined4 *)(iVar3 + 0x4c + DAT_00504f98) = 1;
  *(undefined4 *)(iVar3 + 0x50 + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x54 + DAT_00504f98) = 0;
  *(undefined4 *)(iVar3 + 0x58 + DAT_00504f98) = 0;
  *(int *)(iVar3 + 0x60 + DAT_00504f98) = *(int *)(iVar4 + 0x1c + DAT_0067ee20) - DAT_004dda34;
  *(undefined4 *)(iVar3 + 100 + DAT_00504f98) = *(undefined4 *)(iVar4 + 0x1c + DAT_0067ee20);
  *(undefined4 *)(iVar3 + 0x68 + DAT_00504f98) = 0;
  return;
LAB_00403f05:
  *(undefined1 *)(DAT_00504fa8 + iVar2) = 1;
  DAT_00504fa0 = iVar2;
  goto LAB_00403e3b;
}

