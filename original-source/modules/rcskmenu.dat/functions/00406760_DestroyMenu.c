/*
 * USER32.DLL::DestroyMenu at 00406760
 * BOOL __stdcall DestroyMenu(HMENU hMenu)
 * Address ranges: 00406760-00406765
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DestroyMenu
 */

BOOL __stdcall DestroyMenu(HMENU hMenu)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DestroyMenu(hMenu);
  return BVar1;
}

