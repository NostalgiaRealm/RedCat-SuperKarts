/*
 * FUN_00423ff0 at 00423ff0
 * undefined __register FUN_00423ff0(int * param_1)
 * Address ranges: 00423ff0-00424027
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423ff0(int *param_1)

{
  if ((*(char *)((int)param_1 + 0x1f7) != '\0') && ((char)param_1[0x7d] == '\x01')) {
    param_1[0x10] = param_1[0x10] | 0x200;
    FUN_0042402c(param_1);
    return;
  }
  param_1[0x10] = param_1[0x10] & 0xfffffdff;
  return;
}

