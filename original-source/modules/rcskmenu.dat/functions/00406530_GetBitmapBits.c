/*
 * GDI32.DLL::GetBitmapBits at 00406530
 * LONG __stdcall GetBitmapBits(HBITMAP hbit, LONG cb, LPVOID lpvBits)
 * Address ranges: 00406530-00406535
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetBitmapBits
 */

LONG __stdcall GetBitmapBits(HBITMAP hbit,LONG cb,LPVOID lpvBits)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = GetBitmapBits(hbit,cb,lpvBits);
  return LVar1;
}

