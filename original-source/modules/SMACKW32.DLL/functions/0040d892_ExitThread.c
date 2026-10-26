/*
 * KERNEL32.DLL::ExitThread at 0040d892
 * noreturn void __stdcall ExitThread(DWORD dwExitCode)
 * Address ranges: 0040d892-0040d897
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ExitThread
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 */

void ExitThread(DWORD dwExitCode)

{
                    /* WARNING: Could not recover jumptable at 0x0040d892. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  ExitThread(dwExitCode);
  return;
}

