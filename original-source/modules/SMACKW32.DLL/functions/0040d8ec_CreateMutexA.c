/*
 * KERNEL32.DLL::CreateMutexA at 0040d8ec
 * HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
 * Address ranges: 0040d8ec-0040d8f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CreateMutexA
 */

HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCSTR lpName)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateMutexA(lpMutexAttributes,bInitialOwner,lpName);
  return pvVar1;
}

