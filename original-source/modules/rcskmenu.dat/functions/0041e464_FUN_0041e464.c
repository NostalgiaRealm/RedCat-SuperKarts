/*
 * FUN_0041e464 at 0041e464
 * undefined FUN_0041e464(void)
 * Address ranges: 0041e464-0041e48c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e464(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_0041e238(param_1,param_2,param_3);
  piVar1 = *(int **)(*(int *)(param_1 + 0x20) + 0xc);
  iVar2 = FUN_004118b0(piVar1);
  FUN_00411920(param_2,piVar1[1],iVar2);
  return;
}

