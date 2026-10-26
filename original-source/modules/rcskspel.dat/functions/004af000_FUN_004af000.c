/*
 * FUN_004af000 at 004af000
 * undefined FUN_004af000(void)
 * Address ranges: 004af000-004af068
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004af000(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1936;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004ae7c0();
  local_4 = 0;
  FUN_004ad0f0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004ad0f0();
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  ExceptionList = local_c;
  return param_1;
}

