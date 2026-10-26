/*
 * FUN_00498b80 at 00498b80
 * undefined FUN_00498b80(void)
 * Address ranges: 00498b80-00498bce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00498b80(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x78) == 0) {
    FUN_004afee0(s__s__d____Cannot_get_target_lock_o_004fb6c0,
                 s_D__work_rcsk_Code_Engine_Prog_ca_004fb4a4,0x181,*(undefined4 *)(param_1 + 0x70),
                 *(undefined4 *)(param_1 + 0x74),0,*(undefined4 *)(param_1 + 0x7c));
  }
  *param_2 = *(undefined4 *)(param_1 + 0xcc);
  param_2[1] = *(undefined4 *)(param_1 + 0xd0);
  param_2[2] = *(undefined4 *)(param_1 + 0xd4);
  return;
}

