/*
 * FUN_00448878 at 00448878
 * undefined FUN_00448878(void)
 * Address ranges: 00448878-004488b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448878(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004478c8(param_1,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    if (piVar1 == *(int **)(param_1 + 0x38)) {
      piVar1[1] = 0;
    }
    else {
      FUN_004488b4(param_1,piVar1);
    }
    *(undefined1 *)(param_2 + 0x8c) = 0;
    (**(code **)(**(int **)(param_1 + 0x14) + 0x74))();
  }
  return;
}

