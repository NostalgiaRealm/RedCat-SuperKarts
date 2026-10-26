/*
 * FUN_0041e790 at 0041e790
 * undefined __cdecl FUN_0041e790(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0041e790-0041e7cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041e790(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0041e7d0();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____Invalid_action_key_00436dc4);
  }
  (&DAT_0043e210)[iVar1 * 2] = param_1;
  (&DAT_0043e214)[iVar1 * 2] = param_2;
  return;
}

