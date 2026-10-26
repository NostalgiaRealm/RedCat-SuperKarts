/*
 * FUN_004360a8 at 004360a8
 * undefined FUN_004360a8(void)
 * Address ranges: 004360a8-004360c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004360a8(int *param_1,undefined4 *param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x30))();
  if (cVar1 != '\0') {
    FUN_00403ba4((int *)(param_1[6] + 0x4c),param_2);
  }
  return;
}

