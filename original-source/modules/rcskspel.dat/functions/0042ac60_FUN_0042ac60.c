/*
 * FUN_0042ac60 at 0042ac60
 * undefined FUN_0042ac60(void)
 * Address ranges: 0042ac60-0042ad4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042ac60(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined *puVar3;
  
  FUN_004b1d60(s_Race_ini_004e8d10);
  uVar1 = FUN_004b1ed0(s_RACETYPEINFO_004e8d28,s_RaceType_004e8d1c);
  switch(uVar1) {
  default:
    puVar3 = &DAT_0053a570;
    break;
  case 1:
    puVar3 = &DAT_0053a550;
    break;
  case 2:
    puVar3 = &DAT_0053a530;
    break;
  case 3:
    puVar3 = &DAT_0053a510;
    break;
  case 4:
    puVar3 = &DAT_0053a4f0;
    break;
  case 5:
    puVar3 = &DAT_0053a4d0;
  }
  FUN_0042aaa0(puVar3);
  uVar1 = FUN_004b1ed0(s_RACETYPEINFO_004e8d44,s_Opponents_004e8d38);
  FUN_0042ab00(uVar1);
  uVar1 = FUN_004b1ed0(s_RACETYPEINFO_004e8d64,s_PhysicsModel_004e8d54);
  FUN_0042ab80(uVar1);
  FUN_004b1d60(s_game_ini_004e8d74);
  uVar2 = FUN_004b1ed0(s_Options_004e8d90,s_PlayerGravity_004e8d80);
  _DAT_0053a4a8 = (float)uVar2;
  uVar2 = FUN_004b1ed0(s_Options_004e8da8,s_OpponentGravity_004e8d98);
  _DAT_0053a4ac = (float)uVar2;
  return;
}

