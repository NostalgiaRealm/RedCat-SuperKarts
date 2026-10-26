/*
 * FUN_004b8350 at 004b8350
 * undefined FUN_004b8350(void)
 * Address ranges: 004b8350-004b837d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b8350(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_006ab88c != 0) {
    iVar2 = *param_1;
    while (-1 < iVar2) {
      FUN_004b7d60(iVar2);
      piVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      iVar2 = *piVar1;
    }
    return 0;
  }
  return 0;
}

