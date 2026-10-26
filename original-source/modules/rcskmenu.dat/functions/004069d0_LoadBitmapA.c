/*
 * USER32.DLL::LoadBitmapA at 004069d0
 * HBITMAP __stdcall LoadBitmapA(HINSTANCE hInstance, LPCSTR lpBitmapName)
 * Address ranges: 004069d0-004069d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::LoadBitmapA
 */

HBITMAP __stdcall LoadBitmapA(HINSTANCE hInstance,LPCSTR lpBitmapName)

{
  HBITMAP pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004069d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = LoadBitmapA(hInstance,lpBitmapName);
  return pHVar1;
}

