/*
 * KERNEL32.DLL::LoadResource at 004063e0
 * HGLOBAL __stdcall LoadResource(HMODULE hModule, HRSRC hResInfo)
 * Address ranges: 004063e0-004063e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::LoadResource
 */

HGLOBAL __stdcall LoadResource(HMODULE hModule,HRSRC hResInfo)

{
  HGLOBAL pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004063e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = LoadResource(hModule,hResInfo);
  return pvVar1;
}

