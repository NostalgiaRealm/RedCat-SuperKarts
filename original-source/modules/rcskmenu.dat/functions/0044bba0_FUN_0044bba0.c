/*
 * FUN_0044bba0 at 0044bba0
 * undefined __register FUN_0044bba0(int * param_1, int param_2)
 * Address ranges: 0044bba0-0044bbb8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044bba0(int *param_1,int param_2)

{
  param_1[0x7f] = param_2;
  FUN_0044221c(param_1);
  (**(code **)(*param_1 + 0x74))();
  return;
}

