/*
 * FUN_00435a30 at 00435a30
 * undefined FUN_00435a30(void)
 * Address ranges: 00435a30-00435a97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00435a30(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd25b;
  local_c = ExceptionList;
  if (DAT_0053bee8 == (undefined4 *)0x0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x120);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_0053bee8 = (undefined4 *)0x0;
    }
    else {
      DAT_0053bee8 = (undefined4 *)FUN_004356f0(pvVar1);
    }
    *DAT_0053bee8 = DAT_0053be28;
  }
  ExceptionList = local_c;
  return DAT_0053bee8;
}

