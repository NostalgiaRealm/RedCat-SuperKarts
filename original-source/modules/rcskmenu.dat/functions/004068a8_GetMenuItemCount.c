/*
 * USER32.DLL::GetMenuItemCount at 004068a8
 * int __stdcall GetMenuItemCount(HMENU hMenu)
 * Address ranges: 004068a8-004068ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetMenuItemCount
 */

int __stdcall GetMenuItemCount(HMENU hMenu)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetMenuItemCount(hMenu);
  return iVar1;
}

