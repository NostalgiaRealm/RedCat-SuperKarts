/*
 * FUN_0041f500 at 0041f500
 * int __register FUN_0041f500(void)
 * Address ranges: 0041f500-0041f533
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041f500(void)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_0047d74c != (code *)0x0) {
    iVar2 = (*DAT_0047d74c)();
    if (iVar2 != 0) {
      bVar1 = 1;
      goto LAB_0041f52c;
    }
  }
  bVar1 = 0;
LAB_0041f52c:
  return -(uint)bVar1;
}

