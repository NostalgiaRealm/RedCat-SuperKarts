/*
 * FUN_004028c2 at 004028c2
 * undefined __cdecl FUN_004028c2(int * param_1)
 * Address ranges: 004028c2-004028e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004028c2(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x6c))(param_1);
  }
  return;
}

