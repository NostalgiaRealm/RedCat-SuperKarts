/*
 * FUN_00454ad8 at 00454ad8
 * undefined __register FUN_00454ad8(int param_1)
 * Address ranges: 00454ad8-00454b00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454ad8(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = 0;
  do {
    bVar2 = 0;
    do {
      *(undefined1 *)(param_1 + (uint)bVar1 * 5 + 4 + (uint)bVar2) = 0;
      bVar2 = bVar2 + 1;
    } while (bVar2 != 5);
    bVar1 = bVar1 + 1;
  } while (bVar1 != 6);
  return;
}

