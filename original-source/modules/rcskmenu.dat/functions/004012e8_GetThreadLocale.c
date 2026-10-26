/*
 * KERNEL32.DLL::GetThreadLocale at 004012e8
 * LCID __stdcall GetThreadLocale(void)
 * Address ranges: 004012e8-004012ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetThreadLocale
 */

LCID __stdcall GetThreadLocale(void)

{
  LCID LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004012e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = GetThreadLocale();
  return LVar1;
}

