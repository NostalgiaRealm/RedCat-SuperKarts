/*
 * FUN_00452794 at 00452794
 * undefined __register FUN_00452794(void)
 * Address ranges: 00452794-004527de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00452794(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004527df;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d8f0 = _DAT_0047d8f0 + 1;
  if (_DAT_0047d8f0 == 0) {
    FUN_0041aa3c(&PTR_FUN_00416588,(int)&PTR_FUN_00450238);
    FUN_00402eac(DAT_0047d8f8);
    FUN_00402eac(DAT_0047d8f4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

