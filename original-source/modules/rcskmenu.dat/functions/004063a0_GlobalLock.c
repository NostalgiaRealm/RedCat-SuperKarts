/*
 * KERNEL32.DLL::GlobalLock at 004063a0
 * LPVOID __stdcall GlobalLock(HGLOBAL hMem)
 * Address ranges: 004063a0-004063a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GlobalLock
 */

LPVOID __stdcall GlobalLock(HGLOBAL hMem)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004063a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GlobalLock(hMem);
  return pvVar1;
}

