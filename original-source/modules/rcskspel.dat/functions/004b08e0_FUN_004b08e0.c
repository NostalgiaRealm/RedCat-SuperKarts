/*
 * FUN_004b08e0 at 004b08e0
 * undefined FUN_004b08e0(void)
 * Address ranges: 004b08e0-004b08f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b08e0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x6c))(param_1);
  }
  return;
}

