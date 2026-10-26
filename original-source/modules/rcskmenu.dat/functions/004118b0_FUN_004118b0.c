/*
 * FUN_004118b0 at 004118b0
 * undefined4 __register FUN_004118b0(int * param_1)
 * Address ranges: 004118b0-004118e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004118b0(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  
  uVar1 = (**(code **)(*param_1 + 0xc))(param_1,0,1);
  uVar2 = (**(code **)(*param_1 + 0xc))(param_1,0,CONCAT22(extraout_var,2));
  (**(code **)(*param_1 + 0xc))(param_1,uVar1,0);
  return uVar2;
}

