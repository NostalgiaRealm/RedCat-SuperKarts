/*
 * FUN_004afc80 at 004afc80
 * undefined FUN_004afc80(void)
 * Address ranges: 004afc80-004afc98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004afc80(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}

