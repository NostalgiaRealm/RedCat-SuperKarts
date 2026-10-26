/*
 * FUN_00404f28 at 00404f28
 * char * __register FUN_00404f28(char * param_1)
 * Address ranges: 00404f28-004050ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_00404f28(char *param_1)

{
  HMODULE hModule;
  int iVar1;
  char *pcVar2;
  LPCSTR pCVar3;
  HANDLE hFindFile;
  int iVar4;
  CHAR local_253 [261];
  undefined1 local_14e [322];
  char *local_c;
  char *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  hModule = GetModuleHandleA("kernel32.dll");
  if (((hModule == (HMODULE)0x0) ||
      (local_14e._318_4_ = GetProcAddress(hModule,"GetLongPathNameA"),
      (FARPROC)local_14e._318_4_ == (FARPROC)0x0)) ||
     (iVar1 = (*(code *)local_14e._318_4_)(), iVar1 == 0)) {
    if (*local_8 == '\\') {
      if (local_8[1] != '\\') {
        return local_c;
      }
      pcVar2 = (char *)thunk_FUN_00404f1c(local_8 + 2);
      if (*pcVar2 == '\0') {
        return local_c;
      }
      pcVar2 = (char *)thunk_FUN_00404f1c(pcVar2 + 1);
      if (*pcVar2 == '\0') {
        return local_c;
      }
    }
    else {
      pcVar2 = local_8 + 2;
    }
    iVar1 = (int)pcVar2 - (int)local_8;
    lstrcpynA(local_253,local_8,iVar1 + 1);
    while (*pcVar2 != '\0') {
      pCVar3 = (LPCSTR)thunk_FUN_00404f1c(pcVar2 + 1);
      if (0x105 < (int)(pCVar3 + (iVar1 - (int)pcVar2) + 1)) {
        return local_c;
      }
      lstrcpynA(local_253 + iVar1,pcVar2,(int)(pCVar3 + (1 - (int)pcVar2)));
      hFindFile = FindFirstFileA(local_253,(LPWIN32_FIND_DATAA)local_14e);
      if (hFindFile == (HANDLE)0xffffffff) {
        return local_c;
      }
      FindClose(hFindFile);
      iVar4 = lstrlenA(local_14e + 0x2c);
      if (0x105 < iVar4 + iVar1 + 2) {
        return local_c;
      }
      local_253[iVar1] = '\\';
      lstrcpyA(local_253 + iVar1 + 1,local_14e + 0x2c);
      iVar4 = lstrlenA(local_14e + 0x2c);
      iVar1 = iVar1 + iVar4 + 1;
      pcVar2 = pCVar3;
    }
    lstrcpyA(local_8,local_253);
  }
  else {
    lstrcpyA(local_8,local_253);
  }
  return local_c;
}

