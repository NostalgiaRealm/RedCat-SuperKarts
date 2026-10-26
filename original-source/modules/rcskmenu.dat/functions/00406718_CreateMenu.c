/*
 * USER32.DLL::CreateMenu at 00406718
 * HMENU __stdcall CreateMenu(void)
 * Address ranges: 00406718-0040671d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CreateMenu
 */

HMENU __stdcall CreateMenu(void)

{
  HMENU pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406718. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateMenu();
  return pHVar1;
}

