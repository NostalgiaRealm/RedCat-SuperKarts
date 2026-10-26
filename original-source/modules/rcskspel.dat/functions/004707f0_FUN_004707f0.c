/*
 * FUN_004707f0 at 004707f0
 * undefined FUN_004707f0(void)
 * Address ranges: 004707f0-0047085c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004707f0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d07ff;
  local_c = ExceptionList;
  if (DAT_00544b9c == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x5b0);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_00544b9c = FUN_004704b0(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_00544b9c = 0;
  }
  ExceptionList = local_c;
  return;
}

