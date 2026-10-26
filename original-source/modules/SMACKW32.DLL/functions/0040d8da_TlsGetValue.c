/*
 * KERNEL32.DLL::TlsGetValue at 0040d8da
 * LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
 * Address ranges: 0040d8da-0040d8df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsGetValue
 */

LPVOID TlsGetValue(DWORD dwTlsIndex)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = TlsGetValue(dwTlsIndex);
  return pvVar1;
}

