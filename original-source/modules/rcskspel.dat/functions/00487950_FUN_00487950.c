/*
 * FUN_00487950 at 00487950
 * undefined FUN_00487950(void)
 * Address ranges: 00487950-004879b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00487950(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d14c6;
  local_c = ExceptionList;
  if (DAT_005450f8 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(8);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_005450f8 = FUN_00487910(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_005450f8 = 0;
  }
  ExceptionList = local_c;
  return;
}

