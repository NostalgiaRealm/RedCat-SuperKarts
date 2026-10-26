/*
 * GDI32.DLL::RectVisible at 00406618
 * BOOL __stdcall RectVisible(HDC hdc, RECT * lprect)
 * Address ranges: 00406618-0040661d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::RectVisible
 */

BOOL __stdcall RectVisible(HDC hdc,RECT *lprect)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = RectVisible(hdc,lprect);
  return BVar1;
}

