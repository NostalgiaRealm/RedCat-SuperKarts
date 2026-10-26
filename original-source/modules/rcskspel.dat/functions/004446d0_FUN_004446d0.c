/*
 * FUN_004446d0 at 004446d0
 * undefined FUN_004446d0(void)
 * Address ranges: 004446d0-00444724
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004446d0(int param_1)

{
  if ((param_1 < 0) || (DAT_00543760 <= param_1)) {
    FUN_004afee0(s__s___d__Path_does_not_exist__Pat_004ef00c,
                 s_D__work_rcsk_Code_game_pth_heli__004eefe8,0x5e,param_1,DAT_00543760);
  }
  if ((&DAT_0053f99c)[param_1 * 0xd0] != -1) {
    FUN_00492730((&DAT_0053f99c)[param_1 * 0xd0]);
    FUN_0048fea0((&DAT_0053f99c)[param_1 * 0xd0]);
  }
  return;
}

