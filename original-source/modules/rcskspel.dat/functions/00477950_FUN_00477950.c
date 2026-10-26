/*
 * FUN_00477950 at 00477950
 * undefined FUN_00477950(void)
 * Address ranges: 00477950-0047797b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00477950(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00477940();
  iVar2 = FUN_00477930();
  *param_1 = iVar1 / 2;
  param_1[1] = iVar2 / 2;
  return param_1;
}

