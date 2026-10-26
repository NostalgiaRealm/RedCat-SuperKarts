/*
 * FUN_0044f608 at 0044f608
 * bool __register FUN_0044f608(int * param_1, undefined4 param_2, undefined4 param_3, undefined1 param_4)
 * Address ranges: 0044f608-0044f632
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0044f608(int *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3,param_4);
  return iVar1 != 0;
}

