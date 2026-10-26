/*
 * FUN_00405609 at 00405609
 * undefined FUN_00405609(void)
 * Address ranges: 00405609-00405639
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405609(int param_1)

{
  int *piVar1;
  
  FUN_004afce0(s_2_baans_004de230);
  piVar1 = (int *)(DAT_00504f98 + 0x3c + param_1 * 0x6c);
  if (2 < *piVar1) {
    *piVar1 = 2;
    return;
  }
  return;
}

