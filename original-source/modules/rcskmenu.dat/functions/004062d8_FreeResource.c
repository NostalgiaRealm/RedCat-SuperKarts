/*
 * KERNEL32.DLL::FreeResource at 004062d8
 * BOOL __stdcall FreeResource(HGLOBAL hResData)
 * Address ranges: 004062d8-004062dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::FreeResource
 */

BOOL __stdcall FreeResource(HGLOBAL hResData)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FreeResource(hResData);
  return BVar1;
}

