/*
 * FUN_0040478a at 0040478a
 * undefined4 __fastcall FUN_0040478a(undefined4 param_1)
 * Address ranges: 0040478a-004047d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040478a(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_0043841c + 0x4c))(DAT_0043841c,param_1);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042df54);
  }
  return 0;
}

