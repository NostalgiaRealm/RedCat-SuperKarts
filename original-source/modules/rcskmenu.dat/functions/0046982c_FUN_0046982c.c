/*
 * FUN_0046982c at 0046982c
 * undefined FUN_0046982c(void)
 * Address ranges: 0046982c-004698a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046982c(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004698a2;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e20c = _DAT_0047e20c + 1;
  if (_DAT_0047e20c == 0) {
    DAT_0047e210 = 1;
    FUN_00402eac(DAT_0047e214);
    *(undefined4 *)PTR_DAT_0047c8e4 = 0;
    *(undefined4 *)PTR_PTR_0047c644 = 0;
    *(undefined4 *)PTR_PTR_0047c88c = 0;
    if (DAT_0047e21c != '\0') {
      CoUninitialize();
    }
    FUN_004043f8((VARIANTARG *)&DAT_0047c404,&DAT_004010b0,4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

