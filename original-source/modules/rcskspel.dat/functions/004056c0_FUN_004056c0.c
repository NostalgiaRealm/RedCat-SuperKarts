/*
 * FUN_004056c0 at 004056c0
 * undefined FUN_004056c0(void)
 * Address ranges: 004056c0-004056c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004056c0(int param_1)

{
  int *piVar1;
  
  FUN_004afce0(s_2_baans_004de260);
  piVar1 = (int *)(DAT_00504f98 + 0x3c + param_1 * 0x6c);
  if (2 < *piVar1) {
    *piVar1 = 2;
    return;
  }
  return;
}

