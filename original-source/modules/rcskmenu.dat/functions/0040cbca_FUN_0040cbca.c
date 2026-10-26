/*
 * FUN_0040cbca at 0040cbca
 * undefined __register FUN_0040cbca(void)
 * Address ranges: 0040cbca-0040cbe5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040cbca(void)

{
  int unaff_EBP;
  char *unaff_ESI;
  
  while( true ) {
    if ((byte)(*unaff_ESI - 0x3aU) < 0xf6) break;
    *(uint *)(unaff_EBP + -4) = (uint)(byte)(*unaff_ESI - 0x30);
    unaff_ESI = unaff_ESI + 1;
  }
  return;
}

