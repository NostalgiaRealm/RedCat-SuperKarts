/*
 * GDI32.DLL::SelectObject at 00406638
 * HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ h)
 * Address ranges: 00406638-0040663d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SelectObject
 */

HGDIOBJ __stdcall SelectObject(HDC hdc,HGDIOBJ h)

{
  HGDIOBJ pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406638. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = SelectObject(hdc,h);
  return pvVar1;
}

