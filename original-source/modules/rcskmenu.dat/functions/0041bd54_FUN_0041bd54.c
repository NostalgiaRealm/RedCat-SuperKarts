/*
 * FUN_0041bd54 at 0041bd54
 * undefined __register FUN_0041bd54(int * param_1)
 * Address ranges: 0041bd54-0041bd72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bd54(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1[1] = param_1[1] + -1, param_1[1] == 0)) {
    (**(code **)*param_1)();
    FUN_00402eac(param_1);
  }
  return;
}

