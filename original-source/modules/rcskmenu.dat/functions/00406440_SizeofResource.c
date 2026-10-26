/*
 * KERNEL32.DLL::SizeofResource at 00406440
 * DWORD __stdcall SizeofResource(HMODULE hModule, HRSRC hResInfo)
 * Address ranges: 00406440-00406445
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SizeofResource
 */

DWORD __stdcall SizeofResource(HMODULE hModule,HRSRC hResInfo)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = SizeofResource(hModule,hResInfo);
  return DVar1;
}

