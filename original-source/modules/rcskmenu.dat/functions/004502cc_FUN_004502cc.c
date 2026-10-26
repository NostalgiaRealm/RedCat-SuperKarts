/*
 * FUN_004502cc at 004502cc
 * int __register FUN_004502cc(int param_1, int param_2)
 * Address ranges: 004502cc-004502d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004502cc(int param_1,int param_2)

{
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return param_1;
}

