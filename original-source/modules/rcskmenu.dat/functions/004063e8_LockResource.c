/*
 * KERNEL32.DLL::LockResource at 004063e8
 * LPVOID __stdcall LockResource(HGLOBAL hResData)
 * Address ranges: 004063e8-004063ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::LockResource
 */

LPVOID __stdcall LockResource(HGLOBAL hResData)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004063e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = LockResource(hResData);
  return pvVar1;
}

