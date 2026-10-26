/*
 * FUN_00464424 at 00464424
 * undefined __register FUN_00464424(int * param_1, char param_2)
 * Address ranges: 00464424-00464457
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464424(int *param_1,char param_2)

{
  if (param_2 != (char)param_1[0x84]) {
    *(char *)(param_1 + 0x84) = param_2;
    if (param_2 != '\0') {
      FUN_00464458(param_1);
    }
    FUN_00445950((int)param_1,(char)param_1[0x84]);
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

