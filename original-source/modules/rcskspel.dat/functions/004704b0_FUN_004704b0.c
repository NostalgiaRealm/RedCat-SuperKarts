/*
 * FUN_004704b0 at 004704b0
 * undefined FUN_004704b0(void)
 * Address ranges: 004704b0-00470507
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004704b0(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d07c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004be91c(param_1 + 0xf0,0x10,0xc,FUN_00471880,FUN_0040b4b0);
  local_4 = 0;
  FUN_00470530();
  ExceptionList = local_c;
  return param_1;
}

