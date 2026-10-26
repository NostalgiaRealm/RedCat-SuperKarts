/*
 * FUN_0044c8d4 at 0044c8d4
 * undefined FUN_0044c8d4(void)
 * Address ranges: 0044c8d4-0044c925
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044c8d4(void)

{
  undefined1 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044c926;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d820 = _DAT_0047d820 + 1;
  if (_DAT_0047d820 == 0) {
    puVar1 = &stack0xfffffffc;
    if (DAT_0047ba38 != 0) {
      GlobalDeleteAtom(DAT_0047ba38);
      puVar1 = puStack_8;
    }
    puStack_8 = puVar1;
    FUN_004043f8((VARIANTARG *)&PTR_DAT_0047ba64,&DAT_004010b0,0xb);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

