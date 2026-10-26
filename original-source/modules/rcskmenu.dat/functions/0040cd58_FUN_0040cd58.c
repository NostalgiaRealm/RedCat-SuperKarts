/*
 * FUN_0040cd58 at 0040cd58
 * undefined __register FUN_0040cd58(void)
 * Address ranges: 0040cd58-0040cdbf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040cd58(void)

{
  undefined4 *in_FS_OFFSET;
  bool bVar1;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0040cdc0;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  bVar1 = _DAT_0047d5f8 == 0;
  _DAT_0047d5f8 = _DAT_0047d5f8 + -1;
  if (bVar1) {
    FUN_0040393c((int *)&DAT_0040c080);
    FUN_00403958((int *)&DAT_0040c16c);
    if (DAT_0047d4d1 != '\0') {
      FUN_00403ba4((int *)&PTR_DAT_0047b134,(undefined4 *)&LAB_0040cdd4);
    }
    FUN_0040b368();
    FUN_0040b9e0();
    FUN_0040b4a0();
    FUN_0040be3c();
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

