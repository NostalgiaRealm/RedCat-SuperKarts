/*
 * GDI32.DLL::CreateCompatibleBitmap at 004064b0
 * HBITMAP __stdcall CreateCompatibleBitmap(HDC hdc, int cx, int cy)
 * Address ranges: 004064b0-004064b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateCompatibleBitmap
 */

HBITMAP __stdcall CreateCompatibleBitmap(HDC hdc,int cx,int cy)

{
  HBITMAP pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateCompatibleBitmap(hdc,cx,cy);
  return pHVar1;
}

