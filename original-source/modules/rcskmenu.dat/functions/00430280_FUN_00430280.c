/*
 * FUN_00430280 at 00430280
 * undefined __register FUN_00430280(int param_1, int param_2)
 * Address ranges: 00430280-004302c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430280(int param_1,int param_2)

{
  FUN_0040f848(*(int **)(param_1 + 0x44),param_2);
  FUN_0040f848(*(int **)(param_1 + 0x40),param_2);
  FUN_00432c30(DAT_0047d770);
  if ((*(int *)(*(int *)(param_1 + 0x44) + 8) == 0) && (*(int *)(DAT_0047d770 + 0x74) != 0)) {
    FUN_00446b34(*(int **)(DAT_0047d770 + 0x74));
  }
  return;
}

