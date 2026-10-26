/*
 * FUN_00450ca0 at 00450ca0
 * undefined FUN_00450ca0(void)
 * Address ranges: 00450ca0-00450e29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00450ca0(int param_1)

{
  undefined4 *puVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdbb7;
  pvStack_c = ExceptionList;
  iVar3 = 0;
  local_4 = 3;
  ExceptionList = &pvStack_c;
  ppvVar2 = &pvStack_c;
  if (-1 < DAT_00508610) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x24) + 4) + iVar3 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
      ppvVar2 = ExceptionList;
    } while (iVar3 <= DAT_00508610);
  }
  ExceptionList = ppvVar2;
  iVar4 = 0;
  iVar3 = FUN_00452350();
  if (-1 < iVar3) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + iVar4 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar4 = iVar4 + 1;
      iVar3 = FUN_00452350();
    } while (iVar4 <= iVar3);
  }
  iVar4 = 0;
  iVar3 = FUN_00452340();
  if (-1 < iVar3) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x34) + 4) + iVar4 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar4 = iVar4 + 1;
      iVar3 = FUN_00452340();
    } while (iVar4 <= iVar3);
  }
  iVar3 = *(int *)(param_1 + 0x34);
  *(undefined ***)(param_1 + 0x30) = &PTR_FUN_004d2768;
  if (iVar3 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar3 + 4));
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_004bc150(iVar3);
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  iVar3 = *(int *)(param_1 + 0x2c);
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_004d2778;
  if (iVar3 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar3 + 4));
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_004bc150(iVar3);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  *(undefined ***)(param_1 + 0x20) = &PTR_FUN_004d2788;
  if (iVar3 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar3 + 4));
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_004bc150(iVar3);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  local_4 = 4;
  FUN_004526f0();
  iVar3 = *(int *)(param_1 + 0xc);
  local_4 = 0xffffffff;
  *(undefined ***)(param_1 + 8) = &PTR_FUN_004d2798;
  if (iVar3 != 0) {
    FUN_00418ec0();
    FUN_004bc150(iVar3);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  ExceptionList = pvStack_c;
  return;
}

