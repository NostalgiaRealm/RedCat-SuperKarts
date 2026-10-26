/*
 * FUN_0042ebd0 at 0042ebd0
 * undefined FUN_0042ebd0(void)
 * Address ranges: 0042ebd0-0042ec32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __thiscall FUN_0042ebd0(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *param_1 = *param_2;
  if (*(int *)(param_2 + 4) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  puVar3 = operator_new(iVar2 * 4);
  *(undefined4 **)(param_1 + 4) = puVar3;
  puVar1 = *(undefined4 **)(param_2 + 8);
  for (puVar4 = *(undefined4 **)(param_2 + 4); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *puVar4;
    }
    puVar3 = puVar3 + 1;
  }
  *(undefined4 **)(param_1 + 8) = puVar3;
  *(undefined4 **)(param_1 + 0xc) = puVar3;
  return param_1;
}

