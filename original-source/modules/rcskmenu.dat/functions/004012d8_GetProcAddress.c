/*
 * KERNEL32.DLL::GetProcAddress at 004012d8
 * FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
 * Address ranges: 004012d8-004012dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetProcAddress
 */

FARPROC __stdcall GetProcAddress(HMODULE hModule,LPCSTR lpProcName)

{
  FARPROC pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004012d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = GetProcAddress(hModule,lpProcName);
  return pFVar1;
}

