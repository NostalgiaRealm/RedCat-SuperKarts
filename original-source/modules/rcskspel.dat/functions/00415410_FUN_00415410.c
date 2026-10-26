/*
 * FUN_00415410 at 00415410
 * undefined FUN_00415410(void)
 * Address ranges: 00415410-0041544e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00415410(void)

{
  int iVar1;
  
  iVar1 = (DAT_0053bef0 + DAT_0053be2c * 0x2b) * 4;
  return ((float10)*(float *)(&DAT_00505b84 + iVar1) * (float10)_DAT_00507290 +
         (float10)*(float *)(&DAT_00505b8c + iVar1)) * (float10)_DAT_00507290 +
         (float10)*(float *)(&DAT_00505b94 + iVar1);
}

