/*
 * USER32.DLL::DestroyIcon at 00406758
 * BOOL __stdcall DestroyIcon(HICON hIcon)
 * Address ranges: 00406758-0040675d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DestroyIcon
 */

BOOL __stdcall DestroyIcon(HICON hIcon)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406758. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DestroyIcon(hIcon);
  return BVar1;
}

