/*
 * GDI32.DLL::GetCurrentPositionEx at 00406548
 * BOOL __stdcall GetCurrentPositionEx(HDC hdc, LPPOINT lppt)
 * Address ranges: 00406548-0040654d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetCurrentPositionEx
 */

BOOL __stdcall GetCurrentPositionEx(HDC hdc,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetCurrentPositionEx(hdc,lppt);
  return BVar1;
}

