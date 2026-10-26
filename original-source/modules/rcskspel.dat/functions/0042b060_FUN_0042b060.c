/*
 * FUN_0042b060 at 0042b060
 * undefined FUN_0042b060(void)
 * Address ranges: 0042b060-0042b1ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b060(void)

{
  uint uVar1;
  
  FUN_004b1d60(s_npc_ai_INI_004e8e98);
  uVar1 = FUN_004b1ed0(s_GENERAL_004e8eb0,s_StopSpeed_004e8ea4);
  _DAT_00505030 = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_GENERAL_004e8ec8,s_ChaseTimeEasy_004e8eb8);
  DAT_00505034 = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_GENERAL_004e8ee0,s_ChaseTimeHard_004e8ed0);
  DAT_00505038 = (float)uVar1;
  DAT_0050503c = FUN_004b1ed0(s_GENERAL_004e8ef4,s_GiveUpDist_004e8ee8);
  DAT_00505040 = FUN_004b1ed0(s_GENERAL_004e8f10,s_CopsPerPlayerEasy_004e8efc);
  DAT_00505044 = FUN_004b1ed0(s_GENERAL_004e8f2c,s_CopsPerPlayerHard_004e8f18);
  DAT_00505048 = FUN_004b1ed0(s_GENERAL_004e8f44,s_CopsPerRacer_004e8f34);
  uVar1 = FUN_004b1ed0(s_VIOLATIONS_004e8f58,s_MaxSpeed60_004e8f4c);
  DAT_0050504c = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_VIOLATIONS_004e8f70,s_MaxSpeed80_004e8f64);
  _DAT_00505050 = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_VIOLATIONS_004e8f88,s_MaxSpeed120_004e8f7c);
  _DAT_00505054 = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_VIOLATIONS_004e8fa0,s_NoMaxSpeed_004e8f94);
  DAT_0050504c = DAT_0050504c * 0.25;
  _DAT_00505050 = _DAT_00505050 * 0.25;
  _DAT_00505054 = _DAT_00505054 * 0.25;
  _DAT_00505058 = (float)uVar1 * 0.25;
  return;
}

