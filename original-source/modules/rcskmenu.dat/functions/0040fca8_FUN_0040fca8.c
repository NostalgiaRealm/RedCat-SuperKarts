/*
 * FUN_0040fca8 at 0040fca8
 * undefined __register FUN_0040fca8(int * param_1, undefined4 * param_2)
 * Address ranges: 0040fca8-0040fcb9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fca8(int *param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    (**(code **)*param_2)(param_2,param_1);
    return;
  }
  FUN_0040fcbc(param_1,(int *)0x0);
  return;
}

