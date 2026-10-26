/*
 * FUN_0040cbbf at 0040cbbf
 * undefined __register FUN_0040cbbf(void)
 * Address ranges: 0040cbbf-0040cbc9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040cbbf(void)

{
  char cVar1;
  char *unaff_ESI;
  
  do {
    cVar1 = *unaff_ESI;
    if (cVar1 == '\0') {
      return;
    }
    unaff_ESI = unaff_ESI + 1;
  } while (cVar1 == ' ');
  return;
}

