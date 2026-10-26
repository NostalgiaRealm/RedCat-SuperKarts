/*
 * GDI32.DLL::UnrealizeObject at 004066b8
 * BOOL __stdcall UnrealizeObject(HGDIOBJ h)
 * Address ranges: 004066b8-004066bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::UnrealizeObject
 */

BOOL __stdcall UnrealizeObject(HGDIOBJ h)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = UnrealizeObject(h);
  return BVar1;
}

