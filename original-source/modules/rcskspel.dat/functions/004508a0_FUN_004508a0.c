/*
 * FUN_004508a0 at 004508a0
 * undefined FUN_004508a0(void)
 * Address ranges: 004508a0-004508e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004508a0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = (**(code **)*param_1)(s_D__work_rcsk_Code_game_Bon_Main__004f1244,0x5b);
  FUN_00430dd0(param_3,0,uVar2);
  puVar1 = (undefined4 *)(*(int *)(param_1[1] + 4) + param_3 * 0xc);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  return;
}

