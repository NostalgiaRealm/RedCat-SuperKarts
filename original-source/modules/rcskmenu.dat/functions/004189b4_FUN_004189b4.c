/*
 * FUN_004189b4 at 004189b4
 * undefined __register FUN_004189b4(int param_1)
 * Address ranges: 004189b4-00418a09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004189b4(int param_1)

{
  if ((*(HDC *)(param_1 + 4) != (HDC)0x0) &&
     (*(byte *)(param_1 + 8) != (*(byte *)(param_1 + 8) & 0xf1))) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_0047d688);
    SelectObject(*(HDC *)(param_1 + 4),DAT_0047d68c);
    SelectObject(*(HDC *)(param_1 + 4),DAT_0047d690);
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) & 0xf1;
  }
  return;
}

