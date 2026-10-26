/*
 * FUN_0046c890 at 0046c890
 * undefined FUN_0046c890(void)
 * Address ranges: 0046c890-0046c901
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0046c890(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d036a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00431640();
  uVar1 = 1;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x68) = param_2;
  FUN_0046c510(1);
  FUN_00458460(uVar1);
  FUN_00466e70();
  FUN_0046c910();
  local_4 = 0xffffffff;
  FUN_00431680();
  ExceptionList = local_c;
  return;
}

