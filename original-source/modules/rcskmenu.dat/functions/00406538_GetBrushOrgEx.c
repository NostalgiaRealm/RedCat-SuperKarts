/*
 * GDI32.DLL::GetBrushOrgEx at 00406538
 * BOOL __stdcall GetBrushOrgEx(HDC hdc, LPPOINT lppt)
 * Address ranges: 00406538-0040653d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetBrushOrgEx
 */

BOOL __stdcall GetBrushOrgEx(HDC hdc,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406538. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetBrushOrgEx(hdc,lppt);
  return BVar1;
}

