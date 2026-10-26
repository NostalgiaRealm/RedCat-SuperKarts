/*
 * KERNEL32.DLL::GetVersionExA at 00406378
 * BOOL __stdcall GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)
 * Address ranges: 00406378-0040637d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetVersionExA
 */

BOOL __stdcall GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetVersionExA(lpVersionInformation);
  return BVar1;
}

