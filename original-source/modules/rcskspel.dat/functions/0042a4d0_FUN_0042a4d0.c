/*
 * FUN_0042a4d0 at 0042a4d0
 * undefined FUN_0042a4d0(void)
 * Address ranges: 0042a4d0-0042a5cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0042a4d0(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) == 0) {
    FUN_004afee0(s__s___d__Timer_not_initted__index_004e8acc,
                 s_D__work_rcsk_Code_game_gm_clock__004e8aa8,0x106,param_1);
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
  if (*(int *)(&DAT_0053a274 + iVar3 * 0x14) == -1) {
    iVar1 = 0;
  }
  else {
    iVar3 = FUN_0042a1e0(param_1);
    iVar1 = (DVar2 - *(int *)(&DAT_0053a274 + iVar3 * 0x14)) - iVar1;
  }
  iVar3 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a278 + iVar3 * 0x14) == 0) {
    iVar3 = FUN_0042a1e0(param_1);
    if (*(int *)(&DAT_0053a270 + iVar3 * 0x14) <= iVar1) {
      iVar1 = FUN_0042a1e0(param_1);
      iVar1 = *(int *)(&DAT_0053a270 + iVar1 * 0x14);
    }
    return iVar1;
  }
  iVar3 = FUN_0042a1e0(param_1);
  iVar1 = *(int *)(&DAT_0053a270 + iVar3 * 0x14) - iVar1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}

