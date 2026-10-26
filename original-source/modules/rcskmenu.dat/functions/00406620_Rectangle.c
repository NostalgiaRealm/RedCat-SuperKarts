/*
 * GDI32.DLL::Rectangle at 00406620
 * BOOL __stdcall Rectangle(HDC hdc, int left, int top, int right, int bottom)
 * Address ranges: 00406620-00406625
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::Rectangle
 */

BOOL __stdcall Rectangle(HDC hdc,int left,int top,int right,int bottom)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = Rectangle(hdc,left,top,right,bottom);
  return BVar1;
}

