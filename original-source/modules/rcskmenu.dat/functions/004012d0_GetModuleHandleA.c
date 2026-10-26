/*
 * KERNEL32.DLL::GetModuleHandleA at 004012d0
 * HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
 * Address ranges: 004012d0-004012d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetModuleHandleA
 */

HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)

{
  HMODULE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004012d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetModuleHandleA(lpModuleName);
  return pHVar1;
}

