/*
 * __amsg_exit at 00401bf8
 * void __cdecl __amsg_exit(int param_1)
 * Address ranges: 00401bf8-00401c19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __amsg_exit  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00408c58 == 1) {
    FUN_00404384();
  }
  FUN_004043bd(param_1);
  (*(code *)PTR___exit_00408240)(0xff);
  return;
}

