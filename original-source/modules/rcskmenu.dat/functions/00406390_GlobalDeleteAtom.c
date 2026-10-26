/*
 * KERNEL32.DLL::GlobalDeleteAtom at 00406390
 * ATOM __stdcall GlobalDeleteAtom(ATOM nAtom)
 * Address ranges: 00406390-00406395
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GlobalDeleteAtom
 */

ATOM __stdcall GlobalDeleteAtom(ATOM nAtom)

{
  ATOM AVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406390. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVar1 = GlobalDeleteAtom(nAtom);
  return AVar1;
}

