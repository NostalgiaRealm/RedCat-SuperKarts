/*
 * FUN_004297c4 at 004297c4
 * byte __register FUN_004297c4(uint param_1)
 * Address ranges: 004297c4-004297fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_004297c4(uint param_1)

{
  SHORT SVar1;
  byte bVar2;
  
  SVar1 = GetKeyState(0x10);
  bVar2 = SVar1 < 0;
  SVar1 = GetKeyState(0x11);
  if (SVar1 < 0) {
    bVar2 = bVar2 | 4;
  }
  if ((param_1 & 0x20000000) != 0) {
    bVar2 = bVar2 | 2;
  }
  return bVar2;
}

