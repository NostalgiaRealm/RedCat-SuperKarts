/*
 * FUN_00467a60 at 00467a60
 * undefined FUN_00467a60(void)
 * Address ranges: 00467a60-00467ae6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00467a60(int param_1)

{
  undefined1 *puVar1;
  undefined1 local_11;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cfb78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004604e0();
  local_4 = 0;
  *(undefined ***)(param_1 + 0x8c) = &PTR_FUN_004d2cd8;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_11;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  *(undefined1 **)(param_1 + 0x90) = puVar1;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  ExceptionList = local_c;
  return param_1;
}

