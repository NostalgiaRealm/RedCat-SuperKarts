/*
 * FUN_00423f83 at 00423f83
 * undefined __cdecl FUN_00423f83(int param_1)
 * Address ranges: 00423f83-00423fd8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00423f83(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3e0;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_0041ffc0(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}

