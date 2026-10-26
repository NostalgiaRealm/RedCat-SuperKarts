/*
 * FUN_0040d8d1 at 0040d8d1
 * undefined __stdcall FUN_0040d8d1(void)
 * Address ranges: 0040d8d1-0040d900
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d8d1(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004322f0 + local_8 * 4) = 0xffffffff;
  }
  return;
}

