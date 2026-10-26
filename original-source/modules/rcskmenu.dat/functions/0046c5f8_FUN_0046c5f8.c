/*
 * FUN_0046c5f8 at 0046c5f8
 * undefined __register FUN_0046c5f8(int param_1)
 * Address ranges: 0046c5f8-0046c62f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046c5f8(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = 0;
  do {
    bVar2 = 0;
    do {
      FUN_00402eac(*(int **)(param_1 + (uint)bVar1 * 0x10 + 0x1fc + (uint)bVar2 * 4));
      bVar2 = bVar2 + 1;
    } while (bVar2 != 3);
    bVar1 = bVar1 + 1;
  } while (bVar1 != 9);
  return;
}

