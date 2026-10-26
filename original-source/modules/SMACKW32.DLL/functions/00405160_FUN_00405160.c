/*
 * FUN_00405160 at 00405160
 * uint __fastcall FUN_00405160(undefined4 param_1, byte param_2)
 * Address ranges: 00405160-004053d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_00405160(undefined4 param_1,byte param_2)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  if (DAT_0040e84c == (code *)0x0) {
    _SmackSoundUseWin_0();
  }
  iVar3 = (uint)param_2 * 4 + in_EAX;
  if ((*(uint *)(iVar3 + 0x48) >> 0x18 & 0x40) == 0) {
    uVar4 = 0;
    bVar12 = true;
  }
  else {
    uVar4 = *(uint *)(iVar3 + 0x48) & 0xffffff;
    bVar12 = uVar4 == 0;
  }
  if (bVar12) {
    uVar4 = uVar4 & 0xffffff00;
  }
  else {
    iVar3 = in_EAX + (uint)param_2 * 4;
    bVar8 = (byte)((uint)*(undefined4 *)(iVar3 + 0x48) >> 0x1c) & 1;
    bVar9 = (byte)((uint)*(undefined4 *)(iVar3 + 0x48) >> 0x1d) & 1;
    uVar10 = (bVar9 + 1) * uVar4 * (bVar8 + 1);
    if (DAT_0040e840 == 0) {
      uVar6 = *(int *)(in_EAX + 0x45c) + 0x2000;
      *(uint *)(in_EAX + 0x45c) = uVar6;
      if (*(uint *)(in_EAX + 0x49c) < uVar6) {
        *(uint *)(in_EAX + 0x49c) = uVar6;
      }
      DAT_0040e840 = FUN_00402c30(uVar6,0x2000,0x2000);
      if (DAT_0040e840 == 0) {
        return 0;
      }
    }
    uVar6 = (uint)param_2;
    puVar11 = *(undefined4 **)(in_EAX + 0x404 + uVar6 * 4);
    for (iVar3 = 0x1d; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    uVar7 = *(int *)(in_EAX + 0x400) << 7;
    *(int *)(*(int *)(in_EAX + 0x404 + uVar6 * 4) + 0x1c) =
         (int)(((ulonglong)uVar10 * (ulonglong)uVar7) / 100000);
    *(uint *)(*(int *)(in_EAX + 0x404 + uVar6 * 4) + 0x24) = uVar10 * 0x40;
    iVar3 = *(int *)(in_EAX + 0x404 + uVar6 * 4);
    *(uint *)(iVar3 + 0x18) = ((*(uint *)(iVar3 + 0x1c) >> 6) + uVar10 + 0xfff >> 8 & 0xfffff0) << 8
    ;
    iVar3 = *(int *)(in_EAX + 0x404 + uVar6 * 4);
    if (*(uint *)(iVar3 + 0x18) < 0x2000) {
      *(undefined4 *)(iVar3 + 0x18) = 0x2000;
    }
    iVar3 = in_EAX + (uint)param_2 * 4;
    iVar5 = FUN_00405d70(uVar7,*(int *)(*(int *)(iVar3 + 0x404) + 0x18));
    *(int *)(*(int *)(iVar3 + 0x404) + 8) = iVar5;
    *(int *)(*(int *)(iVar3 + 0x404) + 0xc) = iVar5;
    **(int **)(iVar3 + 0x404) = iVar5;
    *(int *)(*(int *)(iVar3 + 0x404) + 4) = iVar5 + *(int *)(*(int *)(iVar3 + 0x404) + 0x18);
    piVar1 = *(int **)(iVar3 + 0x404);
    if (*piVar1 == 0) {
      return (uint)piVar1 & 0xffffff00;
    }
    piVar1[5] = uVar10;
    *(uint *)(*(int *)(iVar3 + 0x404) + 0x40) = uVar4;
    *(uint *)(*(int *)(iVar3 + 0x404) + 0x48) = (uint)bVar9;
    *(uint *)(*(int *)(iVar3 + 0x404) + 0x4c) = (uint)bVar8;
    cVar2 = (*DAT_0040e84c)(*(undefined4 *)(in_EAX + 900),*(undefined4 *)(iVar3 + 0x404));
    if (cVar2 == '\0') {
      FUN_00402c10();
      uVar4 = *(uint *)(iVar3 + 0x404);
      *(int *)(in_EAX + 0x45c) = *(int *)(in_EAX + 0x45c) - *(int *)(uVar4 + 0x18);
      return uVar4 & 0xffffff00;
    }
    uVar4 = *(uint *)(iVar3 + 0x404);
    *(uint *)(uVar4 + 0x30) = *(int *)(iVar3 + 0x18) - (*(uint *)(uVar4 + 0x1c) >> 7);
    if (*(int *)(in_EAX + 0x420) == -1) {
      uVar4 = (uint)bVar9;
      *(uint *)(in_EAX + 0x420) = uVar4;
    }
    DAT_0040e83c = DAT_0040e83c + 1;
    uVar4 = CONCAT31((int3)(uVar4 >> 8),1);
  }
  return uVar4;
}

