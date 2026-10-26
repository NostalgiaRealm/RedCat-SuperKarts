/*
 * FUN_00446ecc at 00446ecc
 * undefined __register FUN_00446ecc(int param_1, short param_2)
 * Address ranges: 00446ecc-00446ee1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446ecc(int param_1,short param_2)

{
  if ((param_2 != *(short *)(param_1 + 0x60)) &&
     (*(short *)(param_1 + 0x60) = param_2, *(char *)(param_1 + 0x62) != '\0')) {
    FUN_00446db8(param_1);
  }
  return;
}

