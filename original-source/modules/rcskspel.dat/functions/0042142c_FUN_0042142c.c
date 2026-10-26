/*
 * FUN_0042142c at 0042142c
 * undefined FUN_0042142c(void)
 * Address ranges: 0042142c-00421488
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042142c(void)

{
  int iVar1;
  
  iVar1 = DAT_005090bc * 0xc;
  FUN_00498ad0(*(undefined4 *)(&DAT_00508bec + iVar1),*(undefined4 *)(&DAT_00508bf0 + iVar1),
               *(undefined4 *)(&DAT_00508bf4 + iVar1));
  DAT_005090bc = DAT_005090bc + 1;
  if (DAT_005090b8 <= DAT_005090bc) {
    FUN_004213d0();
    return 0;
  }
  return 0;
}

