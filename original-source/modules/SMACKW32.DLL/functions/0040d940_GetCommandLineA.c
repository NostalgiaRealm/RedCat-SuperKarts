/*
 * KERNEL32.DLL::GetCommandLineA at 0040d940
 * LPSTR __stdcall GetCommandLineA(void)
 * Address ranges: 0040d940-0040d945
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCommandLineA
 */

LPSTR GetCommandLineA(void)

{
  LPSTR pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetCommandLineA();
  return pCVar1;
}

