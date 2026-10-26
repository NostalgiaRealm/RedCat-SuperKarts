/*
 * FUN_00418efc at 00418efc
 * int __register FUN_00418efc(short param_1)
 * Address ranges: 00418efc-00418f1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00418efc(short param_1)

{
  if (((param_1 != 1) && (param_1 != 4)) && (param_1 != 8)) {
    return 0;
  }
  return 1 << ((byte)param_1 & 0x1f);
}

