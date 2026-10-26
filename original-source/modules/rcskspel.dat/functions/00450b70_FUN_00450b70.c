/*
 * FUN_00450b70 at 00450b70
 * undefined FUN_00450b70(void)
 * Address ranges: 00450b70-00450c97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00450b70(int param_1)

{
  undefined1 *puVar1;
  undefined1 local_16;
  undefined1 local_15;
  int local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdb79;
  local_c = ExceptionList;
  local_10 = (undefined4 *)(param_1 + 8);
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 4) = 0;
  *local_10 = &PTR_FUN_004d2798;
  local_14 = param_1;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_16;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  *(undefined1 **)(param_1 + 0xc) = puVar1;
  local_4 = 0;
  FUN_00452750(&local_15,0,&local_16);
  local_4 = 1;
  *(undefined ***)(param_1 + 0x20) = &PTR_FUN_004d2788;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_15;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  *(undefined1 **)(param_1 + 0x24) = puVar1;
  local_4._0_1_ = 2;
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_004d2778;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_15;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  *(undefined1 **)(param_1 + 0x2c) = puVar1;
  local_4 = CONCAT31(local_4._1_3_,3);
  *(undefined ***)(param_1 + 0x30) = &PTR_FUN_004d2768;
  puVar1 = operator_new(0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_15;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined1 **)(param_1 + 0x34) = puVar1;
    ExceptionList = local_c;
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  ExceptionList = local_c;
  return param_1;
}

