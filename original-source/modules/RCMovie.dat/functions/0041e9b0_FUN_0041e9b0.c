/*
 * FUN_0041e9b0 at 0041e9b0
 * undefined __fastcall FUN_0041e9b0(int param_1)
 * Address ranges: 0041e9b0-0041ea29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0041e9b0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x1d);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x7c))(piVar1,0);
  }
  piVar1 = *(int **)(param_1 + 0x1d);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x1d) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x19);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x19) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x15);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x15) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x11);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x11) = 0;
  }
  piVar1 = *(int **)(param_1 + 0xd);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0xd) = 0;
  }
  piVar1 = *(int **)(param_1 + 9);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 9) = 0;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}

