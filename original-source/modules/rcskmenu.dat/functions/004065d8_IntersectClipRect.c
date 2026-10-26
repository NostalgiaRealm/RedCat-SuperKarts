/*
 * GDI32.DLL::IntersectClipRect at 004065d8
 * int __stdcall IntersectClipRect(HDC hdc, int left, int top, int right, int bottom)
 * Address ranges: 004065d8-004065dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::IntersectClipRect
 */

int __stdcall IntersectClipRect(HDC hdc,int left,int top,int right,int bottom)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = IntersectClipRect(hdc,left,top,right,bottom);
  return iVar1;
}

