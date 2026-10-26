/*
 * FUN_004585e0 at 004585e0
 * undefined FUN_004585e0(void)
 * Address ranges: 004585e0-00458663
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_004585e0(undefined4 *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00458230(param_2,1);
  local_4 = 0;
  param_1[0x1d] = &PTR_FUN_004d2878;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = (undefined1)param_2;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  param_1[0x1e] = puVar1;
  *param_1 = &PTR_FUN_004d2834;
  param_1[0x1f] = 0x3f800000;
  param_1[0x20] = 0x3f800000;
  ExceptionList = local_c;
  return param_1;
}

