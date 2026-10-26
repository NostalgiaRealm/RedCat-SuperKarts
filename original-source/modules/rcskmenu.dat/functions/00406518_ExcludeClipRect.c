/*
 * GDI32.DLL::ExcludeClipRect at 00406518
 * int __stdcall ExcludeClipRect(HDC hdc, int left, int top, int right, int bottom)
 * Address ranges: 00406518-0040651d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::ExcludeClipRect
 */

int __stdcall ExcludeClipRect(HDC hdc,int left,int top,int right,int bottom)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ExcludeClipRect(hdc,left,top,right,bottom);
  return iVar1;
}

