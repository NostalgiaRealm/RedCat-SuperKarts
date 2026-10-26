/*
 * FUN_00413234 at 00413234
 * undefined __stdcall FUN_00413234(void)
 * Address ranges: 00413234-00413262
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413234(void)

{
  int iVar1;
  
  if (DAT_0043400c != 0xffffffff) {
    do {
      iVar1 = FUN_004133f0(DAT_0043400c);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_0040a97d();
    } while (iVar1 == 0);
  }
  return;
}

