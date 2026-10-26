/*
 * FUN_004200a7 at 004200a7
 * undefined __cdecl FUN_004200a7(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3)
 * Address ranges: 004200a7-004200cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004200a7(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3)

{
  FUN_00423813(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}

