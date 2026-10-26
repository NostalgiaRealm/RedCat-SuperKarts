/*
 * FUN_0048ecd0 at 0048ecd0
 * undefined FUN_0048ecd0(void)
 * Address ranges: 0048ecd0-0048ecf8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048ecd0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_0048ec10(0);
  return;
}

