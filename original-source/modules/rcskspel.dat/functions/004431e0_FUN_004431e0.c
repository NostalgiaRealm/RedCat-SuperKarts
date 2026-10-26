/*
 * FUN_004431e0 at 004431e0
 * undefined FUN_004431e0(void)
 * Address ranges: 004431e0-00443294
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004431e0(void)

{
  int iVar1;
  _STARTUPINFOA *p_Var2;
  _PROCESS_INFORMATION local_254;
  _STARTUPINFOA local_244;
  CHAR local_200 [256];
  CHAR local_100 [256];
  
  p_Var2 = &local_244;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    p_Var2->cb = 0;
    p_Var2 = (_STARTUPINFOA *)&p_Var2->lpReserved;
  }
  local_254.hProcess = (HANDLE)0x0;
  local_244.cb = 0x44;
  local_254.hThread = (HANDLE)0x0;
  local_254.dwProcessId = 0;
  local_254.dwThreadId = 0;
  FUN_004b1d60(s_rrm_ini_004edda8);
  FUN_004b1f10(s_Modules_004eddb8,&DAT_004eddb0,local_200,0x100);
  FUN_004b1f10(s_Modules_004eddc8,s_Program_004eddc0,local_100,0x100);
  CreateProcessA((LPCSTR)0x0,local_100,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,
                 (LPVOID)0x0,local_200,&local_244,&local_254);
  CloseHandle(local_254.hProcess);
  CloseHandle(local_254.hThread);
  return;
}

