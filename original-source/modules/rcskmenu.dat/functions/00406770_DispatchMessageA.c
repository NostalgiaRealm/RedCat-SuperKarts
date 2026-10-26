/*
 * USER32.DLL::DispatchMessageA at 00406770
 * LRESULT __stdcall DispatchMessageA(MSG * lpMsg)
 * Address ranges: 00406770-00406775
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DispatchMessageA
 */

LRESULT __stdcall DispatchMessageA(MSG *lpMsg)

{
  LRESULT LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = DispatchMessageA(lpMsg);
  return LVar1;
}

