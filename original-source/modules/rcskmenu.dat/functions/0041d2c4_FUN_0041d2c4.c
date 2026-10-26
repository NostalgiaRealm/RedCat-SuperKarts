/*
 * FUN_0041d2c4 at 0041d2c4
 * undefined FUN_0041d2c4(void)
 * Address ranges: 0041d2c4-0041d2ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d2c4(int param_1,int *param_2,int param_3)

{
  int iStack_10;
  
  iStack_10 = param_3;
  (**(code **)(*param_2 + 4))(param_2,&iStack_10,4);
  FUN_0041d7fc(param_1,param_2,iStack_10);
  return;
}

