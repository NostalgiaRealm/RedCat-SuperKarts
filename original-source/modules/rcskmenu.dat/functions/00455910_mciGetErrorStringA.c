/*
 * WINMM.DLL::mciGetErrorStringA at 00455910
 * BOOL __stdcall mciGetErrorStringA(MCIERROR mcierr, LPSTR pszText, UINT cchText)
 * Address ranges: 00455910-00455915
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to WINMM.DLL::mciGetErrorStringA
 */

BOOL __stdcall mciGetErrorStringA(MCIERROR mcierr,LPSTR pszText,UINT cchText)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00455910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = mciGetErrorStringA(mcierr,pszText,cchText);
  return BVar1;
}

