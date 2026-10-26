/*
 * KERNEL32.DLL::ExitProcess at 00401288
 * noreturn void __stdcall ExitProcess(UINT uExitCode)
 * Address ranges: 00401288-0040128d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ExitProcess
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 */

void __stdcall ExitProcess(UINT uExitCode)

{
                    /* WARNING: Could not recover jumptable at 0x00401288. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  ExitProcess(uExitCode);
  return;
}

