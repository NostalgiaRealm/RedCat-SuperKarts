/*
 * FUN_00486370 at 00486370
 * undefined FUN_00486370(void)
 * Address ranges: 00486370-004863d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00486370(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d147b;
  local_c = ExceptionList;
  if (DAT_005450cc == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(8);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_005450cc = FUN_00486330(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_005450cc = 0;
  }
  ExceptionList = local_c;
  return;
}

