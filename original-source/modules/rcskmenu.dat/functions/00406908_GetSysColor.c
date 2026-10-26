/*
 * USER32.DLL::GetSysColor at 00406908
 * DWORD __stdcall GetSysColor(int nIndex)
 * Address ranges: 00406908-0040690d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetSysColor
 */

DWORD __stdcall GetSysColor(int nIndex)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetSysColor(nIndex);
  return DVar1;
}

