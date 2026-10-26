/*
 * GDI32.DLL::LineTo at 004065e0
 * BOOL __stdcall LineTo(HDC hdc, int x, int y)
 * Address ranges: 004065e0-004065e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::LineTo
 */

BOOL __stdcall LineTo(HDC hdc,int x,int y)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = LineTo(hdc,x,y);
  return BVar1;
}

