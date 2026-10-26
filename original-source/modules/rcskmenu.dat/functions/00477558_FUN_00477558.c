/*
 * FUN_00477558 at 00477558
 * undefined FUN_00477558(void)
 * Address ranges: 00477558-004775a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477558(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004775a9;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e55c = _DAT_0047e55c + 1;
  if (_DAT_0047e55c == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047c558,&DAT_004010b0,0xb);
    FUN_004043f8((VARIANTARG *)&DAT_0047c52c,&DAT_004010b0,0xb);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

