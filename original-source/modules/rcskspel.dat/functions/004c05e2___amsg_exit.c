/*
 * __amsg_exit at 004c05e2
 * void __cdecl __amsg_exit(int param_1)
 * Address ranges: 004c05e2-004c0603
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __amsg_exit  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_006b673c == 1) {
    FUN_004c7d1b();
  }
  FUN_004c7d54(param_1);
  (*(code *)PTR___exit_00502ae0)(0xff);
  return;
}

