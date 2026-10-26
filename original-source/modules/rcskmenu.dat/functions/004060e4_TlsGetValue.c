/*
 * KERNEL32.DLL::TlsGetValue at 004060e4
 * LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
 * Address ranges: 004060e4-004060e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsGetValue
 */

LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004060e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = TlsGetValue(dwTlsIndex);
  return pvVar1;
}

