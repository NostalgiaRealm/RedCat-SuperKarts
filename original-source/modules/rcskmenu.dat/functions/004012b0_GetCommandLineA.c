/*
 * KERNEL32.DLL::GetCommandLineA at 004012b0
 * LPSTR __stdcall GetCommandLineA(void)
 * Address ranges: 004012b0-004012b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCommandLineA
 */

LPSTR __stdcall GetCommandLineA(void)

{
  LPSTR pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004012b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetCommandLineA();
  return pCVar1;
}

