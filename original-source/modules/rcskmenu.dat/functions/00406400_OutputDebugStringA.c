/*
 * KERNEL32.DLL::OutputDebugStringA at 00406400
 * void __stdcall OutputDebugStringA(LPCSTR lpOutputString)
 * Address ranges: 00406400-00406405
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::OutputDebugStringA
 */

void __stdcall OutputDebugStringA(LPCSTR lpOutputString)

{
                    /* WARNING: Could not recover jumptable at 0x00406400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OutputDebugStringA(lpOutputString);
  return;
}

