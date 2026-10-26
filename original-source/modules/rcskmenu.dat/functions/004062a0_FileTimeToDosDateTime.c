/*
 * KERNEL32.DLL::FileTimeToDosDateTime at 004062a0
 * BOOL __stdcall FileTimeToDosDateTime(FILETIME * lpFileTime, LPWORD lpFatDate, LPWORD lpFatTime)
 * Address ranges: 004062a0-004062a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::FileTimeToDosDateTime
 */

BOOL __stdcall FileTimeToDosDateTime(FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FileTimeToDosDateTime(lpFileTime,lpFatDate,lpFatTime);
  return BVar1;
}

