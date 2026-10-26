/*
 * FUN_00454670 at 00454670
 * undefined FUN_00454670(void)
 * Address ranges: 00454670-00454717
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __thiscall FUN_00454670(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdda8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_3;
  param_1[1] = *param_2;
  param_1[8] = 0;
  local_4 = 0;
  if (DAT_00543d54 == (undefined4 *)0x0) {
    DAT_00543d54 = operator_new(0x18);
    DAT_00543d54[1] = 0;
    DAT_00543d54[5] = 1;
    *DAT_00543d54 = 0;
    DAT_00543d54[2] = 0;
  }
  puVar1 = DAT_00543d54;
  DAT_00543d58 = DAT_00543d58 + 1;
  pvVar2 = operator_new(0x18);
  *(undefined4 **)((int)pvVar2 + 4) = puVar1;
  *(undefined4 *)((int)pvVar2 + 0x14) = 0;
  *(void **)(param_1 + 4) = pvVar2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  ExceptionList = local_c;
  return param_1;
}

