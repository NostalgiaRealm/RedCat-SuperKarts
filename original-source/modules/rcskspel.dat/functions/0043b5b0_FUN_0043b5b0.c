/*
 * FUN_0043b5b0 at 0043b5b0
 * undefined FUN_0043b5b0(void)
 * Address ranges: 0043b5b0-0043b5f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0043b5b0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_0053c1ec) {
    iVar2 = 0;
    do {
      iVar1 = FUN_0043b580(param_1,iVar2 + DAT_0053c1f0);
      if (iVar1 != 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x44;
    } while (iVar3 < DAT_0053c1ec);
  }
  return -1;
}

