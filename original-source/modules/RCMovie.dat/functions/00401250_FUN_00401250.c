/*
 * FUN_00401250 at 00401250
 * undefined __stdcall FUN_00401250(void)
 * Address ranges: 00401250-00401297
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401250(void)

{
  int iVar1;
  
  FUN_004056d0((uint *)s_movie_ini_0042c134);
  iVar1 = FUN_0040584a(s_HELPDESK_0042c120,s_DEBUG_0042c12c);
  FUN_00401590(0,(uint)(iVar1 == 1));
  DAT_004383a8 = FUN_0040584a(s_PLAYER_0042c110,&DAT_0042c118);
  return;
}

