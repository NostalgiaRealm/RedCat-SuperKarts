/*
 * USER32.DLL::GetCursorPos at 00406838
 * BOOL __stdcall GetCursorPos(LPPOINT lpPoint)
 * Address ranges: 00406838-0040683d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetCursorPos
 */

BOOL __stdcall GetCursorPos(LPPOINT lpPoint)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406838. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetCursorPos(lpPoint);
  return BVar1;
}

