/*
 * FUN_0048bc90 at 0048bc90
 * undefined FUN_0048bc90(void)
 * Address ranges: 0048bc90-0048bca7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048bc90(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}

