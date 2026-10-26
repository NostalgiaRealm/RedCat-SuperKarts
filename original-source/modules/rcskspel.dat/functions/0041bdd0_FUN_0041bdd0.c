/*
 * FUN_0041bdd0 at 0041bdd0
 * undefined FUN_0041bdd0(void)
 * Address ranges: 0041bdd0-0041c0a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bdd0(int param_1,int param_2)

{
  int iVar1;
  float local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_1 < 0) || (8 < param_1)) {
    FUN_004afee0(s__s__d____Illegal_car_type___d__004e2a4c,
                 s_D__work_rcsk_Code_game_car_whl_C_004e2a28,0x122,param_1);
  }
  iVar1 = *(int *)(param_2 * 0xd0 + 0xc + DAT_0067ee20);
  FUN_0041bb30(param_1,&local_54,&local_48);
  uStack_2c = uStack_50;
  uStack_8 = uStack_50;
  uStack_1c = uStack_40;
  uStack_10 = uStack_40;
  uStack_28 = uStack_4c;
  uStack_4 = uStack_4c;
  uStack_20 = uStack_44;
  fStack_18 = local_48;
  uStack_14 = uStack_44;
  uStack_3c = 0;
  uStack_38 = 0;
  iVar1 = iVar1 * 0xa9;
  uStack_34 = 0;
  fStack_30 = -local_54;
  fStack_24 = -local_48;
  FUN_00492620(param_2,*(undefined4 *)(iVar1 + 4 + DAT_006a5c38),1,fStack_30,uStack_50,uStack_4c,0,0
               ,0);
  fStack_30 = 0.0;
  uStack_2c = 0;
  uStack_28 = 0;
  FUN_00492620(param_2,*(undefined4 *)(iVar1 + 4 + DAT_006a5c38),1,local_54,uStack_8,uStack_4,0,0,0)
  ;
  fStack_30 = 0.0;
  uStack_2c = 0;
  uStack_28 = 0;
  FUN_00492620(param_2,*(undefined4 *)(iVar1 + 4 + DAT_006a5c38),2,fStack_24,uStack_20,uStack_1c,0,0
               ,0);
  fStack_24 = 0.0;
  uStack_20 = 0;
  uStack_1c = 0;
  FUN_00492620(param_2,*(undefined4 *)(iVar1 + 4 + DAT_006a5c38),2,fStack_18,uStack_14,uStack_10,0,0
               ,0);
  FUN_004906b0(0);
  FUN_004a09e0();
  FUN_004906b0(1);
  FUN_004a09e0();
  FUN_004906b0(2);
  FUN_004a09e0();
  FUN_004906b0(3);
  FUN_004a09e0();
  return;
}

