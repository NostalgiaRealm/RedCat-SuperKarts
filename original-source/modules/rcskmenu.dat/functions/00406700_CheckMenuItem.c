/*
 * USER32.DLL::CheckMenuItem at 00406700
 * DWORD __stdcall CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck)
 * Address ranges: 00406700-00406705
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CheckMenuItem
 */

DWORD __stdcall CheckMenuItem(HMENU hMenu,UINT uIDCheckItem,UINT uCheck)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = CheckMenuItem(hMenu,uIDCheckItem,uCheck);
  return DVar1;
}

