/*
 * FUN_004257d9 at 004257d9
 * undefined __cdecl FUN_004257d9(int param_1, undefined4 * param_2)
 * Address ranges: 004257d9-004257f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004257d9(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 - (int)param_2;
  iVar2 = 3;
  do {
    *(undefined4 *)(iVar1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

