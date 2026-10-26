/*
 * FUN_00430e2c at 00430e2c
 * undefined __register FUN_00430e2c(void)
 * Address ranges: 00430e2c-00430e87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430e2c(void)

{
  DWORD DVar1;
  
  if (DAT_0047d78c != (HHOOK)0x0) {
    UnhookWindowsHookEx(DAT_0047d78c);
  }
  DAT_0047d78c = (HHOOK)0x0;
  if (DAT_0047d790 != (HANDLE)0x0) {
    SetEvent(DAT_0047d788);
    DVar1 = GetCurrentThreadId();
    if (DVar1 != DAT_0047d784) {
      WaitForSingleObject(DAT_0047d790,0xffffffff);
    }
    CloseHandle(DAT_0047d790);
    DAT_0047d790 = (HANDLE)0x0;
  }
  return;
}

