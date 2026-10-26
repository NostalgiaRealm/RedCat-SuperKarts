/*
 * FUN_00453740 at 00453740
 * undefined FUN_00453740(void)
 * Address ranges: 00453740-0045377a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453740(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_004503c0();
  iVar2 = FUN_0044fe20();
  if (iVar2 < iVar1 + 1) {
    uVar3 = FUN_0044fe20();
    FUN_004503a0(uVar3);
    return;
  }
  iVar1 = FUN_004503c0();
  FUN_004503a0(iVar1 + 1);
  return;
}

