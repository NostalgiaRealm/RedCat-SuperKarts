/*
 * FUN_0043608c at 0043608c
 * undefined FUN_0043608c(void)
 * Address ranges: 0043608c-004360a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043608c(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x2c))();
  if (cVar1 != '\0') {
    *(undefined4 *)(param_1[6] + 0x48) = param_2;
  }
  return;
}

