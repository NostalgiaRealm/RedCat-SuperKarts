/*
 * FUN_00426c50 at 00426c50
 * undefined FUN_00426c50(void)
 * Address ranges: 00426c50-00426da0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426c50(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  
  if (DAT_0053ba30 != 0) {
    iVar1 = FUN_00426540(param_1);
    iVar1 = *(int *)(&DAT_0050dfb0 + iVar1 * 0x1910);
    iVar2 = FUN_00426540(param_1);
    iVar3 = FUN_00426540(param_1);
    iVar4 = FUN_00426540(param_1);
    iVar4 = *(int *)(&DAT_0050f8b8 + iVar4 * 0x1910);
    iVar3 = *(int *)(&DAT_0050f8bc + iVar3 * 0x1910);
    if ((0 < iVar4 - iVar3) && (iVar9 = 0, 0 < iVar1)) {
      puVar7 = (uint *)(&DAT_0050dfc4 + iVar2 * 0x1910);
      do {
        uVar8 = *puVar7 >> 0x18;
        uVar5 = (0xff - uVar8) / (uint)(iVar4 - iVar3);
        if (uVar5 == 0) {
          uVar5 = 1;
        }
        uVar5 = uVar5 + uVar8;
        if (0xff < uVar5) {
          uVar5 = 0xff;
        }
        uVar5 = *puVar7 & 0xffffff | uVar5 << 0x18;
        iVar2 = FUN_00426540(param_1);
        iVar6 = FUN_00426570(iVar9);
        *(uint *)(&DAT_0050dfc4 + iVar2 * 0x1910 + iVar6 * 0x20) = uVar5;
        iVar2 = FUN_00426540(param_1);
        iVar6 = FUN_00426570(iVar9);
        iVar9 = iVar9 + 1;
        *(uint *)(&DAT_0050ec44 + iVar2 * 0x1910 + iVar6 * 0x20) = uVar5;
        puVar7 = puVar7 + 8;
      } while (iVar9 < iVar1);
    }
  }
  return;
}

