/*
 * FUN_00463084 at 00463084
 * undefined __register FUN_00463084(int * param_1)
 * Address ranges: 00463084-004630b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463084(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x4c))();
  if (cVar1 != '\0') {
    FUN_00464410(param_1);
    if (*(short *)((int)param_1 + 0x10a) != 0) {
      (*(code *)param_1[0x42])(param_1[0x43],param_1);
    }
  }
  return;
}

