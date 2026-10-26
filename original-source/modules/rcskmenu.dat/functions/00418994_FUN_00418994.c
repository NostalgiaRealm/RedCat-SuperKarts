/*
 * FUN_00418994 at 00418994
 * int __register FUN_00418994(int * param_1)
 * Address ranges: 00418994-004189af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00418994(int *param_1)

{
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,0xf);
  return param_1[1];
}

