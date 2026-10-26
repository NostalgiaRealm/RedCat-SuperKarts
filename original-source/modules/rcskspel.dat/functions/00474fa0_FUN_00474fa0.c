/*
 * FUN_00474fa0 at 00474fa0
 * undefined FUN_00474fa0(void)
 * Address ranges: 00474fa0-004750ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __thiscall
FUN_00474fa0(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
            undefined1 *param_5,undefined1 *param_6,undefined1 *param_7)

{
  undefined1 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d09e6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_00412870(param_2,0,0xffffffff);
  local_4 = 0;
  param_1[0x10] = *param_3;
  FUN_0040b4f0(0);
  FUN_00412870(param_3,0,0xffffffff);
  local_4._0_1_ = 1;
  uVar1 = *param_4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  param_1[0x20] = uVar1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_00412870(param_4,0,0xffffffff);
  local_4._0_1_ = 2;
  param_1[0x30] = *param_5;
  FUN_0040b4f0(0);
  FUN_00412870(param_5,0,0xffffffff);
  local_4._0_1_ = 3;
  uVar1 = *param_6;
  *(undefined4 *)(param_1 + 0x44) = 0;
  param_1[0x40] = uVar1;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  FUN_00412870(param_6,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,4);
  param_1[0x50] = *param_7;
  if (*(int *)(param_7 + 4) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_7 + 8) - *(int *)(param_7 + 4) >> 2;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  pvVar2 = operator_new(iVar4 * 4);
  *(void **)(param_1 + 0x54) = pvVar2;
  uVar3 = FUN_00476950(*(undefined4 *)(param_7 + 4),*(undefined4 *)(param_7 + 8),pvVar2);
  *(undefined4 *)(param_1 + 0x58) = uVar3;
  *(undefined4 *)(param_1 + 0x5c) = uVar3;
  ExceptionList = local_c;
  return param_1;
}

