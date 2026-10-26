/*
 * FUN_00445700 at 00445700
 * undefined __register FUN_00445700(int * param_1)
 * Address ranges: 00445700-00445723
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445700(int *param_1)

{
  if (param_1[0x53] == 0) {
    if ((int *)param_1[9] != (int *)0x0) {
      FUN_00445700((int *)param_1[9]);
    }
    (**(code **)(*param_1 + 0x8c))();
  }
  return;
}

