/*
 * FUN_00481ec0 at 00481ec0
 * undefined FUN_00481ec0(void)
 * Address ranges: 00481ec0-00481fd1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00481ec0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1355;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = operator_new(0x100);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[2] = (int)piVar1;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[0x22] = -1;
    piVar1[9] = 0;
    piVar1[0x23] = -1;
    piVar1[0x27] = 0;
    piVar1[0x1f] = 0;
    *(undefined1 *)(piVar1 + 0x2a) = 1;
    piVar1[0x37] = 0;
    *piVar1 = (int)&PTR_FUN_004d2ea8;
    piVar1[0x20] = 0;
    piVar1[0x21] = 0;
  }
  pvVar2 = operator_new(0xbc);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00483de0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar1 + 0xc))(param_1,param_2,uVar3,1);
  if (DAT_005450a0 == (int *)0x0) {
    piVar1[3] = 0;
    piVar1[4] = 0;
  }
  else {
    piVar1[3] = (int)DAT_005450a0;
    piVar1[4] = 0;
    *(int **)((int)DAT_005450a0 + 8) = piVar1 + 2;
  }
  DAT_005450a0 = piVar1 + 2;
  ExceptionList = pvVar2;
  return 1;
}

