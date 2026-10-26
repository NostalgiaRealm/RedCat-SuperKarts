/*
 * FUN_00435030 at 00435030
 * undefined FUN_00435030(void)
 * Address ranges: 00435030-004350ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00435030(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __ftol();
  if (iVar1 < 18000) {
    return 0;
  }
  __ftol();
  iVar2 = (-(uint)(DAT_0053b9f4 != 2) & 0xfffffffa) + 0xc;
  iVar1 = __ftol();
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  return iVar1;
}

