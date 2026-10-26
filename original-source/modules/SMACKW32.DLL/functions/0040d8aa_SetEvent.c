/*
 * KERNEL32.DLL::SetEvent at 0040d8aa
 * BOOL __stdcall SetEvent(HANDLE hEvent)
 * Address ranges: 0040d8aa-0040d8af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetEvent
 */

BOOL SetEvent(HANDLE hEvent)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetEvent(hEvent);
  return BVar1;
}

