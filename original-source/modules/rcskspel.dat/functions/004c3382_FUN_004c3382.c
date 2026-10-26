/*
 * FUN_004c3382 at 004c3382
 * undefined FUN_004c3382(void)
 * Address ranges: 004c3382-004c33d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c3382(int param_1)

{
  int iVar1;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d3c00;
  pcStack_10 = FUN_004c2aa4;
  local_14 = ExceptionList;
  if ((param_1 != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 4), iVar1 != 0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_004beb18(*(undefined4 *)(param_1 + 0x18),iVar1);
  }
  ExceptionList = local_14;
  return;
}

