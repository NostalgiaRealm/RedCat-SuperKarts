/*
 * FUN_0047f4c0 at 0047f4c0
 * undefined FUN_0047f4c0(void)
 * Address ranges: 0047f4c0-0047f5c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0047f4c0(undefined4 *param_1)

{
  undefined1 local_15;
  undefined4 *local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d122b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = local_15;
  local_14 = param_1;
  FUN_0040b4f0(0);
  *(undefined1 *)(param_1 + 5) = local_15;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  *(undefined1 *)(param_1 + 9) = local_15;
  FUN_0040b4f0(0);
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xd) = local_15;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  local_4._0_1_ = 3;
  *(undefined1 *)(param_1 + 0x13) = local_15;
  *(undefined1 *)((int)param_1 + 0x4d) = local_15;
  *(undefined1 *)(param_1 + 0x15) = 0;
  FUN_00480390();
  local_4._0_1_ = 4;
  *(undefined1 *)(param_1 + 0x17) = DAT_00545028;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  FUN_00412870(&DAT_00545028,0,0xffffffff);
  local_10 = param_1 + 0x1c;
  param_1[0x1b] = 0;
  *(undefined1 *)local_10 = local_15;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  local_4 = CONCAT31(local_4._1_3_,6);
  FUN_00480370(&local_15);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  ExceptionList = local_c;
  return param_1;
}

