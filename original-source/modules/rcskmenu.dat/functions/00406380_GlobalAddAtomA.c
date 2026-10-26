/*
 * KERNEL32.DLL::GlobalAddAtomA at 00406380
 * ATOM __stdcall GlobalAddAtomA(LPCSTR lpString)
 * Address ranges: 00406380-00406385
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GlobalAddAtomA
 */

ATOM __stdcall GlobalAddAtomA(LPCSTR lpString)

{
  ATOM AVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVar1 = GlobalAddAtomA(lpString);
  return AVar1;
}

