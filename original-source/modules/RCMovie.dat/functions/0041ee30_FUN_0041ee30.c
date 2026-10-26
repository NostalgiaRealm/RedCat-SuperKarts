/*
 * FUN_0041ee30 at 0041ee30
 * char __fastcall FUN_0041ee30(int * param_1)
 * Address ranges: 0041ee30-0041ee7c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char __fastcall FUN_0041ee30(int *param_1)

{
  char cVar1;
  
  if (DAT_0043d534 == 0) {
    return '\x01';
  }
  cVar1 = (**(code **)(*param_1 + 0x14))();
  if (cVar1 == '\x01') {
    if (*(int **)((int)param_1 + 5) == (int *)0x0) {
      FUN_004015a6((byte *)s__s__d____Video_stream_has_no_ass_00436fcc);
      return '\0';
    }
    FUN_0041f210(*(int **)((int)param_1 + 5));
  }
  return cVar1;
}

