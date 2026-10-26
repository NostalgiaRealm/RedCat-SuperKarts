/*
 * FUN_00423c89 at 00423c89
 * undefined4 __cdecl FUN_00423c89(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, int param_6, int param_7)
 * Address ranges: 00423c89-00423d24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00423c89(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7)

{
  undefined4 uVar1;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3b8;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  DAT_0043e458 = param_1;
  DAT_0043e45c = param_3;
  local_8 = 1;
  ExceptionList = &local_14;
  uVar1 = FUN_00420053(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00423d4f();
  ExceptionList = local_14;
  return uVar1;
}

