/*
 * KERNEL32.DLL::GetThreadLocale at 00406360
 * LCID __stdcall GetThreadLocale(void)
 * Address ranges: 00406360-00406365
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetThreadLocale
 */

LCID __stdcall GetThreadLocale(void)

{
  LCID LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = GetThreadLocale();
  return LVar1;
}

