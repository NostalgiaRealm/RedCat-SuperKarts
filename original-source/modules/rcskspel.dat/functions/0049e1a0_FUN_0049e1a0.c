/*
 * FUN_0049e1a0 at 0049e1a0
 * undefined FUN_0049e1a0(void)
 * Address ranges: 0049e1a0-0049e23c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049e1a0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004d169c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_004d3074;
  local_4 = 2;
  FUN_004afce0(s_____Exitting_CSndEngine______004fc290);
  FUN_0049e2d0();
  DAT_006a5c30 = DAT_006a5c30 + -1;
  FUN_004afce0(s_____CSndEngine_Exit_done_____004fc270);
  local_4._0_1_ = 1;
  FUN_004be99e(param_1 + 8,0x10,0x20,FUN_0040b4b0);
  local_4 = (uint)local_4._1_3_ << 8;
  thunk_FUN_0049ebe0();
  local_4 = 0xffffffff;
  thunk_FUN_0049dcb0();
  ExceptionList = local_c;
  return;
}

