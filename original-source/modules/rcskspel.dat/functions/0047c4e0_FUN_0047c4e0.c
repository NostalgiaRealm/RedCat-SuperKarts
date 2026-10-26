/*
 * FUN_0047c4e0 at 0047c4e0
 * undefined FUN_0047c4e0(void)
 * Address ranges: 0047c4e0-0047c655
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __thiscall FUN_0047c4e0(undefined1 *param_1,undefined1 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d0f38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[8] = param_2[8];
  local_4 = 0;
  if (DAT_00544fb0 == (undefined4 *)0x0) {
    DAT_00544fb0 = operator_new(0x30);
    DAT_00544fb0[1] = 0;
    DAT_00544fb0[0xb] = 1;
    *DAT_00544fb0 = 0;
    DAT_00544fb0[2] = 0;
  }
  puVar2 = DAT_00544fb0;
  DAT_00544fb4 = DAT_00544fb4 + 1;
  pvVar1 = operator_new(0x30);
  *(undefined4 **)((int)pvVar1 + 4) = puVar2;
  *(undefined4 *)((int)pvVar1 + 0x2c) = 0;
  *(void **)(param_1 + 4) = pvVar1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar5 = *(undefined4 **)(*(int *)(param_2 + 4) + 4);
  local_4 = 2;
  puVar4 = puVar2;
  local_10 = puVar5;
  if (puVar5 != DAT_00544fb0) {
    do {
      puVar2 = (undefined4 *)FUN_0047cee0(puVar4,puVar5[0xb]);
      if (local_10 == puVar5) {
        local_10 = puVar2;
      }
      uVar3 = FUN_0047cd30(puVar5[2],puVar2);
      puVar2[2] = uVar3;
      FUN_0047cf50(puVar2 + 3,puVar5 + 3);
      *puVar4 = puVar2;
      puVar5 = (undefined4 *)*puVar5;
      puVar4 = puVar2;
    } while (puVar5 != DAT_00544fb0);
  }
  *puVar2 = DAT_00544fb0;
  *(undefined4 **)(*(int *)(param_1 + 4) + 4) = local_10;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar5 = (undefined4 *)puVar2[1];
  if (puVar5 == DAT_00544fb0) {
    *puVar2 = puVar2;
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  }
  else {
    for (puVar4 = (undefined4 *)*puVar5; puVar4 != DAT_00544fb0; puVar4 = (undefined4 *)*puVar4) {
      puVar5 = puVar4;
    }
    *puVar2 = puVar5;
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 4);
    for (puVar5 = (undefined4 *)puVar2[2]; puVar5 != DAT_00544fb0; puVar5 = (undefined4 *)puVar5[2])
    {
      puVar2 = puVar5;
    }
    *(undefined4 **)(*(int *)(param_1 + 4) + 8) = puVar2;
  }
  ExceptionList = local_c;
  return param_1;
}

