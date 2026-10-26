/*
 * FUN_0040a4d0 at 0040a4d0
 * undefined FUN_0040a4d0(void)
 * Address ranges: 0040a4d0-0040a54f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a4d0(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00503ef0 + param_1 * 0x47;
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
  *(undefined4 *)(*piVar1 * 0xd0 + 0x9c + DAT_0067ee20) = 0;
  *(undefined4 *)(*piVar1 * 0xd0 + 0xac + DAT_0067ee20) = 0;
  FUN_00413330(*piVar1);
  FUN_004130e0(*piVar1);
  FUN_00412fd0(*piVar1);
  return;
}

