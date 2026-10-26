/*
 * FUN_004931c0 at 004931c0
 * undefined FUN_004931c0(void)
 * Address ranges: 004931c0-00493200
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004931c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 < 0) || (0x100 < param_1)) {
    FUN_004afee0(s___s___d_Trying_to_set_an_illegal_004faa4c,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0xd4,param_1);
  }
  (&DAT_006802c8)[param_1 * 2] = param_2;
  (&DAT_006802cc)[param_1 * 2] = param_3;
  return;
}

