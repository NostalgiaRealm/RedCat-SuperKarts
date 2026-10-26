/*
 * FUN_0040303c at 0040303c
 * undefined __register FUN_0040303c(int * param_1, int param_2)
 * Address ranges: 0040303c-00403056
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040303c(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    while (*piVar1 != param_2) {
      piVar1 = *(int **)(*piVar1 + -0x24);
      if (piVar1 == (int *)0x0) {
        FUN_004027a0(CONCAT31((int3)((uint)param_1 >> 8),10));
        return;
      }
    }
  }
  return;
}

