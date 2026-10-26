/*
 * KERNEL32.DLL::GetDateFormatA at 004062f8
 * int __stdcall GetDateFormatA(LCID Locale, DWORD dwFlags, SYSTEMTIME * lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate)
 * Address ranges: 004062f8-004062fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetDateFormatA
 */

int __stdcall
GetDateFormatA(LCID Locale,DWORD dwFlags,SYSTEMTIME *lpDate,LPCSTR lpFormat,LPSTR lpDateStr,
              int cchDate)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDateFormatA(Locale,dwFlags,lpDate,lpFormat,lpDateStr,cchDate);
  return iVar1;
}

