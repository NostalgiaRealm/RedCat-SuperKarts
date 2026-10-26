/*
 * FUN_0040f570 at 0040f570
 * undefined FUN_0040f570(void)
 * Address ranges: 0040f570-0040f5b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f570(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004b1ed0(PTR_s_RCR_GLOBAL_004df2a8,s_BONUS_SCAN_AHEAD_004df33c);
  if (iVar1 == 0) {
    iVar1 = 5;
  }
  *(int *)(param_1 + 0x21c) = iVar1;
  FUN_004afce0(s__s__d____Read_key__s___d__004df37c,s_D__work_rcsk_Code_game_ai_rcr_se_004df350,0x90
               ,s_BONUS_SCAN_AHEAD_004df33c,iVar1);
  return;
}

