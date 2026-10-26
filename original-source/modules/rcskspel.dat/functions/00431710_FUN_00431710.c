/*
 * FUN_00431710 at 00431710
 * undefined FUN_00431710(void)
 * Address ranges: 00431710-00431743
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00431710(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1);
    (**(code **)(*(int *)param_1[1] + 8))((int *)param_1[1]);
    param_1[1] = 0;
  }
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
  }
  return;
}

