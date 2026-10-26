/*
 * USER32.DLL::IsDialogMessageA at 00406990
 * BOOL __stdcall IsDialogMessageA(HWND hDlg, LPMSG lpMsg)
 * Address ranges: 00406990-00406995
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::IsDialogMessageA
 */

BOOL __stdcall IsDialogMessageA(HWND hDlg,LPMSG lpMsg)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = IsDialogMessageA(hDlg,lpMsg);
  return BVar1;
}

