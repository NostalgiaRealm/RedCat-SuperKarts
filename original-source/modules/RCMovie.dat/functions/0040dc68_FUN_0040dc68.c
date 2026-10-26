/*
 * FUN_0040dc68 at 0040dc68
 * undefined __cdecl FUN_0040dc68(int * param_1, int param_2)
 * Address ranges: 0040dc68-0040dcd5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040dc68(int *param_1,int param_2)

{
  int iVar1;
  uint local_c;
  uint local_8;
  
  local_c = FUN_0040dba6(param_1,param_2);
  local_8 = local_c;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x74))(param_1,8,&local_c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_color_key_004325a0);
  }
  return;
}

