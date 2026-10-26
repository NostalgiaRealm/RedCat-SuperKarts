/*
 * FUN_00436dc0 at 00436dc0
 * undefined FUN_00436dc0(void)
 * Address ranges: 00436dc0-00436dd6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00436dc0(int param_1)

{
  if (param_1 < 10) {
    return *(undefined4 *)(&DAT_004ebe08 + param_1 * 4);
  }
  return DAT_00508610;
}

