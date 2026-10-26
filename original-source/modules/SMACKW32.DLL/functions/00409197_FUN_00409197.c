/*
 * FUN_00409197 at 00409197
 * undefined __stdcall FUN_00409197(void)
 * Address ranges: 00409197-004091cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409197(void)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  DWORD nNumberOfBytesToWrite;
  DWORD local_14;
  
  nNumberOfBytesToWrite = 0;
  pcVar2 = in_EAX;
  while (cVar1 = *pcVar2, pcVar2 = pcVar2 + 1, cVar1 != '\0') {
    nNumberOfBytesToWrite = nNumberOfBytesToWrite + 1;
  }
  WriteFile(*(HANDLE *)(DAT_004104f8 + 8),in_EAX,nNumberOfBytesToWrite,&local_14,(LPOVERLAPPED)0x0);
  FUN_004079ff(extraout_ECX,extraout_EDX);
  return;
}

