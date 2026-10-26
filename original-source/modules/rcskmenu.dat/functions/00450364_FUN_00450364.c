/*
 * FUN_00450364 at 00450364
 * int __register FUN_00450364(uint param_1)
 * Address ranges: 00450364-00450394
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00450364(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while ((iVar1 < 0x1f && ((1 << ((byte)iVar1 & 0x1f) & param_1) == 0))) {
    iVar1 = iVar1 + 1;
  }
  iVar2 = 0;
  while ((1 << ((byte)iVar1 & 0x1f) & param_1) != 0) {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

