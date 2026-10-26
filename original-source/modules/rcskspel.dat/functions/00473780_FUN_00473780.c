/*
 * FUN_00473780 at 00473780
 * undefined FUN_00473780(void)
 * Address ranges: 00473780-0047381d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00473780(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 local_11 [5];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d08e8;
  local_c = ExceptionList;
  local_11[0] = 0;
  ExceptionList = &local_c;
  FUN_00431750();
  FUN_00431950();
  FUN_004780a0();
  local_4 = 0;
  FUN_004707f0();
  FUN_00470aa0();
  iVar2 = FUN_00473820();
  if (iVar2 == 0) {
    FUN_00473f20(local_11);
    FUN_00473ee0();
  }
  FUN_004707f0();
  FUN_00470c10();
  FUN_00431750();
  FUN_00431960();
  uVar1 = local_11[0];
  local_4 = 0xffffffff;
  FUN_004780e0();
  ExceptionList = local_c;
  return uVar1;
}

