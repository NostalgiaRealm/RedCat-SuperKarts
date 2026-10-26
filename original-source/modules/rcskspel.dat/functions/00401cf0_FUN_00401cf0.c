/*
 * FUN_00401cf0 at 00401cf0
 * undefined FUN_00401cf0(void)
 * Address ranges: 00401cf0-00401d11
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00401cf0(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_00415be0(*(undefined4 *)(&DAT_00503ef8 + param_1 * 0x11c));
  return cVar1 == '\0';
}

