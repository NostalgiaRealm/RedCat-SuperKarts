/*
 * FUN_00426800 at 00426800
 * undefined FUN_00426800(void)
 * Address ranges: 00426800-004268f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426800(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = FUN_00426540(param_1);
  iVar1 = *(int *)(&DAT_0050dfb0 + iVar1 * 0x1910);
  iVar2 = FUN_00426540(param_1);
  iVar3 = FUN_00426570(iVar1);
  puVar5 = param_2;
  puVar6 = (undefined4 *)(&DAT_0050dfb4 + iVar3 * 0x20 + iVar2 * 0x1910);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar2 = FUN_00426570(iVar1 + 1);
  iVar3 = FUN_00426540(param_1);
  puVar5 = param_2 + 8;
  puVar6 = (undefined4 *)(&DAT_0050dfb4 + iVar3 * 0x1910 + iVar2 * 0x20);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar2 = FUN_00426540(param_1);
  iVar3 = FUN_00426570(iVar1);
  puVar5 = param_3;
  puVar6 = (undefined4 *)(&DAT_0050ec34 + iVar3 * 0x20 + iVar2 * 0x1910);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar1 = FUN_00426570(iVar1 + 1);
  iVar2 = FUN_00426540(param_1);
  puVar5 = param_3 + 8;
  puVar6 = (undefined4 *)(&DAT_0050ec34 + iVar2 * 0x1910 + iVar1 * 0x20);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}

