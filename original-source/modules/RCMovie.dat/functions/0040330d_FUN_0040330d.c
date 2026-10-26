/*
 * FUN_0040330d at 0040330d
 * undefined __cdecl FUN_0040330d(int * param_1, undefined4 param_2)
 * Address ranges: 0040330d-0040337d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040330d(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_6c [20];
  undefined4 local_1c;
  undefined4 local_8;
  
  local_8 = 0x1000400;
  local_6c[0] = 100;
  local_1c = param_2;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,0,0,0,local_8,local_6c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____clear_surface_blt_error_0042d5c0);
  }
  return;
}

