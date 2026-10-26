/*
 * FUN_004604e0 at 004604e0
 * undefined FUN_004604e0(void)
 * Address ranges: 004604e0-0046057d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004604e0(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined1 local_11;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cef5b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0;
  param_1[2] = &PTR_FUN_004d2b88;
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
  param_1[3] = puVar1;
  local_4 = 0;
  param_1[4] = &PTR_FUN_004d2b78;
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
  param_1[5] = puVar1;
  *(undefined1 *)((int)param_1 + 0x89) = 0;
  *param_1 = &PTR_FUN_004d2b74;
  ExceptionList = local_c;
  return param_1;
}

