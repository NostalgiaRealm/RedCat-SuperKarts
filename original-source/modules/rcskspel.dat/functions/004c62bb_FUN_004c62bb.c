/*
 * FUN_004c62bb at 004c62bb
 * undefined FUN_004c62bb(void)
 * Address ranges: 004c62bb-004c62d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c62bb(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_006b67c0 != (code *)0x0) {
    iVar1 = (*DAT_006b67c0)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

