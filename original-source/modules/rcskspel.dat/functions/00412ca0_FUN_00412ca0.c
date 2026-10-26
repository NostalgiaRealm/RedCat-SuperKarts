/*
 * FUN_00412ca0 at 00412ca0
 * undefined FUN_00412ca0(void)
 * Address ranges: 00412ca0-00412ce0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412ca0(void)

{
  DWORD DVar1;
  DWORD DVar2;
  
  if (DAT_00505b40 != 0) {
    DVar1 = GetTickCount();
    DVar2 = GetTickCount();
    if (199 < DVar2 - DAT_00505b50) {
      DAT_00505b4c = (uint)(DAT_00505b4c == 0);
      DAT_00505b50 = DVar1;
    }
  }
  return;
}

