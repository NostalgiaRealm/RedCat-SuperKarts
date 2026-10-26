/*
 * FUN_00481a80 at 00481a80
 * undefined FUN_00481a80(void)
 * Address ranges: 00481a80-00481bd3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00481a80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  char unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d132b;
  local_c = ExceptionList;
  if (DAT_005450a4 == (int *)0x0) {
    ExceptionList = &local_c;
    DAT_005450a4 = operator_new(0x100);
    if (DAT_005450a4 == (int *)0x0) {
      DAT_005450a4 = (int *)0x0;
    }
    else {
      DAT_005450a4[2] = (int)DAT_005450a4;
      DAT_005450a4[7] = 0;
      DAT_005450a4[8] = 0;
      DAT_005450a4[0x22] = -1;
      DAT_005450a4[9] = 0;
      DAT_005450a4[0x23] = -1;
      DAT_005450a4[0x27] = 0;
      *(undefined1 *)(DAT_005450a4 + 0x2a) = 1;
      DAT_005450a4[0x1f] = 0;
      DAT_005450a4[0x37] = 0;
      *DAT_005450a4 = (int)&PTR_FUN_004d2e80;
      DAT_005450a4[0x20] = 0;
      DAT_005450a4[0x21] = 0;
    }
    pvVar1 = operator_new(0xbc);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00483b10();
    }
    local_4 = 0xffffffff;
    (**(code **)(*DAT_005450a4 + 0xc))(param_1,param_2,uVar2,param_3);
    if (unaff_retaddr == '\0') {
      *(undefined1 *)(DAT_005450a4 + 0x2a) = 1;
    }
    ExceptionList = pvVar1;
    return 1;
  }
  return 0;
}

