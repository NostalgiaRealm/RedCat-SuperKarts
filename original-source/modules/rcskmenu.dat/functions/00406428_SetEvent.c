/*
 * KERNEL32.DLL::SetEvent at 00406428
 * BOOL __stdcall SetEvent(HANDLE hEvent)
 * Address ranges: 00406428-0040642d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetEvent
 */

BOOL __stdcall SetEvent(HANDLE hEvent)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetEvent(hEvent);
  return BVar1;
}

