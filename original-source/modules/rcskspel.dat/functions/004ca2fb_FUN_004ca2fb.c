/*
 * FUN_004ca2fb at 004ca2fb
 * undefined FUN_004ca2fb(void)
 * Address ranges: 004ca2fb-004ca383
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004ca2fb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_006b69f4 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_006b69f4 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_006b69f4 != (FARPROC)0x0) {
        DAT_006b69f8 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_006b69fc = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_004ca34a;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_004ca34a:
    if (DAT_006b69f8 != (FARPROC)0x0) {
      iVar1 = (*DAT_006b69f8)();
      if ((iVar1 != 0) && (DAT_006b69fc != (FARPROC)0x0)) {
        iVar1 = (*DAT_006b69fc)(iVar1);
      }
    }
    iVar1 = (*DAT_006b69f4)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}

