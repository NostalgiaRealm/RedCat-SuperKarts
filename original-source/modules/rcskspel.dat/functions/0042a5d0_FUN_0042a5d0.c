/*
 * FUN_0042a5d0 at 0042a5d0
 * undefined FUN_0042a5d0(void)
 * Address ranges: 0042a5d0-0042a668
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a5d0(undefined4 param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) == 0) {
    FUN_004afee0(s__s___d__Timer_not_initted__index_004e8b14,
                 s_D__work_rcsk_Code_game_gm_clock__004e8af0,0x148,param_1);
  }
  if (param_2 < 0) {
    FUN_004afee0(s__s___d__Illegal_value_for_timer__004e8b5c,
                 s_D__work_rcsk_Code_game_gm_clock__004e8b38,0x14e,param_2);
  }
  iVar1 = FUN_0042a1e0(param_1);
  *(int *)(&DAT_0053a270 + iVar1 * 0x14) = param_2;
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a274 + iVar1 * 0x14) != -1) {
    DVar2 = GetTickCount();
    iVar1 = FUN_0042a1e0(param_1);
    *(DWORD *)(&DAT_0053a274 + iVar1 * 0x14) = DVar2;
  }
  return;
}

