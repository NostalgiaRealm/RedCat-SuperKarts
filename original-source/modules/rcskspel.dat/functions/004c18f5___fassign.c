/*
 * __fassign at 004c18f5
 * void __cdecl __fassign(int flag, char * argument, char * number)
 * Address ranges: 004c18f5-004c1932
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __fassign  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (flag != 0) {
    FUN_004c93ac(&local_c);
    *(undefined4 *)argument = local_c;
    *(undefined4 *)(argument + 4) = local_8;
    return;
  }
  FUN_004c93d9(&number,number);
  *(char **)argument = number;
  return;
}

