/*
 * FUN_004112d0 at 004112d0
 * undefined FUN_004112d0(void)
 * Address ranges: 004112d0-00411314
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004112d0(int param_1)

{
  if ((param_1 < 8) && (-1 < param_1)) {
    (&DAT_00505a30)[param_1 * 6] = 0xffffffff;
    (&DAT_00505a38)[param_1 * 6] = 0xffffffff;
    (&DAT_00505a40)[param_1 * 6] = 0;
    (&DAT_00505a34)[param_1 * 6] = 0xffffffff;
    *(undefined4 *)(&DAT_00505a3c + param_1 * 0x18) = 0xffffffff;
    (&DAT_00505a44)[param_1 * 6] = 0;
    return 1;
  }
  return 0;
}

