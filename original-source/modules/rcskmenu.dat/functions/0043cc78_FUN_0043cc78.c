/*
 * FUN_0043cc78 at 0043cc78
 * undefined FUN_0043cc78(void)
 * Address ranges: 0043cc78-0043cca9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cc78(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[2];
  if (-1 < iVar2 + -1) {
    iVar3 = 0;
    do {
      iVar1 = FUN_0040f6b0(param_1,iVar3);
      FUN_0040272c(iVar1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_0040f538(param_1);
  return;
}

