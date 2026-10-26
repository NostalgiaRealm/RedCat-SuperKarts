/*
 * FUN_004026ac at 004026ac
 * undefined4 __cdecl FUN_004026ac(int * param_1, undefined4 * param_2)
 * Address ranges: 004026ac-00402726
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004026ac(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042d024);
  }
  *param_2 = local_60;
  return local_4c;
}

