/*
 * FUN_004062d3 at 004062d3
 * undefined4 __cdecl FUN_004062d3(undefined4 param_1)
 * Address ranges: 004062d3-00406326
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004062d3(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = (**(code **)(*DAT_0043d410 + 0x14))(DAT_0043d410,param_1,&local_8);
  if (iVar1 != 0) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_duplicating_sound_0042f42c);
  }
  return local_8;
}

