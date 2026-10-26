/*
 * USER32.DLL::ShowCursor at 00406b40
 * int __stdcall ShowCursor(BOOL bShow)
 * Address ranges: 00406b40-00406b45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ShowCursor
 */

int __stdcall ShowCursor(BOOL bShow)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ShowCursor(bShow);
  return iVar1;
}

