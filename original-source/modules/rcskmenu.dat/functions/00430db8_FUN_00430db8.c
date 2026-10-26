/*
 * FUN_00430db8 at 00430db8
 * undefined __register FUN_00430db8(undefined4 param_1, undefined4 param_2, DWORD param_3)
 * Address ranges: 00430db8-00430e2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430db8(undefined4 param_1,undefined4 param_2,DWORD param_3)

{
  DWORD dwThreadId;
  DWORD DStack_4;
  
  if (*(char *)(DAT_0047d770 + 0x95) == '\0') {
    DStack_4 = param_3;
    if (DAT_0047d78c == (HHOOK)0x0) {
      dwThreadId = GetCurrentThreadId();
      DAT_0047d78c = SetWindowsHookExA(3,FUN_00430d74,(HINSTANCE)0x0,dwThreadId);
    }
    if (DAT_0047d788 == (HANDLE)0x0) {
      DAT_0047d788 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
    }
    if (DAT_0047d790 == (HANDLE)0x0) {
      DAT_0047d790 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,1000,FUN_00430d18,(LPVOID)0x0,0,
                                  &DStack_4);
    }
  }
  return;
}

