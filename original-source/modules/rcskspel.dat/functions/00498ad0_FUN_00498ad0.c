/*
 * FUN_00498ad0 at 00498ad0
 * undefined FUN_00498ad0(void)
 * Address ranges: 00498ad0-00498b1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00498ad0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_1 + 0x74) == 0) {
    FUN_004afee0(s__s__d____Cannot_set_position_loc_004fb618,
                 s_D__work_rcsk_Code_Engine_Prog_ca_004fb4a4,0x15e,*(undefined4 *)(param_1 + 0x6c),0
                 ,*(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c));
  }
  *(undefined4 *)(param_1 + 0xbc) = param_2;
  *(undefined4 *)(param_1 + 0xc0) = param_3;
  *(undefined4 *)(param_1 + 0xc4) = param_4;
  return;
}

