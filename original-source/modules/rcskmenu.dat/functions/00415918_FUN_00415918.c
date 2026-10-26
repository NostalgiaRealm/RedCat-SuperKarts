/*
 * FUN_00415918 at 00415918
 * int __register FUN_00415918(void)
 * Address ranges: 00415918-00415948
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00415918(void)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_0047d65c == 0) {
    FUN_004158b8();
  }
  if (DAT_0047d660 != (code *)0x0) {
    iVar2 = (*DAT_0047d660)();
    if (iVar2 != 0) {
      bVar1 = 1;
      goto LAB_00415943;
    }
  }
  bVar1 = 0;
LAB_00415943:
  return -(uint)bVar1;
}

