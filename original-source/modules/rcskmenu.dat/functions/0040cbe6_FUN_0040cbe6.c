/*
 * FUN_0040cbe6 at 0040cbe6
 * undefined __register FUN_0040cbe6(void)
 * Address ranges: 0040cbe6-0040cc14
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040cbe6(void)

{
  char cVar1;
  uint uVar2;
  char *unaff_ESI;
  
  uVar2 = 0;
  if ((*unaff_ESI == '+') || (*unaff_ESI == '-')) {
    unaff_ESI = unaff_ESI + 1;
  }
  do {
    cVar1 = *unaff_ESI;
    if ((byte)(cVar1 - 0x3aU) < 0xf6) {
      return;
    }
    unaff_ESI = unaff_ESI + 1;
    uVar2 = uVar2 * 10 + (uint)(byte)(cVar1 - 0x30);
  } while (uVar2 < 500);
  return;
}

