/*
 * FUN_0042ce10 at 0042ce10
 * undefined FUN_0042ce10(void)
 * Address ranges: 0042ce10-0042cfef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ce10(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char local_5c [4];
  char local_58 [4];
  char local_54 [4];
  char local_50 [4];
  char local_4c [4];
  char local_48 [4];
  char local_44;
  char local_40 [4];
  char local_3c [4];
  char local_38 [4];
  char local_34 [4];
  char local_30 [4];
  char local_2c [4];
  char local_28 [4];
  char local_24 [4];
  char local_20 [4];
  char local_1c [4];
  char local_18 [4];
  char local_14 [2];
  char local_12;
  char local_10 [4];
  char local_c [4];
  char local_8 [4];
  char local_4 [2];
  char local_2;
  
  local_20 = (char  [4])s_KEY_ACCELERATE_004ea4c8._0_4_;
  local_1c = (char  [4])s_KEY_ACCELERATE_004ea4c8._4_4_;
  local_18 = (char  [4])s_KEY_ACCELERATE_004ea4c8._8_4_;
  local_14 = (char  [2])s_KEY_ACCELERATE_004ea4c8._12_2_;
  local_12 = s_KEY_ACCELERATE_004ea4c8[0xe];
  local_5c = (char  [4])s_KEY_BRAKE_004ea4d8._0_4_;
  local_58 = (char  [4])s_KEY_BRAKE_004ea4d8._4_4_;
  local_54._0_2_ = s_KEY_BRAKE_004ea4d8._8_2_;
  local_40 = (char  [4])s_KEY_STEERLEFT_004ea4e4._0_4_;
  local_3c = (char  [4])s_KEY_STEERLEFT_004ea4e4._4_4_;
  local_38 = (char  [4])s_KEY_STEERLEFT_004ea4e4._8_4_;
  local_34._0_2_ = s_KEY_STEERLEFT_004ea4e4._12_2_;
  local_10 = (char  [4])s_KEY_STEERRIGHT_004ea4f4._0_4_;
  local_c = (char  [4])s_KEY_STEERRIGHT_004ea4f4._4_4_;
  local_8 = (char  [4])s_KEY_STEERRIGHT_004ea4f4._8_4_;
  local_4 = (char  [2])s_KEY_STEERRIGHT_004ea4f4._12_2_;
  local_2 = s_KEY_STEERRIGHT_004ea4f4[0xe];
  local_50 = (char  [4])s_KEY_USEBONUS_004ea504._0_4_;
  local_4c = (char  [4])s_KEY_USEBONUS_004ea504._4_4_;
  local_48 = (char  [4])s_KEY_USEBONUS_004ea504._8_4_;
  local_44 = s_KEY_USEBONUS_004ea504[0xc];
  local_30 = (char  [4])s_KEY_HANDBRAKE_004ea514._0_4_;
  local_2c = (char  [4])s_KEY_HANDBRAKE_004ea514._4_4_;
  local_28 = (char  [4])s_KEY_HANDBRAKE_004ea514._8_4_;
  local_24._0_2_ = s_KEY_HANDBRAKE_004ea514._12_2_;
  FUN_004afce0(s_set_game_input_004ea524);
  FUN_004b1d60(s_Race_INI_004ea534);
  iVar1 = FUN_004b1ed0(s_GAME_SETTINGS_004ea548,s_CONTROL_004ea540);
  uVar2 = FUN_004b1ed0(s_GAME_SETTINGS_004ea564,s_SENSITIVITY_004ea558);
  FUN_004b1d60(s_game_ini_004ea574);
  uVar3 = FUN_004b1ed0(s_INPUT_004ea580,local_20);
  uVar4 = FUN_004b1ed0(s_Input_004ea588,local_5c);
  uVar5 = FUN_004b1ed0(s_Input_004ea590,local_40);
  uVar6 = FUN_004b1ed0(s_Input_004ea598,local_10);
  uVar7 = FUN_004b1ed0(s_Input_004ea5a0,local_50);
  uVar8 = FUN_004b1ed0(s_Input_004ea5a8,local_30);
  FUN_0042ec40(uVar5,uVar6,uVar3,uVar4,uVar7,uVar8,0,0,uVar2);
  FUN_0042ed30(iVar1 + 1);
  return;
}

