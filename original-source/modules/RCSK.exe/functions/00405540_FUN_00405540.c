/*
 * FUN_00405540 at 00405540
 * int __cdecl FUN_00405540(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00405540-004055c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00405540(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00408d80 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00408d80 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00408d80 != (FARPROC)0x0) {
        DAT_00408d84 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_00408d88 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_0040558f;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_0040558f:
    if (DAT_00408d84 != (FARPROC)0x0) {
      iVar1 = (*DAT_00408d84)();
      if ((iVar1 != 0) && (DAT_00408d88 != (FARPROC)0x0)) {
        iVar1 = (*DAT_00408d88)(iVar1);
      }
    }
    iVar1 = (*DAT_00408d80)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}

