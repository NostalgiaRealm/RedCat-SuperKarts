/*
 * FUN_0044bb84 at 0044bb84
 * undefined __register FUN_0044bb84(int * param_1, undefined1 param_2)
 * Address ranges: 0044bb84-0044bb9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044bb84(int *param_1,undefined1 param_2)

{
  *(undefined1 *)((int)param_1 + 0x1fa) = param_2;
  FUN_0044221c(param_1);
  (**(code **)(*param_1 + 0x74))();
  return;
}

