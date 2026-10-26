/*
 * FUN_0047cf50 at 0047cf50
 * undefined FUN_0047cf50(void)
 * Address ranges: 0047cf50-0047d03a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047cf50(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d101a;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = *param_2;
    ExceptionList = &local_c;
    *(undefined4 *)(param_1 + 4) = 0;
    *param_1 = uVar1;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00412870(param_2,0,0xffffffff);
    local_4._0_1_ = 1;
    param_1[0x10] = param_2[0x10];
    if (*(int *)(param_2 + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14)) / 0x14;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    pvVar2 = operator_new(iVar3 * 0x14);
    *(void **)(param_1 + 0x14) = pvVar2;
    iVar3 = *(int *)(param_2 + 0x18);
    for (iVar4 = *(int *)(param_2 + 0x14); iVar4 != iVar3; iVar4 = iVar4 + 0x14) {
      local_4._0_1_ = 2;
      if (pvVar2 != (void *)0x0) {
        FUN_00477a70(iVar4);
      }
      pvVar2 = (void *)((int)pvVar2 + 0x14);
    }
    *(void **)(param_1 + 0x18) = pvVar2;
    *(void **)(param_1 + 0x1c) = pvVar2;
  }
  ExceptionList = local_c;
  return;
}

