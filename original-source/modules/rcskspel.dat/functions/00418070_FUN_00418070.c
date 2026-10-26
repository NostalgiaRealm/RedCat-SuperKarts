/*
 * FUN_00418070 at 00418070
 * undefined FUN_00418070(void)
 * Address ranges: 00418070-004181ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00418070(int param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004ccf48;
  local_c = ExceptionList;
  local_4 = 4;
  ExceptionList = &local_c;
  FUN_00418980();
  iVar1 = *(int *)(param_1 + 0x54);
  local_4._0_1_ = 3;
  *(undefined ***)(param_1 + 0x50) = &PTR_FUN_004d253c;
  if (iVar1 != 0) {
    FUN_0048b600(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = *(int *)(param_1 + 0x4c);
  local_4._0_1_ = 2;
  *(undefined ***)(param_1 + 0x48) = &PTR_FUN_004d252c;
  if (iVar1 != 0) {
    FUN_0048b600(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  iVar1 = *(int *)(param_1 + 0x44);
  local_4._0_1_ = 1;
  *(undefined ***)(param_1 + 0x40) = &PTR_FUN_004d253c;
  if (iVar1 != 0) {
    FUN_0048b600(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  iVar1 = *(int *)(param_1 + 0x38);
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined ***)(param_1 + 0x34) = &PTR_FUN_004d253c;
  if (iVar1 != 0) {
    FUN_00418ec0();
    FUN_004bc150(iVar1);
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  iVar1 = *(int *)(param_1 + 0x2c);
  local_4 = 0xffffffff;
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_004d253c;
  if (iVar1 != 0) {
    FUN_0048b600(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  ExceptionList = local_c;
  return;
}

