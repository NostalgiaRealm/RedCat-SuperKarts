/*
 * FUN_00446170 at 00446170
 * undefined FUN_00446170(void)
 * Address ranges: 00446170-004461d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446170(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd697;
  local_c = ExceptionList;
  if (DAT_005437a4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_005437a4 = FUN_004460b0(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_005437a4 = 0;
  }
  ExceptionList = local_c;
  return;
}

