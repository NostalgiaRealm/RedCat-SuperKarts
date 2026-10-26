/*
 * FUN_0043e7e0 at 0043e7e0
 * undefined FUN_0043e7e0(void)
 * Address ranges: 0043e7e0-0043e800
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e7e0(int *param_1,undefined4 *param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x30))();
  if (cVar1 != '\0') {
    FUN_00403ba4((int *)(param_1[6] + 0x70),param_2);
  }
  return;
}

