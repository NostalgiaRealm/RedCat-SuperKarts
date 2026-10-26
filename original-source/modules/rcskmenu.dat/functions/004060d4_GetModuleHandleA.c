/*
 * KERNEL32.DLL::GetModuleHandleA at 004060d4
 * HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
 * Address ranges: 004060d4-004060d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetModuleHandleA
 */

HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)

{
  HMODULE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004060d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetModuleHandleA(lpModuleName);
  return pHVar1;
}

