/*
 * OLEAUT32.DLL::SysReAllocStringLen at 00401350
 * INT __stdcall SysReAllocStringLen(BSTR * pbstr, OLECHAR * psz, uint len)
 * Address ranges: 00401350-00401355
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLEAUT32.DLL::SysReAllocStringLen
 */

INT __stdcall SysReAllocStringLen(BSTR *pbstr,OLECHAR *psz,uint len)

{
  INT IVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = SysReAllocStringLen(pbstr,psz,len);
  return IVar1;
}

