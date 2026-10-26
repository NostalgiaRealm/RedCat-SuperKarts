/*
 * USER32.DLL::GetSubMenu at 00406900
 * HMENU __stdcall GetSubMenu(HMENU hMenu, int nPos)
 * Address ranges: 00406900-00406905
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetSubMenu
 */

HMENU __stdcall GetSubMenu(HMENU hMenu,int nPos)

{
  HMENU pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetSubMenu(hMenu,nPos);
  return pHVar1;
}

