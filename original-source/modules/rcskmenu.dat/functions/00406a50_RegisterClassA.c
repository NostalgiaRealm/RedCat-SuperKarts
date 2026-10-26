/*
 * USER32.DLL::RegisterClassA at 00406a50
 * ATOM __stdcall RegisterClassA(WNDCLASSA * lpWndClass)
 * Address ranges: 00406a50-00406a55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::RegisterClassA
 */

ATOM __stdcall RegisterClassA(WNDCLASSA *lpWndClass)

{
  ATOM AVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVar1 = RegisterClassA(lpWndClass);
  return AVar1;
}

