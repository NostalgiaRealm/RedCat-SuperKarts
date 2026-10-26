/*
 * FUN_0043acf0 at 0043acf0
 * undefined FUN_0043acf0(void)
 * Address ranges: 0043acf0-0043ad55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_0043acf0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar3 = param_2 * 4;
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  pvVar4 = operator_new(uVar3);
  puVar1 = (undefined4 *)((int)pvVar4 + (param_2 & 0xfffffffc));
  iVar2 = *(int *)(param_1 + 0x20);
  puVar6 = puVar1;
  for (puVar5 = *(undefined4 **)(param_1 + 0x10); puVar5 != (undefined4 *)(iVar2 + 4);
      puVar5 = puVar5 + 1) {
    *puVar6 = *puVar5;
    puVar6 = puVar6 + 1;
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
  *(void **)(param_1 + 0x24) = pvVar4;
  *(uint *)(param_1 + 0x28) = param_2;
  return puVar1;
}

