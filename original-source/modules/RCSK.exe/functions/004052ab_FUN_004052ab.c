/*
 * FUN_004052ab at 004052ab
 * int __cdecl FUN_004052ab(LPSTR param_1, WCHAR param_2)
 * Address ranges: 004052ab-00405312
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_004052ab(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_00408d98 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_00408da8,0x220,&param_2,1,lpMultiByteStr,DAT_00408aa0,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  DAT_00408c04 = 0x2a;
  return -1;
}

