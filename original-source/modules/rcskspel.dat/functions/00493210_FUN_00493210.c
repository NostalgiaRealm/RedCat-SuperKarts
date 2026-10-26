/*
 * FUN_00493210 at 00493210
 * undefined FUN_00493210(void)
 * Address ranges: 00493210-00493241
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00493210(int param_1)

{
  if ((param_1 < 0) || (0x100 < param_1)) {
    FUN_004afee0(s___s___d_Trying_to_get_an_illegal_004faaac,param_1,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0xe3);
  }
  return (&DAT_006802c8)[param_1 * 2];
}

