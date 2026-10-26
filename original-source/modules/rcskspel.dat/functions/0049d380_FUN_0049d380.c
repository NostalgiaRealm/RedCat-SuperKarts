/*
 * FUN_0049d380 at 0049d380
 * undefined FUN_0049d380(void)
 * Address ranges: 0049d380-0049d3d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049d380(int param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d15f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  iVar1 = FUN_0049d870();
  if (iVar1 != 0) {
    FUN_004b41b0(*(undefined4 *)(param_1 + 0x38));
  }
  local_4 = 0xffffffff;
  FUN_0049f1a0();
  ExceptionList = local_c;
  return;
}

