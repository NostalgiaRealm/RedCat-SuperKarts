/*
 * FUN_0040235c at 0040235c
 * undefined4 __cdecl FUN_0040235c(int * param_1)
 * Address ranges: 0040235c-004023cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040235c(int *param_1)

{
  int iVar1;
  undefined4 local_70 [9];
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042ceb0);
  }
  return local_4c;
}

