/*
 * GDI32.DLL::GetTextMetricsA at 004065c0
 * BOOL __stdcall GetTextMetricsA(HDC hdc, LPTEXTMETRICA lptm)
 * Address ranges: 004065c0-004065c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetTextMetricsA
 */

BOOL __stdcall GetTextMetricsA(HDC hdc,LPTEXTMETRICA lptm)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetTextMetricsA(hdc,lptm);
  return BVar1;
}

