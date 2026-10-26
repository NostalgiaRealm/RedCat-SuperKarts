/*
 * FUN_0044de90 at 0044de90
 * undefined __register FUN_0044de90(undefined4 * param_1)
 * Address ranges: 0044de90-0044dea4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044de90(undefined4 *param_1)

{
  if (*(char *)(param_1 + 2) == '\0') {
    FUN_0044df24(param_1);
    return;
  }
  (**(code **)(*(int *)param_1[1] + 8))();
  return;
}

