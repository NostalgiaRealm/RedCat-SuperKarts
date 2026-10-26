/*
 * FUN_004031ae at 004031ae
 * undefined __cdecl FUN_004031ae(int * param_1, undefined4 * param_2, undefined4 * param_3)
 * Address ranges: 004031ae-0040322e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004031ae(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 6;
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_70);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_get_desc_of_s_0042d54c);
  }
  *param_2 = local_64;
  *param_3 = local_68;
  return;
}

