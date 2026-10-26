/*
 * FUN_00408984 at 00408984
 * undefined __stdcall FUN_00408984(void)
 * Address ranges: 00408984-004089d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408984(void)

{
  HANDLE hObject;
  int in_EAX;
  LPVOID pvVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (DAT_0040ef40 != 0xffffffff) {
    pvVar1 = TlsGetValue(DAT_0040ef40);
    if (pvVar1 != (LPVOID)0x0) {
      hObject = *(HANDLE *)((int)pvVar1 + 0xde);
      FUN_00409107(extraout_ECX,extraout_EDX);
      TlsSetValue(DAT_0040ef40,(LPVOID)0x0);
      if ((hObject != (HANDLE)0x0) && (in_EAX != 0)) {
        CloseHandle(hObject);
      }
    }
  }
  return;
}

