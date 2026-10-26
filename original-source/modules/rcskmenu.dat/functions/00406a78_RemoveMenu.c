/*
 * USER32.DLL::RemoveMenu at 00406a78
 * BOOL __stdcall RemoveMenu(HMENU hMenu, UINT uPosition, UINT uFlags)
 * Address ranges: 00406a78-00406a7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::RemoveMenu
 */

BOOL __stdcall RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = RemoveMenu(hMenu,uPosition,uFlags);
  return BVar1;
}

