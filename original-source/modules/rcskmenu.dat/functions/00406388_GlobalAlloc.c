/*
 * KERNEL32.DLL::GlobalAlloc at 00406388
 * HGLOBAL __stdcall GlobalAlloc(UINT uFlags, SIZE_T dwBytes)
 * Address ranges: 00406388-0040638d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GlobalAlloc
 */

HGLOBAL __stdcall GlobalAlloc(UINT uFlags,SIZE_T dwBytes)

{
  HGLOBAL pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406388. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GlobalAlloc(uFlags,dwBytes);
  return pvVar1;
}

