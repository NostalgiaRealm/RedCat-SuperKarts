/*
 * GDI32.DLL::GetTextExtentPoint32A at 004065b0
 * BOOL __stdcall GetTextExtentPoint32A(HDC hdc, LPCSTR lpString, int c, LPSIZE psizl)
 * Address ranges: 004065b0-004065b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetTextExtentPoint32A
 */

BOOL __stdcall GetTextExtentPoint32A(HDC hdc,LPCSTR lpString,int c,LPSIZE psizl)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetTextExtentPoint32A(hdc,lpString,c,psizl);
  return BVar1;
}

