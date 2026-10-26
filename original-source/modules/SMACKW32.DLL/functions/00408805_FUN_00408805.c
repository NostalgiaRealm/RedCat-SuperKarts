/*
 * FUN_00408805 at 00408805
 * undefined __stdcall FUN_00408805(void)
 * Address ranges: 00408805-00408861
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408805(void)

{
  undefined4 *in_EAX;
  DWORD DVar1;
  HANDLE pvVar2;
  LPSECURITY_ATTRIBUTES lpMutexAttributes;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 != in_EAX[2]) {
    if (in_EAX[1] == 0) {
      FUN_00408805();
      if (in_EAX[1] == 0) {
        pvVar2 = CreateMutexA(lpMutexAttributes,(BOOL)lpMutexAttributes,(LPCSTR)lpMutexAttributes);
        in_EAX[1] = 1;
        *in_EAX = pvVar2;
      }
      FUN_00408867();
    }
    WaitForSingleObject((HANDLE)*in_EAX,0xffffffff);
    in_EAX[2] = DVar1;
  }
  in_EAX[3] = in_EAX[3] + 1;
  return;
}

