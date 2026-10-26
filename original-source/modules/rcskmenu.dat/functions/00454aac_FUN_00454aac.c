/*
 * FUN_00454aac at 00454aac
 * undefined __register FUN_00454aac(int param_1, int param_2)
 * Address ranges: 00454aac-00454ad7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454aac(int param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    FUN_0040282c((undefined4 *)(param_2 + 4 + (uint)bVar1 * 5),
                 (undefined4 *)(param_1 + 4 + (uint)bVar1 * 5),5);
    bVar1 = bVar1 + 1;
  } while (bVar1 != 6);
  return;
}

