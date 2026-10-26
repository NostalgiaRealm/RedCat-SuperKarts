/*
 * USER32.DLL::GetMenuItemInfoA at 004068b8
 * BOOL __stdcall GetMenuItemInfoA(HMENU hmenu, UINT item, BOOL fByPosition, LPMENUITEMINFOA lpmii)
 * Address ranges: 004068b8-004068bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetMenuItemInfoA
 */

BOOL __stdcall GetMenuItemInfoA(HMENU hmenu,UINT item,BOOL fByPosition,LPMENUITEMINFOA lpmii)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetMenuItemInfoA(hmenu,item,fByPosition,lpmii);
  return BVar1;
}

