/*
 * GDI32.DLL::GetClipBox at 00406540
 * int __stdcall GetClipBox(HDC hdc, LPRECT lprect)
 * Address ranges: 00406540-00406545
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetClipBox
 */

int __stdcall GetClipBox(HDC hdc,LPRECT lprect)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetClipBox(hdc,lprect);
  return iVar1;
}

