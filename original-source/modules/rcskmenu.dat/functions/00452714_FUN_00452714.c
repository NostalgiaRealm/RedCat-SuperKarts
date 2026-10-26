/*
 * FUN_00452714 at 00452714
 * undefined __register FUN_00452714(int * param_1, char param_2)
 * Address ranges: 00452714-00452729
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452714(int *param_1,char param_2)

{
  if (param_2 != (char)param_1[0x22]) {
    *(char *)(param_1 + 0x22) = param_2;
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  return;
}

