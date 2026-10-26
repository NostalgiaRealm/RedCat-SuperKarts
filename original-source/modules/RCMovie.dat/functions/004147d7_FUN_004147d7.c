/*
 * FUN_004147d7 at 004147d7
 * undefined4 __cdecl FUN_004147d7(int * param_1, int param_2, uint param_3, int param_4, int param_5)
 * Address ranges: 004147d7-0041485d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004147d7(int *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int local_8;
  
  FUN_004015a6((byte *)s__s__d__00435118);
  for (local_8 = 0; local_8 < param_4; local_8 = local_8 + 1) {
    FUN_004015a6((byte *)s__s__d__0043512c);
    FUN_004146c3(param_1,param_2,local_8,param_3,param_5);
  }
  FUN_004015a6((byte *)s__s__d__00435140);
  return 0;
}

