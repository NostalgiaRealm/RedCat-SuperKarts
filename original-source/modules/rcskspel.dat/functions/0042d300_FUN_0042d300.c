/*
 * FUN_0042d300 at 0042d300
 * undefined FUN_0042d300(void)
 * Address ranges: 0042d300-0042d357
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0042d300(void)

{
  int iVar1;
  
  __ftol();
  if (DAT_0053b9f4 == 0) {
    iVar1 = __ftol();
    return iVar1 * 1000;
  }
  iVar1 = __ftol();
  return iVar1 * 1000;
}

