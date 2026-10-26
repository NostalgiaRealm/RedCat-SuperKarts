/*
 * FUN_0044ff18 at 0044ff18
 * undefined FUN_0044ff18(void)
 * Address ranges: 0044ff18-0044ff44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044ff18(int param_1,undefined *param_2,undefined *param_3)

{
  LPCSTR lpFileName;
  LPCSTR lpKeyName;
  LPCSTR lpAppName;
  LPCSTR lpString;
  
  lpFileName = FUN_00403f94(*(undefined **)(param_1 + 4));
  lpString = (LPCSTR)0x0;
  lpKeyName = FUN_00403f94(param_3);
  lpAppName = FUN_00403f94(param_2);
  WritePrivateProfileStringA(lpAppName,lpKeyName,lpString,lpFileName);
  return;
}

