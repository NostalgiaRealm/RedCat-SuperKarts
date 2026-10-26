/*
 * FUN_004371f0 at 004371f0
 * undefined FUN_004371f0(void)
 * Address ranges: 004371f0-00437259
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004371f0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd373;
  local_c = ExceptionList;
  if (DAT_0053bf70 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_0053bf70 = FUN_00437040(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_0053bf70 = 0;
  }
  ExceptionList = local_c;
  return;
}

