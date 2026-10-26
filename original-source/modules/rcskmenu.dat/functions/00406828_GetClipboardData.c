/*
 * USER32.DLL::GetClipboardData at 00406828
 * HANDLE __stdcall GetClipboardData(UINT uFormat)
 * Address ranges: 00406828-0040682d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetClipboardData
 */

HANDLE __stdcall GetClipboardData(UINT uFormat)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetClipboardData(uFormat);
  return pvVar1;
}

