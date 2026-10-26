/*
 * FUN_004336e4 at 004336e4
 * int __register FUN_004336e4(int param_1)
 * Address ranges: 004336e4-00433701
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004336e4(int param_1)

{
  if (param_1 == -0x1000000) {
    param_1 = 0x20000000;
  }
  else if (param_1 == -1) {
    return 0x1fffffff;
  }
  return param_1;
}

