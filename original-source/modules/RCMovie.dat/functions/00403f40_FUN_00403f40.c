/*
 * FUN_00403f40 at 00403f40
 * undefined __stdcall FUN_00403f40(void)
 * Address ranges: 00403f40-00403f5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403f40(void)

{
  HANDLE hProcess;
  
  hProcess = GetCurrentProcess();
  SetPriorityClass(hProcess,0x100);
  return;
}

