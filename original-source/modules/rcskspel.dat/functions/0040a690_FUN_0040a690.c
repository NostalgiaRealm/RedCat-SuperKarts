/*
 * FUN_0040a690 at 0040a690
 * undefined FUN_0040a690(void)
 * Address ranges: 0040a690-0040a72a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a690(int param_1)

{
  *(undefined4 *)(&DAT_00503f2c + param_1 * 0x11c) = 0;
  *(undefined4 *)(&DAT_00503f30 + param_1 * 0x11c) = 0;
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x9c + DAT_0067ee20) = 0;
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xac + DAT_0067ee20) = 0;
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return;
}

