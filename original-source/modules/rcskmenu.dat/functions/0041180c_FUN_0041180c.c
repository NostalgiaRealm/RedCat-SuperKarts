/*
 * FUN_0041180c at 0041180c
 * undefined __register FUN_0041180c(int * param_1, char param_2)
 * Address ranges: 0041180c-00411827
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041180c(int *param_1,char param_2)

{
  if (param_2 != (char)param_1[6]) {
    if (param_2 != '\0') {
      (**(code **)(*param_1 + 0x7c))();
    }
    *(char *)(param_1 + 6) = param_2;
  }
  return;
}

