/*
 * USER32.DLL::GetMenuItemID at 004068b0
 * UINT __stdcall GetMenuItemID(HMENU hMenu, int nPos)
 * Address ranges: 004068b0-004068b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetMenuItemID
 */

UINT __stdcall GetMenuItemID(HMENU hMenu,int nPos)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = GetMenuItemID(hMenu,nPos);
  return UVar1;
}

