/*
 * __amsg_exit at 0041f5cf
 * void __cdecl __amsg_exit(int param_1)
 * Address ranges: 0041f5cf-0041f5f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __amsg_exit  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0043e2bc == 1) {
    FUN_00421708();
  }
  FUN_00421741(param_1);
  (*(code *)PTR___exit_004370e0)(0xff);
  return;
}

