/*
 * FUN_00422030 at 00422030
 * undefined FUN_00422030(void)
 * Address ranges: 00422030-004220b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00422030(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(DAT_006a5c38 + param_1 * 0xa9 + 0xc) * 0x44;
  iVar1 = *(int *)(iVar3 + 0x2c + DAT_005090d0) * 0x4b;
  if (0x7ff < iVar1) {
    iVar1 = iVar1 + -0x7ff;
  }
  *(undefined4 *)(iVar3 + 0x24 + DAT_005090d0) = 0x50;
  *(int *)(iVar3 + 0x28 + DAT_005090d0) = iVar1;
  iVar1 = iVar3 + DAT_005090d0;
  FUN_0048f4e0();
  uVar2 = __ftol();
  *(undefined4 *)(iVar1 + 0x34) = uVar2;
  *(undefined4 *)(iVar3 + 0x40 + DAT_005090d0) = 0;
  return;
}

