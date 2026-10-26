/*
 * FUN_00466e44 at 00466e44
 * undefined __register FUN_00466e44(int param_1, char param_2)
 * Address ranges: 00466e44-00466e87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466e44(int param_1,char param_2)

{
  WPARAM WVar1;
  
  if (param_2 != *(char *)(param_1 + 0x1f9)) {
    if (param_2 == '\0') {
      WVar1 = FUN_00466cc0(param_1);
      *(undefined1 *)(param_1 + 0x1f9) = 0;
      FUN_00467220(*(int **)(param_1 + 500),param_1,WVar1);
    }
    else {
      *(undefined1 *)(param_1 + 0x1f9) = 1;
      FUN_00467538(*(int **)(param_1 + 500),param_1);
    }
  }
  return;
}

