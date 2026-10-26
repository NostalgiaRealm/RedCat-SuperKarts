/*
 * FUN_00414f40 at 00414f40
 * undefined __cdecl FUN_00414f40(int * param_1, undefined4 * param_2, int param_3, int param_4)
 * Address ranges: 00414f40-00415094
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00414f40(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004028c2(param_1);
  if (DAT_0043d754 == 0) {
    local_8 = FUN_00402631(param_1,&local_10);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414e80(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_004027f9(param_1,local_8);
  }
  else if (DAT_0043d754 == 1) {
    local_8 = FUN_00402631(param_1,&local_10);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414c60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_004027f9(param_1,local_8);
  }
  else if (DAT_0043d754 == 2) {
    local_8 = FUN_00402631(param_1,&local_10);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414d60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_004027f9(param_1,local_8);
  }
  return;
}

