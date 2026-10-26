/*
 * FUN_0047f750 at 0047f750
 * undefined FUN_0047f750(void)
 * Address ranges: 0047f750-0047f7bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047f750(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004d1240;
  local_c = ExceptionList;
  if (DAT_00545038 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xa0);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_00545038 = FUN_0047f4c0(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_00545038 = 0;
  }
  ExceptionList = local_c;
  return;
}

