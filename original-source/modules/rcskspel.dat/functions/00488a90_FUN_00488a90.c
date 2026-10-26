/*
 * FUN_00488a90 at 00488a90
 * undefined FUN_00488a90(void)
 * Address ranges: 00488a90-00488af3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00488a90(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d14db;
  local_c = ExceptionList;
  if (DAT_00545100 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_00545100 = 0;
    }
    else {
      DAT_00545100 = FUN_00488a40(pvVar1);
    }
    FUN_00488a80();
  }
  ExceptionList = local_c;
  return DAT_00545100;
}

