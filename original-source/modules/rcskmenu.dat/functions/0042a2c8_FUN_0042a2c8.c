/*
 * FUN_0042a2c8 at 0042a2c8
 * undefined __register FUN_0042a2c8(void)
 * Address ranges: 0042a2c8-0042a3cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a2c8(void)

{
  int *piVar1;
  int in_stack_00000004;
  
  piVar1 = (int *)(in_stack_00000004 + -4);
  FUN_00445724(*(int **)(*piVar1 + 4));
  FUN_0041f500();
  if (0 < *(int *)(*piVar1 + 0x24)) {
    FUN_00445724(*(int **)(*piVar1 + 4));
    FUN_0041f500();
  }
  if (0 < *(int *)(*piVar1 + 0x38)) {
    FUN_00445724(*(int **)(*piVar1 + 4));
    FUN_0041f500();
  }
  if (0 < *(int *)(*piVar1 + 0x30)) {
    FUN_00445724(*(int **)(*piVar1 + 4));
    FUN_0041f500();
  }
  FUN_00417210(*(uint *)(*piVar1 + 0x28));
  FUN_00445724(*(int **)(*piVar1 + 4));
  FUN_0041f500();
  return;
}

