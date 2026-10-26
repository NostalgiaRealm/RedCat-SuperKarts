/*
 * USER32.DLL::UnhookWindowsHookEx at 00406b80
 * BOOL __stdcall UnhookWindowsHookEx(HHOOK hhk)
 * Address ranges: 00406b80-00406b85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::UnhookWindowsHookEx
 */

BOOL __stdcall UnhookWindowsHookEx(HHOOK hhk)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = UnhookWindowsHookEx(hhk);
  return BVar1;
}

