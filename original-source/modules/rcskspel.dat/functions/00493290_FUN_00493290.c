/*
 * FUN_00493290 at 00493290
 * undefined FUN_00493290(void)
 * Address ranges: 00493290-004932d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00493290(int param_1,undefined4 param_2)

{
  if ((-1 < param_1) && (param_1 < 0x101)) {
    (&DAT_0067fe18)[param_1] = param_2;
    return;
  }
  FUN_004afee0(s___s___d_Trying_to_set_an_illegal_004fab28,
               s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0xff,param_1);
  (&DAT_0067fe18)[param_1] = param_2;
  return;
}

