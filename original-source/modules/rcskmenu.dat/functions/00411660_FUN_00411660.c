/*
 * FUN_00411660 at 00411660
 * undefined __register FUN_00411660(int * param_1, int param_2, undefined4 * param_3)
 * Address ranges: 00411660-004116c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411660(int *param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  
  (**(code **)(*param_1 + 0x74))();
  if (param_1[4] == param_1[5]) {
    FUN_004115ac(param_1);
  }
  if (param_2 < param_1[4]) {
    FUN_0040282c((undefined4 *)(param_1[3] + param_2 * 8),
                 (undefined4 *)(param_1[3] + 8 + param_2 * 8),(param_1[4] - param_2) * 8);
  }
  piVar1 = (int *)(param_1[3] + param_2 * 8);
  *piVar1 = 0;
  piVar1[1] = 0;
  FUN_00403ba4(piVar1,param_3);
  param_1[4] = param_1[4] + 1;
  (**(code **)(*param_1 + 0x70))();
  return;
}

