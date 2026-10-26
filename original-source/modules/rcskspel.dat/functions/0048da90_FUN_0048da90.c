/*
 * FUN_0048da90 at 0048da90
 * undefined FUN_0048da90(void)
 * Address ranges: 0048da90-0048daf3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0048da90(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d15c5;
  local_c = ExceptionList;
  if (DAT_0067e4d0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_0067e4d0 = 0;
    }
    else {
      DAT_0067e4d0 = FUN_0048da40(pvVar1);
    }
    FUN_0048da80();
  }
  ExceptionList = local_c;
  return DAT_0067e4d0;
}

