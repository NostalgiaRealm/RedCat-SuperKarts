/*
 * FUN_0049e0a0 at 0049e0a0
 * undefined FUN_0049e0a0(void)
 * Address ranges: 0049e0a0-0049e17b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0049e0a0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d165c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0049dc30();
  local_4 = 0;
  FUN_0049eaa0();
  local_4._0_1_ = 1;
  FUN_004be91c(param_1 + 8,0x10,0x20,FUN_00471880,FUN_0040b4b0);
  *param_1 = &PTR_FUN_004d3074;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_0049f2a0(DAT_006a5c30 == 0,s__s___d__Can_t_create_multiple_in_004fc1fc,
               s_D__work_rcracer_oursoundlib_soun_004fc23c,0x58);
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x99] = 0;
  param_1[0x9c] = 100;
  param_1[0x9a] = 0;
  param_1[0x88] = 0;
  param_1[0x9b] = 0;
  DAT_006a5c30 = DAT_006a5c30 + 1;
  ExceptionList = local_c;
  return param_1;
}

