/*
 * USER32.DLL::GetKeyboardState at 00406890
 * BOOL __stdcall GetKeyboardState(PBYTE lpKeyState)
 * Address ranges: 00406890-00406895
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetKeyboardState
 */

BOOL __stdcall GetKeyboardState(PBYTE lpKeyState)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406890. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetKeyboardState(lpKeyState);
  return BVar1;
}

