/*
 * FUN_0047c6c0 at 0047c6c0
 * undefined FUN_0047c6c0(void)
 * Address ranges: 0047c6c0-0047c7f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __thiscall FUN_0047c6c0(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0f69;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2;
  if (*(int *)(param_2 + 4) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x14;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  puVar3 = operator_new(iVar5 * 0x14);
  *(undefined1 **)(param_1 + 4) = puVar3;
  puVar1 = *(undefined1 **)(param_2 + 8);
  for (puVar7 = *(undefined1 **)(param_2 + 4); puVar7 != puVar1; puVar7 = puVar7 + 0x14) {
    local_4 = 0;
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = *puVar7;
      FUN_0040b4f0(0);
      FUN_00412870(puVar7,0,0xffffffff);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(puVar7 + 0x10);
    }
    puVar3 = puVar3 + 0x14;
  }
  *(undefined1 **)(param_1 + 8) = puVar3;
  *(undefined1 **)(param_1 + 0xc) = puVar3;
  local_4 = 1;
  param_1[0x10] = param_2[0x10];
  if (*(int *)(param_2 + 0x14) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 2;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  puVar4 = operator_new(iVar5 * 4);
  *(undefined4 **)(param_1 + 0x14) = puVar4;
  puVar2 = *(undefined4 **)(param_2 + 0x18);
  for (puVar6 = *(undefined4 **)(param_2 + 0x14); puVar6 != puVar2; puVar6 = puVar6 + 1) {
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = *puVar6;
    }
    puVar4 = puVar4 + 1;
  }
  *(undefined4 **)(param_1 + 0x18) = puVar4;
  *(undefined4 **)(param_1 + 0x1c) = puVar4;
  ExceptionList = local_c;
  return param_1;
}

