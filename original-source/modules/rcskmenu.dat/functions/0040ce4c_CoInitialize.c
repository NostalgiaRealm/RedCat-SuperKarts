/*
 * OLE32.DLL::CoInitialize at 0040ce4c
 * HRESULT __stdcall CoInitialize(LPVOID pvReserved)
 * Address ranges: 0040ce4c-0040ce51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLE32.DLL::CoInitialize
 */

HRESULT __stdcall CoInitialize(LPVOID pvReserved)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040ce4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = CoInitialize(pvReserved);
  return HVar1;
}

