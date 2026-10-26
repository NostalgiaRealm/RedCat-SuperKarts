/*
 * FUN_00473568 at 00473568
 * undefined __register FUN_00473568(void)
 * Address ranges: 00473568-004735b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473568(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004735b9;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e2dc = _DAT_0047e2dc + 1;
  if (_DAT_0047e2dc == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047e2e0,"\x0e\vTFinishChar$",10);
    FUN_004043f8((VARIANTARG *)&PTR_s_PIC_REDCAT_0047c4c0,&DAT_004010b0,10);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

