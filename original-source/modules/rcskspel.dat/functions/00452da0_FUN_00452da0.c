/*
 * FUN_00452da0 at 00452da0
 * undefined FUN_00452da0(void)
 * Address ranges: 00452da0-00452e2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00452da0(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdcc8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (DAT_00543d2c == (undefined4 *)0x0) {
    ExceptionList = &local_c;
    DAT_00543d2c = operator_new(0x14);
    DAT_00543d2c[1] = 0;
    DAT_00543d2c[4] = 1;
    *DAT_00543d2c = 0;
    DAT_00543d2c[2] = 0;
  }
  puVar1 = DAT_00543d2c;
  DAT_00543d30 = DAT_00543d30 + 1;
  pvVar2 = operator_new(0x14);
  *(undefined4 **)((int)pvVar2 + 4) = puVar1;
  *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  *(void **)(param_1 + 4) = pvVar2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  ExceptionList = local_c;
  return;
}

