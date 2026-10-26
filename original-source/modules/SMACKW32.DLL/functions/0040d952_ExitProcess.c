/*
 * KERNEL32.DLL::ExitProcess at 0040d952
 * noreturn void __stdcall ExitProcess(UINT uExitCode)
 * Address ranges: 0040d952-0040d957
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ExitProcess
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 */

void ExitProcess(UINT uExitCode)

{
                    /* WARNING: Could not recover jumptable at 0x0040d952. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  ExitProcess(uExitCode);
  return;
}

