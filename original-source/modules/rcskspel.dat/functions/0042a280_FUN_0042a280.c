/*
 * FUN_0042a280 at 0042a280
 * undefined FUN_0042a280(void)
 * Address ranges: 0042a280-0042a2e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a280(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) == 0) {
    FUN_004afee0(s__s___d__Timer_not_initted__index_004e8a3c,
                 s_D__work_rcsk_Code_game_gm_clock__004e8a18,0x77,param_1);
  }
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a280 + iVar1 * 0x14) == 0) {
    DVar2 = GetTickCount();
    iVar1 = FUN_0042a1e0(param_1);
    *(DWORD *)(&DAT_0053a280 + iVar1 * 0x14) = DVar2;
  }
  return;
}

