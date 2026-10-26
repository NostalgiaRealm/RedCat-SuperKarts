/*
 * FUN_0040f6d8 at 0040f6d8
 * undefined FUN_0040f6d8(void)
 * Address ranges: 0040f6d8-0040f708
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f6d8(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[3];
  if (iVar1 < 0x41) {
    if (iVar1 < 9) {
      iVar2 = 4;
    }
    else {
      iVar2 = 0x10;
    }
  }
  else {
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 3;
    }
    iVar2 = iVar2 >> 2;
  }
  FUN_0040f868(param_1,iVar2 + iVar1);
  return;
}

