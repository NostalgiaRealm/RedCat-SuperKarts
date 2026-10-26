/*
 * FUN_0047d0c0 at 0047d0c0
 * undefined FUN_0047d0c0(void)
 * Address ranges: 0047d0c0-0047d134
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __thiscall FUN_0047d0c0(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  *param_1 = *param_2;
  iVar1 = 0;
  if (*(int *)(param_2 + 4) != 0) {
    iVar1 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x14;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  pvVar2 = operator_new(iVar1 * 0x14);
  *(void **)(param_1 + 4) = pvVar2;
  iVar1 = *(int *)(param_2 + 8);
  for (iVar3 = *(int *)(param_2 + 4); iVar3 != iVar1; iVar3 = iVar3 + 0x14) {
    FUN_0047d140(pvVar2,iVar3);
    pvVar2 = (void *)((int)pvVar2 + 0x14);
  }
  *(void **)(param_1 + 8) = pvVar2;
  *(void **)(param_1 + 0xc) = pvVar2;
  return param_1;
}

