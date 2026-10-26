/*
 * USER32.DLL::DeleteMenu at 00406748
 * BOOL __stdcall DeleteMenu(HMENU hMenu, UINT uPosition, UINT uFlags)
 * Address ranges: 00406748-0040674d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DeleteMenu
 */

BOOL __stdcall DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DeleteMenu(hMenu,uPosition,uFlags);
  return BVar1;
}

