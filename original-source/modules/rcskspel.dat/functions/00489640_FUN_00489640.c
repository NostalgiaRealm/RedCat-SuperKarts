/*
 * FUN_00489640 at 00489640
 * undefined FUN_00489640(void)
 * Address ranges: 00489640-004896b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00489640(undefined4 *param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (**(code **)*param_1)();
  uVar1 = uVar1 & 0x80000001;
  bVar2 = uVar1 == 0;
  if ((int)uVar1 < 0) {
    bVar2 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
  }
  *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x18) = 0x3f6147ae;
  if (!bVar2) {
    *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x1c) = 0x3e280000;
    *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x38) = 0x3f7c0000;
    *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x3c) = 0x3e280000;
    return;
  }
  *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x1c) = 0x3e180000;
  *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x38) = 0x3f7c0000;
  *(undefined4 *)(*(int *)(param_1[1] + 4) + 0x3c) = 0x3e180000;
  return;
}

