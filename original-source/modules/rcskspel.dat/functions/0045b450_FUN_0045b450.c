/*
 * FUN_0045b450 at 0045b450
 * undefined FUN_0045b450(void)
 * Address ranges: 0045b450-0045b4bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0045b450(int param_1)

{
  undefined1 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004ce312;
  local_10 = ExceptionList;
  puVar1 = *(undefined1 **)(param_1 + 0xc);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  ExceptionList = &local_10;
  FUN_004b1d60(puVar1);
  local_8 = 0;
  FUN_0045b520();
  FUN_0045b860();
  FUN_0045d980();
  FUN_0045e460();
  ExceptionList = local_10;
  return;
}

