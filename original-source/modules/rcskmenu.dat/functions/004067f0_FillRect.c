/*
 * USER32.DLL::FillRect at 004067f0
 * int __stdcall FillRect(HDC hDC, RECT * lprc, HBRUSH hbr)
 * Address ranges: 004067f0-004067f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::FillRect
 */

int __stdcall FillRect(HDC hDC,RECT *lprc,HBRUSH hbr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = FillRect(hDC,lprc,hbr);
  return iVar1;
}

