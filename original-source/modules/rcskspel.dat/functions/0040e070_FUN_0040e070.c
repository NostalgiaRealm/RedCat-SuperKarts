/*
 * FUN_0040e070 at 0040e070
 * undefined FUN_0040e070(void)
 * Address ranges: 0040e070-0040e0ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040e070(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0040e030(param_1);
  if ((char)iVar1 != '\0') {
    iVar2 = FUN_004be6c9();
    iVar1 = iVar2 / 3;
    iVar2 = iVar2 % 3;
    if (iVar2 == 0) {
      iVar1 = FUN_0040f350(param_1);
    }
    else {
      if (iVar2 == 1) {
        iVar1 = FUN_0040f320(param_1);
        return iVar1;
      }
      if (iVar2 == 2) {
        iVar1 = FUN_0040f380(param_1);
        return iVar1;
      }
    }
  }
  return iVar1;
}

