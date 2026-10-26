/*
 * FUN_00458ee4 at 00458ee4
 * undefined __register FUN_00458ee4(void)
 * Address ranges: 00458ee4-00458f1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00458ee4(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00458f20;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e17c = _DAT_0047e17c + 1;
  if (_DAT_0047e17c == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_KEY_ACCELERATE_0047c0b4,&DAT_004010b0,6);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

