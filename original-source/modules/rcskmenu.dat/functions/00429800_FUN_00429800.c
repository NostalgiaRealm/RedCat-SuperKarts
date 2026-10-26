/*
 * FUN_00429800 at 00429800
 * byte __register FUN_00429800(int param_1)
 * Address ranges: 00429800-00429844
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_00429800(int param_1)

{
  byte bVar1;
  
  bVar1 = (*(byte *)(param_1 + 0x10) & 0x80) != 0;
  if ((*(byte *)(param_1 + 0x11) & 0x80) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((*(byte *)(param_1 + 0x12) & 0x80) != 0) {
    bVar1 = bVar1 | 2;
  }
  if ((*(byte *)(param_1 + 1) & 0x80) != 0) {
    bVar1 = bVar1 | 8;
  }
  if ((*(byte *)(param_1 + 2) & 0x80) != 0) {
    bVar1 = bVar1 | 0x10;
  }
  if ((*(byte *)(param_1 + 4) & 0x80) != 0) {
    bVar1 = bVar1 | 0x20;
  }
  return bVar1;
}

