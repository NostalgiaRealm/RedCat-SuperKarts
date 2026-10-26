/*
 * FUN_00493250 at 00493250
 * undefined FUN_00493250(void)
 * Address ranges: 00493250-00493281
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00493250(int param_1)

{
  if ((param_1 < 0) || (0x100 < param_1)) {
    FUN_004afee0(s___s___d_Trying_to_get_an_illegal_004faae8,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0xf1,param_1);
  }
  return (&DAT_006802cc)[param_1 * 2];
}

