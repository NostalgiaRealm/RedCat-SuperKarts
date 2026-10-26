/*
 * FUN_0042a210 at 0042a210
 * undefined FUN_0042a210(void)
 * Address ranges: 0042a210-0042a273
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a210(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) == 0) {
    FUN_004afee0(s__s___d__Timer_not_initted__index_004e89f4,
                 s_D__work_rcsk_Code_game_gm_clock__004e89d0,0x5e,param_1);
  }
  DVar2 = GetTickCount();
  iVar1 = FUN_0042a1e0(param_1);
  *(DWORD *)(&DAT_0053a274 + iVar1 * 0x14) = DVar2;
  iVar1 = FUN_0042a1e0(param_1);
  *(undefined4 *)(&DAT_0053a280 + iVar1 * 0x14) = 0;
  return;
}

