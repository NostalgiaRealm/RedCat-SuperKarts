/*
 * FUN_0041f534 at 0041f534
 * int __register FUN_0041f534(void)
 * Address ranges: 0041f534-0041f55b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041f534(void)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_0047d750 != (code *)0x0) {
    iVar2 = (*DAT_0047d750)();
    if (iVar2 != 0) {
      bVar1 = 1;
      goto LAB_0041f554;
    }
  }
  bVar1 = 0;
LAB_0041f554:
  return -(uint)bVar1;
}

