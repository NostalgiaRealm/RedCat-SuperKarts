/*
 * FUN_004023cc at 004023cc
 * undefined4 __cdecl FUN_004023cc(int * param_1)
 * Address ranges: 004023cc-0040243b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004023cc(int *param_1)

{
  int iVar1;
  undefined4 local_70 [9];
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cee4);
  }
  return local_4c;
}

