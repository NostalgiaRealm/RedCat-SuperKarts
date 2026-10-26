/*
 * FUN_004320b4 at 004320b4
 * undefined4 __register FUN_004320b4(int param_1, undefined4 param_2)
 * Address ranges: 004320b4-004320e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004320b4(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = *(int **)(param_1 + 0x74);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0xc4))(piVar1,param_2);
    if (cVar2 != '\0') {
      FUN_00432e8c(param_1);
    }
  }
  return 0;
}

