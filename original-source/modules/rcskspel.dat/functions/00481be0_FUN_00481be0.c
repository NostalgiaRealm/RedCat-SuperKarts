/*
 * FUN_00481be0 at 00481be0
 * undefined FUN_00481be0(void)
 * Address ranges: 00481be0-00481d33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00481be0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  char unaff_retaddr;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004d1340;
  local_c = ExceptionList;
  if (DAT_005450a8 == (int *)0x0) {
    ExceptionList = &local_c;
    DAT_005450a8 = operator_new(0x100);
    if (DAT_005450a8 == (int *)0x0) {
      DAT_005450a8 = (int *)0x0;
    }
    else {
      DAT_005450a8[2] = (int)DAT_005450a8;
      DAT_005450a8[7] = 0;
      DAT_005450a8[8] = 0;
      DAT_005450a8[0x22] = -1;
      DAT_005450a8[9] = 0;
      DAT_005450a8[0x23] = -1;
      DAT_005450a8[0x27] = 0;
      *(undefined1 *)(DAT_005450a8 + 0x2a) = 1;
      DAT_005450a8[0x1f] = 0;
      DAT_005450a8[0x37] = 0;
      *DAT_005450a8 = (int)&PTR_FUN_004d2e94;
      DAT_005450a8[0x20] = 0;
      DAT_005450a8[0x21] = 0;
    }
    pvVar1 = operator_new(0xbc);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00483c70();
    }
    local_4 = 0xffffffff;
    (**(code **)(*DAT_005450a8 + 0xc))(param_1,param_2,uVar2,param_3);
    if (unaff_retaddr == '\0') {
      *(undefined1 *)(DAT_005450a8 + 0x2a) = 1;
    }
    ExceptionList = pvVar1;
    return 1;
  }
  return 0;
}

