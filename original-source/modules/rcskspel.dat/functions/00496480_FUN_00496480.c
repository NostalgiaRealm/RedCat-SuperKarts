/*
 * FUN_00496480 at 00496480
 * undefined FUN_00496480(void)
 * Address ranges: 00496480-004964d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00496480(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,param_1 + 0x31,param_1 + 0x18,
                 *(undefined4 *)(param_1 + 8));
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_004bc150(*(undefined4 *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

