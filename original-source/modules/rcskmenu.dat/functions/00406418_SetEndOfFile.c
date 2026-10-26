/*
 * KERNEL32.DLL::SetEndOfFile at 00406418
 * BOOL __stdcall SetEndOfFile(HANDLE hFile)
 * Address ranges: 00406418-0040641d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetEndOfFile
 */

BOOL __stdcall SetEndOfFile(HANDLE hFile)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetEndOfFile(hFile);
  return BVar1;
}

