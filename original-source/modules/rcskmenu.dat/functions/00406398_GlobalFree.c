/*
 * KERNEL32.DLL::GlobalFree at 00406398
 * HGLOBAL __stdcall GlobalFree(HGLOBAL hMem)
 * Address ranges: 00406398-0040639d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GlobalFree
 */

HGLOBAL __stdcall GlobalFree(HGLOBAL hMem)

{
  HGLOBAL pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GlobalFree(hMem);
  return pvVar1;
}

