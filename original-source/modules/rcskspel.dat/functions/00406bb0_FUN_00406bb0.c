/*
 * FUN_00406bb0 at 00406bb0
 * undefined FUN_00406bb0(void)
 * Address ranges: 00406bb0-00406bdf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_00406bb0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_00503f7c + param_1 * 0x11c);
  if (iVar1 == 1) {
    return 'M';
  }
  if (iVar1 == 0) {
    return 'R';
  }
  return ((iVar1 != 2) - 1U & 0xd) + 0x3f;
}

