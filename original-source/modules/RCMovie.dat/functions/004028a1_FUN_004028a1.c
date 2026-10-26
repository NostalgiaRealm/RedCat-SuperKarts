/*
 * FUN_004028a1 at 004028a1
 * undefined __cdecl FUN_004028a1(int * param_1)
 * Address ranges: 004028a1-004028c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004028a1(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x6c))(param_1);
  }
  return;
}

