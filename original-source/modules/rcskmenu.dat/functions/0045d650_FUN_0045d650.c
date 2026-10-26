/*
 * FUN_0045d650 at 0045d650
 * undefined FUN_0045d650(void)
 * Address ranges: 0045d650-0045d68b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d650(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0045d68c;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e19c = _DAT_0047e19c + 1;
  if (_DAT_0047e19c == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_PR_NONE_0047c2e0,&DAT_004010b0,0x17);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

