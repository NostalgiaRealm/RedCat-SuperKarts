/*
 * FUN_004027f9 at 004027f9
 * undefined __cdecl FUN_004027f9(int * param_1, undefined4 param_2)
 * Address ranges: 004027f9-0040284c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004027f9(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,param_2);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_unlock_surfac_0042d0c8);
  }
  return;
}

