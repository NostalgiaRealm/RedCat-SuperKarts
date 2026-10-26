/*
 * FUN_004050d0 at 004050d0
 * HMODULE __register FUN_004050d0(LPCSTR param_1)
 * Address ranges: 004050d0-0040519b;004051a3-0040528b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HMODULE FUN_004050d0(LPCSTR param_1)

{
  LSTATUS LVar1;
  char *pcVar2;
  HMODULE pHVar3;
  LCID Locale;
  LPSTR lpString1;
  undefined4 *in_FS_OFFSET;
  LPDWORD lpReserved;
  LPDWORD lpType;
  BYTE *lpData;
  DWORD *lpcbData;
  undefined4 uVar4;
  LCTYPE LCType;
  int iVar5;
  char local_121 [261];
  DWORD local_1c;
  BYTE local_16 [5];
  char local_11 [2];
  undefined1 local_f;
  HKEY local_c;
  LPCSTR local_8;
  
  local_8 = param_1;
  GetModuleFileNameA((HMODULE)0x0,local_121,0x105);
  local_16[0] = '\0';
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,"Software\\Borland\\Locales",0,0xf003f,&local_c);
  if (LVar1 != 0) {
    LVar1 = RegOpenKeyExA((HKEY)0x80000001,"Software\\Borland\\Delphi\\Locales",0,0xf003f,&local_c);
    if (LVar1 != 0) {
      lstrcpyA(local_121,local_8);
      iVar5 = 5;
      pcVar2 = local_11;
      LCType = 3;
      Locale = GetThreadLocale();
      GetLocaleInfoA(Locale,LCType,pcVar2,iVar5);
      pHVar3 = (HMODULE)0x0;
      if ((local_121[0] != '\0') && ((local_11[0] != '\0' || (local_16[0] != '\0')))) {
        iVar5 = lstrlenA(local_121);
        for (pcVar2 = local_121 + iVar5; (*pcVar2 != '.' && (pcVar2 != local_121));
            pcVar2 = pcVar2 + -1) {
        }
        if (pcVar2 != local_121) {
          lpString1 = pcVar2 + 1;
          if (local_16[0] != '\0') {
            lstrcpyA(lpString1,(LPCSTR)local_16);
            pHVar3 = LoadLibraryExA(local_121,(HANDLE)0x0,2);
          }
          if ((pHVar3 == (HMODULE)0x0) && (local_11[0] != '\0')) {
            lstrcpyA(lpString1,local_11);
            pHVar3 = LoadLibraryExA(local_121,(HANDLE)0x0,2);
            if (pHVar3 == (HMODULE)0x0) {
              local_f = 0;
              lstrcpyA(lpString1,local_11);
              pHVar3 = LoadLibraryExA(local_121,(HANDLE)0x0,2);
            }
          }
        }
      }
      return pHVar3;
    }
  }
  uVar4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xfffffec8;
  local_1c = 5;
  lpcbData = &local_1c;
  lpData = local_16;
  lpType = (LPDWORD)0x0;
  lpReserved = (LPDWORD)0x0;
  pcVar2 = FUN_00404f28(local_121);
  LVar1 = RegQueryValueExA(local_c,pcVar2,lpReserved,lpType,lpData,lpcbData);
  if (LVar1 != 0) {
    RegQueryValueExA(local_c,"",(LPDWORD)0x0,(LPDWORD)0x0,local_16,&local_1c);
  }
  *in_FS_OFFSET = uVar4;
  pHVar3 = (HMODULE)RegCloseKey(local_c);
  return pHVar3;
}

