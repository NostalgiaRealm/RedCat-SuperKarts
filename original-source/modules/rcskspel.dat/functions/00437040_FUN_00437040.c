/*
 * FUN_00437040 at 00437040
 * undefined FUN_00437040(void)
 * Address ranges: 00437040-004371e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __fastcall FUN_00437040(undefined1 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 local_65;
  int local_64;
  undefined1 *local_60;
  undefined4 *local_5c;
  undefined1 *local_58;
  undefined4 *local_54;
  int local_44;
  int local_40;
  int local_20;
  undefined **local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd35e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 1;
  local_60 = param_1;
  iVar1 = FUN_004365e0();
  local_4 = 0;
  *(undefined ***)(param_1 + 4) = &PTR_FUN_004d268c;
  puVar2 = operator_new(0x10);
  local_4._0_1_ = 1;
  local_58 = puVar2;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    *puVar2 = local_65;
    puVar3 = operator_new(0x2ec);
    *(undefined4 **)(puVar2 + 4) = puVar3;
    local_64 = 0xb;
    do {
      local_4._0_1_ = 2;
      local_54 = puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR_FUN_004d267c;
        local_5c = puVar3;
        FUN_00439460(&local_65);
        local_4._0_1_ = 3;
        *puVar3 = &PTR_FUN_004d266c;
        FUN_00439490(iVar1 + 4);
        local_4._0_1_ = 4;
        puVar3[0xd] = *(undefined4 *)(iVar1 + 0x34);
        FUN_0043b180(iVar1 + 0x38);
        puVar3[0x10] = *(undefined4 *)(iVar1 + 0x40);
        param_1 = local_60;
      }
      puVar3 = puVar3 + 0x11;
      local_64 = local_64 + -1;
    } while (local_64 != 0);
    *(int *)(puVar2 + 8) = *(int *)(puVar2 + 4) + 0x2ec;
    *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 4) + 0x2ec;
    local_64 = 0;
    local_5c = puVar3;
  }
  *(undefined1 **)(param_1 + 8) = puVar2;
  local_4._0_1_ = 7;
  local_18 = &PTR_FUN_004d265c;
  if (local_14 != 0) {
    FUN_00439a50(*(undefined4 *)(local_14 + 4),*(undefined4 *)(local_14 + 8));
    FUN_004bc150(*(undefined4 *)(local_14 + 4));
    *(undefined4 *)(local_14 + 4) = 0;
    *(undefined4 *)(local_14 + 8) = 0;
    *(undefined4 *)(local_14 + 0xc) = 0;
    FUN_004bc150(local_14);
  }
  local_14 = 0;
  local_4 = CONCAT31(local_4._1_3_,6);
  while (local_20 != 0) {
    local_40 = local_40 + 4;
    local_20 = local_20 + -1;
    if ((local_20 == 0) || (local_40 == local_44)) {
      FUN_00438c10();
    }
  }
  ExceptionList = local_c;
  return param_1;
}

