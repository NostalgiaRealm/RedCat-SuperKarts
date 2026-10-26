/*
 * FUN_0040320c at 0040320c
 * int * __register FUN_0040320c(int * param_1, char param_2)
 * Address ranges: 0040320c-0040321a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0040320c(int *param_1,char param_2)

{
  if (param_2 < '\x01') {
    return param_1;
  }
  (**(code **)(*param_1 + -0x18))();
  return param_1;
}

