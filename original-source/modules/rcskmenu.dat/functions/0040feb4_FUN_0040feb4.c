/*
 * FUN_0040feb4 at 0040feb4
 * undefined __register FUN_0040feb4(int param_1, char param_2)
 * Address ranges: 0040feb4-0040fed4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040feb4(int param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if ((piVar1 != (int *)0x0) && (piVar1[3] == 0)) {
    if (param_2 != '\0') {
      param_1 = 0;
    }
    (**(code **)(*piVar1 + 0x10))(piVar1,param_1);
  }
  return;
}

