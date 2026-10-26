/*
 * FUN_0040f2f0 at 0040f2f0
 * undefined FUN_0040f2f0(void)
 * Address ranges: 0040f2f0-0040f316
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f2f0(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (0 < param_2) {
    puVar1 = (undefined1 *)(param_1 + 2);
    do {
      puVar1[-2] = 0;
      puVar1[-1] = 0;
      *puVar1 = 0;
      *(undefined4 *)(puVar1 + 2) = 0xffffffff;
      puVar1 = puVar1 + 8;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

