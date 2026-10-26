/*
 * FUN_00498a80 at 00498a80
 * undefined FUN_00498a80(void)
 * Address ranges: 00498a80-00498ace
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00498a80(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x74) == 0) {
    FUN_004afee0(s__s__d____Cannot_get_position_loc_004fb570,
                 s_D__work_rcsk_Code_Engine_Prog_ca_004fb4a4,0x149,*(undefined4 *)(param_1 + 0x6c),0
                 ,*(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c));
  }
  *param_2 = *(undefined4 *)(param_1 + 0xbc);
  param_2[1] = *(undefined4 *)(param_1 + 0xc0);
  param_2[2] = *(undefined4 *)(param_1 + 0xc4);
  return;
}

