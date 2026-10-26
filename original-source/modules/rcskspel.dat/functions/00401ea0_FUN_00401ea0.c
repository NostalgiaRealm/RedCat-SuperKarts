/*
 * FUN_00401ea0 at 00401ea0
 * undefined FUN_00401ea0(void)
 * Address ranges: 00401ea0-00401f29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401ea0(int param_1)

{
  if (*(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) <= 5.0) {
    *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
    *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x9c + DAT_0067ee20) = 0;
    *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xac + DAT_0067ee20) = 0;
    return 1;
  }
  return 0;
}

