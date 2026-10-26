/*
 * FUN_00467bfc at 00467bfc
 * undefined __register FUN_00467bfc(void)
 * Address ranges: 00467bfc-00467c6a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00467bfc(void)

{
  undefined1 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00467c6b;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e1f8 = _DAT_0047e1f8 + 1;
  if (_DAT_0047e1f8 == 0) {
    puVar1 = &stack0xfffffffc;
    if (DAT_0047e1fc != (HMODULE)0x0) {
      FreeLibrary(DAT_0047e1fc);
      puVar1 = puStack_8;
    }
    puStack_8 = puVar1;
    if (DAT_0047e200 != (HMODULE)0x0) {
      FreeLibrary(DAT_0047e200);
    }
    FUN_004043cc(0x47c390,(int)&DAT_0046579c);
    FUN_004043cc(0x47c384,(int)&DAT_0046579c);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

