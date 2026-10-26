/*
 * FUN_004988a0 at 004988a0
 * undefined FUN_004988a0(void)
 * Address ranges: 004988a0-004988ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004988a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(int *)(param_1 + 0x74) == 1) || (*(int *)(param_1 + 0x7c) == 1)) {
    FUN_004afee0(s__s__d____Cannot_set_position_in_c_004fb408,
                 s_D__work_rcsk_Code_Engine_Prog_ca_004fb4a4,0xa0,*(undefined4 *)(param_1 + 0x6c),
                 *(int *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                 *(undefined4 *)(param_1 + 0x7c));
  }
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  return;
}

