/*
 * FUN_004404bc at 004404bc
 * undefined4 __register FUN_004404bc(int * param_1, int * param_2, int * param_3)
 * Address ranges: 004404bc-004404eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004404bc(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x30))(param_1,param_2,param_3);
  if ((char)uVar1 != '\0') {
    FUN_0044051c(param_1,param_2,param_3);
  }
  return uVar1;
}

