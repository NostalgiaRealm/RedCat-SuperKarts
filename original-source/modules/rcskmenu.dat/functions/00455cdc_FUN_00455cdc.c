/*
 * FUN_00455cdc at 00455cdc
 * undefined __register FUN_00455cdc(int param_1)
 * Address ranges: 00455cdc-00455cf6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455cdc(int param_1)

{
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_0040272c(*(int *)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}

