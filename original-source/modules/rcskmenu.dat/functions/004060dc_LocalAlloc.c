/*
 * KERNEL32.DLL::LocalAlloc at 004060dc
 * HLOCAL __stdcall LocalAlloc(UINT uFlags, SIZE_T uBytes)
 * Address ranges: 004060dc-004060e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::LocalAlloc
 */

HLOCAL __stdcall LocalAlloc(UINT uFlags,SIZE_T uBytes)

{
  HLOCAL pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004060dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = LocalAlloc(uFlags,uBytes);
  return pvVar1;
}

