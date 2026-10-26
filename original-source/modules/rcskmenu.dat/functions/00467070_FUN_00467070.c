/*
 * FUN_00467070 at 00467070
 * undefined __register FUN_00467070(int param_1)
 * Address ranges: 00467070-004670ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467070(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_004674c4(param_1);
  if (-1 < iVar2 + -1) {
    iVar4 = 0;
    do {
      iVar3 = FUN_004674ac(param_1,iVar4);
      bVar1 = *(byte *)(iVar3 + 0x1fa);
      iVar3 = FUN_004674ac(param_1,iVar4);
      FUN_00466f7c(iVar3,bVar1);
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

