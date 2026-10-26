/*
 * FUN_00404be0 at 00404be0
 * undefined FUN_00404be0(void)
 * Address ranges: 00404be0-00404c4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00404be0(int param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  FUN_0048f4e0();
  uVar1 = __ftol();
  iVar2 = param_1 * 0x50 + DAT_00680ae0;
  if (*(int *)(iVar2 + 0x14) != -1) {
    return *(int *)(iVar2 + 0x14);
  }
  uVar1 = uVar1 & 0x80000001;
  bVar3 = uVar1 == 0;
  if ((int)uVar1 < 0) {
    bVar3 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (bVar3) {
    if (*(int *)(iVar2 + 0x1c) != -1) {
      return *(int *)(iVar2 + 0x1c);
    }
    iVar2 = *(int *)(iVar2 + 0x18);
    if (iVar2 == -1) {
      return param_1;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x18) != -1) {
      return *(int *)(iVar2 + 0x18);
    }
    iVar2 = *(int *)(iVar2 + 0x1c);
    if (iVar2 == -1) {
      return param_1;
    }
  }
  return iVar2;
}

