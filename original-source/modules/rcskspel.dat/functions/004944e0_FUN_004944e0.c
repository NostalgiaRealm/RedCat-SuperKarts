/*
 * FUN_004944e0 at 004944e0
 * undefined FUN_004944e0(void)
 * Address ranges: 004944e0-0049450e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004944e0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x24) != 10) {
    FUN_004afce0(s_adding_object___d_to_list__004faecc,param_2);
    *(undefined4 *)(param_1 + 0x28 + *(int *)(param_1 + 0x24) * 4) = param_2;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  }
  return;
}

