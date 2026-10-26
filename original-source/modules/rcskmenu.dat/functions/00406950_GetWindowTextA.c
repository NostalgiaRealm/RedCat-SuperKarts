/*
 * USER32.DLL::GetWindowTextA at 00406950
 * int __stdcall GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount)
 * Address ranges: 00406950-00406955
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetWindowTextA
 */

int __stdcall GetWindowTextA(HWND hWnd,LPSTR lpString,int nMaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetWindowTextA(hWnd,lpString,nMaxCount);
  return iVar1;
}

