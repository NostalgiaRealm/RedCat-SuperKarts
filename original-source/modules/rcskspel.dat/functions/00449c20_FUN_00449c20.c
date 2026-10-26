/*
 * FUN_00449c20 at 00449c20
 * undefined FUN_00449c20(void)
 * Address ranges: 00449c20-00449c73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00449c20(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cd7e6;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00449d30();
  local_4 = 0xffffffff;
  FUN_004be99e(param_1 + 8,0x10,0x40,&DAT_004498f0);
  ExceptionList = local_c;
  return;
}

