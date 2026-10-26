/*
 * KERNEL32.DLL::TlsFree at 0040d8c8
 * BOOL __stdcall TlsFree(DWORD dwTlsIndex)
 * Address ranges: 0040d8c8-0040d8cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsFree
 */

BOOL TlsFree(DWORD dwTlsIndex)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = TlsFree(dwTlsIndex);
  return BVar1;
}

