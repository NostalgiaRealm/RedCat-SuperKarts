/*
 * KERNEL32.DLL::TlsAlloc at 0040d8d4
 * DWORD __stdcall TlsAlloc(void)
 * Address ranges: 0040d8d4-0040d8d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsAlloc
 */

DWORD TlsAlloc(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = TlsAlloc();
  return DVar1;
}

