/*
 * FUN_00429770 at 00429770
 * byte __register FUN_00429770(uint param_1)
 * Address ranges: 00429770-004297bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_00429770(uint param_1)

{
  SHORT SVar1;
  byte bVar2;
  
  bVar2 = (param_1 & 4) != 0;
  if ((param_1 & 8) != 0) {
    bVar2 = bVar2 | 4;
  }
  if ((param_1 & 1) != 0) {
    bVar2 = bVar2 | 8;
  }
  if ((param_1 & 2) != 0) {
    bVar2 = bVar2 | 0x10;
  }
  if ((param_1 & 0x10) != 0) {
    bVar2 = bVar2 | 0x20;
  }
  SVar1 = GetKeyState(0x12);
  if (SVar1 < 0) {
    bVar2 = bVar2 | 2;
  }
  return bVar2;
}

