/*
 * USER32.DLL::GetMenuStringA at 004068c8
 * int __stdcall GetMenuStringA(HMENU hMenu, UINT uIDItem, LPSTR lpString, int cchMax, UINT flags)
 * Address ranges: 004068c8-004068cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetMenuStringA
 */

int __stdcall GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,int cchMax,UINT flags)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetMenuStringA(hMenu,uIDItem,lpString,cchMax,flags);
  return iVar1;
}

