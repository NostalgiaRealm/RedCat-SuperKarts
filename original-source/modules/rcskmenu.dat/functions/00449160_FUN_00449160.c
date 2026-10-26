/*
 * FUN_00449160 at 00449160
 * int __register FUN_00449160(int param_1, int param_2)
 * Address ranges: 00449160-00449166
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00449160(int param_1,int param_2)

{
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return param_1;
}

