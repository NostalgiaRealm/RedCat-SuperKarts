/*
 * FUN_00441770 at 00441770
 * undefined FUN_00441770(void)
 * Address ranges: 00441770-0044178c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441770(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x2c))();
  if (cVar1 != '\0') {
    *(undefined4 *)(param_1[8] + 0x150) = param_2;
  }
  return;
}

