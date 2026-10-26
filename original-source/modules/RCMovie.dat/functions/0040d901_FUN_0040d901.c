/*
 * FUN_0040d901 at 0040d901
 * undefined __cdecl FUN_0040d901(undefined4 param_1)
 * Address ranges: 0040d901-0040d93e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040d901(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040d89a();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____set_help_key__No_free_k_00432478);
  }
  else {
    *(undefined4 *)(&DAT_004322f0 + iVar1 * 4) = param_1;
  }
  return;
}

