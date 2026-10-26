/*
 * FUN_004771b0 at 004771b0
 * undefined FUN_004771b0(void)
 * Address ranges: 004771b0-00477313
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004771b0(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d0c65;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined1 *)0x0) {
    ExceptionList = &local_c;
    *param_1 = *param_2;
    FUN_0040b4f0(0);
    FUN_00412870(param_2,0,0xffffffff);
    local_4._0_1_ = 1;
    param_1[0x10] = param_2[0x10];
    FUN_0040b4f0(0);
    FUN_00412870(param_2 + 0x10,0,0xffffffff);
    local_4._0_1_ = 2;
    param_1[0x20] = param_2[0x20];
    FUN_0040b4f0(0);
    FUN_00412870(param_2 + 0x20,0,0xffffffff);
    local_4._0_1_ = 3;
    param_1[0x30] = param_2[0x30];
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    FUN_00412870(param_2 + 0x30,0,0xffffffff);
    local_4._0_1_ = 4;
    param_1[0x40] = param_2[0x40];
    FUN_0040b4f0(0);
    FUN_00412870(param_2 + 0x40,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,5);
    param_1[0x50] = param_2[0x50];
    if (*(int *)(param_2 + 0x54) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_2 + 0x58) - *(int *)(param_2 + 0x54) >> 2;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    puVar2 = operator_new(iVar3 << 2);
    *(undefined4 **)(param_1 + 0x54) = puVar2;
    puVar1 = *(undefined4 **)(param_2 + 0x58);
    for (puVar4 = *(undefined4 **)(param_2 + 0x54); puVar4 != puVar1; puVar4 = puVar4 + 1) {
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = *puVar4;
      }
      puVar2 = puVar2 + 1;
    }
    *(undefined4 **)(param_1 + 0x58) = puVar2;
    *(undefined4 **)(param_1 + 0x5c) = puVar2;
  }
  ExceptionList = local_c;
  return;
}

