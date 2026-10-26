/*
 * FUN_004214cc at 004214cc
 * undefined FUN_004214cc(void)
 * Address ranges: 004214cc-0042151c;00421535-00421538
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004214cc(void)

{
  int iVar1;
  
  iVar1 = DAT_005090bc * 0xc;
  FUN_00498ad0(*(undefined4 *)(&DAT_00508bec + iVar1),*(undefined4 *)(&DAT_00508bf0 + iVar1),
               *(undefined4 *)(&DAT_00508bf4 + iVar1));
  DAT_005090bc = DAT_005090bc + -2;
  if (DAT_005090bc < 0) {
    return 1;
  }
  return 0;
}

