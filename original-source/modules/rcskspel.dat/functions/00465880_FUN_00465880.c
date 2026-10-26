/*
 * FUN_00465880 at 00465880
 * undefined FUN_00465880(void)
 * Address ranges: 00465880-00465890
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00465880(int param_1)

{
  if ((*(int *)(param_1 + 0x14) != 1) && (*(int *)(param_1 + 0x14) == 2)) {
    return *(undefined4 *)(param_1 + 0xc);
  }
  return *(undefined4 *)(param_1 + 8);
}

