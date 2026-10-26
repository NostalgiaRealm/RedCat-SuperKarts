/*
 * OLEAUT32.DLL::SysStringLen at 00401360
 * UINT __stdcall SysStringLen(BSTR param_1)
 * Address ranges: 00401360-00401365
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLEAUT32.DLL::SysStringLen
 */

UINT __stdcall SysStringLen(BSTR param_1)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = SysStringLen(param_1);
  return UVar1;
}

