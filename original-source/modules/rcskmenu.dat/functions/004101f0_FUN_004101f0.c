/*
 * FUN_004101f0 at 004101f0
 * undefined __register FUN_004101f0(int param_1, undefined4 param_2, int param_3, undefined4 param_4)
 * Address ranges: 004101f0-0041020f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004101f0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00410218(param_1,param_3);
  (**(code **)(*piVar1 + 0xc))(piVar1,param_4);
  return;
}

