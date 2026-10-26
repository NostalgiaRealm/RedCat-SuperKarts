/*
 * FUN_00401010 at 00401010
 * undefined4 __stdcall FUN_00401010(undefined4 param_1, int param_2)
 * Address ranges: 00401010-00401033
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00401010(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_00405da0();
    FUN_00406c10();
  }
  _DAT_0041043c = param_1;
  return 1;
}

