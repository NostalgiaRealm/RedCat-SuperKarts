/*
 * FUN_00480390 at 00480390
 * undefined FUN_00480390(void)
 * Address ranges: 00480390-0048041e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00480390(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d12a8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (DAT_00544fb0 == (undefined4 *)0x0) {
    ExceptionList = &local_c;
    DAT_00544fb0 = operator_new(0x30);
    DAT_00544fb0[1] = 0;
    DAT_00544fb0[0xb] = 1;
    *DAT_00544fb0 = 0;
    DAT_00544fb0[2] = 0;
  }
  puVar1 = DAT_00544fb0;
  DAT_00544fb4 = DAT_00544fb4 + 1;
  pvVar2 = operator_new(0x30);
  *(undefined4 **)((int)pvVar2 + 4) = puVar1;
  *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
  *(void **)(param_1 + 4) = pvVar2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  ExceptionList = local_c;
  return;
}

