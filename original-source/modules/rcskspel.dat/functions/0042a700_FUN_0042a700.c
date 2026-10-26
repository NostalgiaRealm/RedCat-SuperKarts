/*
 * FUN_0042a700 at 0042a700
 * undefined FUN_0042a700(void)
 * Address ranges: 0042a700-0042a7b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0042a700(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) == 0) {
    FUN_004afee0(s__s___d__Timer_not_initted__index_004e8bfc,
                 s_D__work_rcsk_Code_game_gm_clock__004e8bd8,0x18d,param_1);
  }
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a274 + iVar1 * 0x14) == -1) {
    return false;
  }
  DVar2 = GetTickCount();
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a280 + iVar1 * 0x14) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0042a1e0(param_1);
    iVar1 = DVar2 - *(int *)(&DAT_0053a280 + iVar1 * 0x14);
  }
  iVar3 = FUN_0042a1e0(param_1);
  iVar3 = *(int *)(&DAT_0053a274 + iVar3 * 0x14);
  iVar4 = FUN_0042a1e0(param_1);
  return *(int *)(&DAT_0053a270 + iVar4 * 0x14) <= (int)((DVar2 - iVar3) - iVar1);
}

