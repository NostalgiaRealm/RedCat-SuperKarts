/*
 * GDI32.DLL::PatBlt at 004065f8
 * BOOL __stdcall PatBlt(HDC hdc, int x, int y, int w, int h, DWORD rop)
 * Address ranges: 004065f8-004065fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::PatBlt
 */

BOOL __stdcall PatBlt(HDC hdc,int x,int y,int w,int h,DWORD rop)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = PatBlt(hdc,x,y,w,h,rop);
  return BVar1;
}

