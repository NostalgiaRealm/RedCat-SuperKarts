/*
 * KERNEL32.DLL::InterlockedDecrement at 00401388
 * LONG __stdcall InterlockedDecrement(LONG * lpAddend)
 * Address ranges: 00401388-0040138d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::InterlockedDecrement
 */

LONG __stdcall InterlockedDecrement(LONG *lpAddend)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401388. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = InterlockedDecrement(lpAddend);
  return LVar1;
}

