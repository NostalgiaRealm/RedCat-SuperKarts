/*
 * FUN_004224b0 at 004224b0
 * undefined FUN_004224b0(void)
 * Address ranges: 004224b0-004224f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004224b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_006a5c38 + param_1 * 0xa9 + 0xc) * 0x44 + DAT_005090d0;
  FUN_0048f4e0();
  uVar1 = __ftol();
  *(undefined4 *)(iVar2 + 0x34) = uVar1;
  return;
}

