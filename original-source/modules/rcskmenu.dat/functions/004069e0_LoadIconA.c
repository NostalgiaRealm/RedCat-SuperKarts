/*
 * USER32.DLL::LoadIconA at 004069e0
 * HICON __stdcall LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName)
 * Address ranges: 004069e0-004069e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::LoadIconA
 */

HICON __stdcall LoadIconA(HINSTANCE hInstance,LPCSTR lpIconName)

{
  HICON pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004069e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = LoadIconA(hInstance,lpIconName);
  return pHVar1;
}

