/*
 * FUN_00430d18 at 00430d18
 * undefined FUN_00430d18(void)
 * Address ranges: 00430d18-00430d73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430d18(void)

{
  HANDLE pvVar1;
  DWORD DVar2;
  tagPOINT tStack_c;
  
  DAT_0047d784 = GetCurrentThreadId();
  while( true ) {
    DVar2 = WaitForSingleObject(DAT_0047d788,100);
    if (DVar2 != 0x102) break;
    if ((DAT_0047d770 != 0) && (*(int *)(DAT_0047d770 + 0x50) != 0)) {
      GetCursorPos(&tStack_c);
      pvVar1 = FUN_0043e07c(&tStack_c);
      if (pvVar1 == (HANDLE)0x0) {
        FUN_00432e8c(DAT_0047d770);
      }
    }
  }
  return;
}

