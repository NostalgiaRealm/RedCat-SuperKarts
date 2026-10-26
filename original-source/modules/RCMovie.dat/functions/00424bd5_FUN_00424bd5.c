/*
 * FUN_00424bd5 at 00424bd5
 * int __cdecl FUN_00424bd5(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00424bd5-00424c5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00424bd5(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0043e474 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_0043e474 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_0043e474 != (FARPROC)0x0) {
        DAT_0043e478 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_0043e47c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_00424c24;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_00424c24:
    if (DAT_0043e478 != (FARPROC)0x0) {
      iVar1 = (*DAT_0043e478)();
      if ((iVar1 != 0) && (DAT_0043e47c != (FARPROC)0x0)) {
        iVar1 = (*DAT_0043e47c)(iVar1);
      }
    }
    iVar1 = (*DAT_0043e474)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}

