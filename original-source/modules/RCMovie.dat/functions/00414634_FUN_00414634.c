/*
 * FUN_00414634 at 00414634
 * int __cdecl FUN_00414634(int param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 00414634-004146c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00414634(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_2 < param_5) {
    while( true ) {
      uVar1 = FUN_0041461b(param_1,param_2 + local_8,param_3,param_5);
      uVar2 = FUN_0041461b(param_1,param_2 + 1 + local_8,param_3,param_5);
      if (((CONCAT31(extraout_var,uVar1) != CONCAT31(extraout_var_00,uVar2)) || (param_4 <= local_8)
          ) || (0x3e < local_8)) break;
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    local_c = 1;
  }
  else {
    local_c = local_8;
  }
  return local_c;
}

