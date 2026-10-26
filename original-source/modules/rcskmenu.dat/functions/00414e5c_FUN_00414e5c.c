/*
 * FUN_00414e5c at 00414e5c
 * undefined __register FUN_00414e5c(int param_1, char param_2)
 * Address ranges: 00414e5c-00414ea1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414e5c(int param_1,char param_2)

{
  int *piVar1;
  char acStack_10c [256];
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    FUN_00403dac(acStack_10c,*(undefined4 **)(param_1 + 8),0xff);
    piVar1 = (int *)FUN_0040315c(piVar1,acStack_10c);
    if (piVar1 != (int *)0x0) {
      if (param_2 == '\0') {
        *piVar1 = 0;
      }
      else {
        *piVar1 = param_1;
      }
    }
  }
  return;
}

