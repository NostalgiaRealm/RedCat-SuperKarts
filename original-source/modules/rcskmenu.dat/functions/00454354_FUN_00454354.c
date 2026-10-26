/*
 * FUN_00454354 at 00454354
 * undefined FUN_00454354(void)
 * Address ranges: 00454354-00454426
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454354(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00454427;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d90c = _DAT_0047d90c + 1;
  if (_DAT_0047d90c == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_Landenrace_0047bcfc,&DAT_004010b0,5);
    FUN_004043f8((VARIANTARG *)&PTR_s_NORMALRACE_0047bce8,&DAT_004010b0,5);
    FUN_004043f8((VARIANTARG *)&PTR_s_RedCat_0047bcd8,&DAT_004010b0,4);
    FUN_004043f8((VARIANTARG *)&PTR_s_Redcat_0047bcb0,&DAT_004010b0,10);
    FUN_004043f8((VARIANTARG *)&PTR_s_Nederland_0047bc98,&DAT_004010b0,6);
    FUN_004043f8((VARIANTARG *)&PTR_s_NEDERLAND_0047bc80,&DAT_004010b0,6);
    FUN_004043f8((VARIANTARG *)&PTR_DAT_0047bc74,&DAT_004010b0,3);
    FUN_004043f8((VARIANTARG *)&PTR_s_Makkelijk_0047bc68,&DAT_004010b0,3);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

