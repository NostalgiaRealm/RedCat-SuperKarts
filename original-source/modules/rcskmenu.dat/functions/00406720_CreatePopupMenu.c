/*
 * USER32.DLL::CreatePopupMenu at 00406720
 * HMENU __stdcall CreatePopupMenu(void)
 * Address ranges: 00406720-00406725
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CreatePopupMenu
 */

HMENU __stdcall CreatePopupMenu(void)

{
  HMENU pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreatePopupMenu();
  return pHVar1;
}

