/*
 * OLEAUT32.DLL::SysAllocStringLen at 00401348
 * BSTR __stdcall SysAllocStringLen(OLECHAR * strIn, UINT ui)
 * Address ranges: 00401348-0040134d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLEAUT32.DLL::SysAllocStringLen
 */

BSTR __stdcall SysAllocStringLen(OLECHAR *strIn,UINT ui)

{
  BSTR pOVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pOVar1 = SysAllocStringLen(strIn,ui);
  return pOVar1;
}

