/*
 * KERNEL32.DLL::LocalFree at 004013bc
 * HLOCAL __stdcall LocalFree(HLOCAL hMem)
 * Address ranges: 004013bc-004013c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::LocalFree
 */

HLOCAL __stdcall LocalFree(HLOCAL hMem)

{
  HLOCAL pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004013bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = LocalFree(hMem);
  return pvVar1;
}

