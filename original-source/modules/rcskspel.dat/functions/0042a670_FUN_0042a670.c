/*
 * FUN_0042a670 at 0042a670
 * undefined FUN_0042a670(void)
 * Address ranges: 0042a670-0042a6fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a670(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    FUN_004afee0(s__s___d__Illegal_value_for_timer__004e8bac,
                 s_D__work_rcsk_Code_game_gm_clock__004e8b88,0x16c,param_2);
  }
  iVar1 = FUN_0042a1e0(param_1);
  *(int *)(&DAT_0053a270 + iVar1 * 0x14) = param_2;
  iVar1 = FUN_0042a1e0(param_1);
  *(undefined4 *)(&DAT_0053a278 + iVar1 * 0x14) = param_3;
  iVar1 = FUN_0042a1e0(param_1);
  *(undefined4 *)(&DAT_0053a274 + iVar1 * 0x14) = 0xffffffff;
  iVar1 = FUN_0042a1e0(param_1);
  *(undefined4 *)(&DAT_0053a280 + iVar1 * 0x14) = 0;
  iVar1 = FUN_0042a1e0(param_1);
  *(undefined4 *)(&DAT_0053a27c + iVar1 * 0x14) = 1;
  return;
}

