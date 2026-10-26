/*
 * FUN_0044c114 at 0044c114
 * undefined __register FUN_0044c114(uint * param_1, byte param_2, ushort param_3)
 * Address ranges: 0044c114-0044c652
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044c114(uint *param_1,byte param_2,ushort param_3)

{
  LONG nNumerator;
  LONG nNumerator_00;
  char cVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  LPCSTR pCVar6;
  int *piVar7;
  HDC pHVar8;
  int iVar9;
  HICON pHVar10;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint uVar11;
  undefined **ppuVar12;
  int *in_FS_OFFSET;
  bool bVar13;
  tagRECT *ptVar14;
  int iVar15;
  undefined1 *puStack_8c;
  undefined1 *puStack_88;
  undefined1 *puStack_84;
  uint *local_74;
  uint *local_70;
  uint *local_6c;
  undefined *local_68;
  tagRECT local_64;
  int *local_54;
  undefined **local_50;
  int *local_4c;
  byte local_46;
  byte local_45;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagSIZE local_18;
  int *local_10;
  ushort local_b;
  byte local_9;
  uint *local_8;
  
  puStack_84 = &stack0xfffffffc;
  local_74 = (uint *)0x0;
  local_70 = (uint *)0x0;
  local_6c = (uint *)0x0;
  local_68 = (undefined *)0x0;
  puStack_88 = &LAB_0044c653;
  puStack_8c = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&puStack_8c;
  local_b = param_3;
  local_9 = param_2;
  local_8 = param_1;
  local_10 = FUN_0044bfe0((int *)&PTR_FUN_0044bec8,'\x01',*(int **)PTR_DAT_0047c86c);
  (**(code **)(*local_10 + 0x68))(local_10,*(undefined1 *)(*(int *)PTR_DAT_0047c86c + 0x28));
  FUN_0042c378((int)local_10,'\x03');
  iVar3 = FUN_0042c57c((int)local_10);
  FUN_004188b4(iVar3);
  piVar4 = (int *)FUN_0042c57c((int)local_10);
  FUN_0044be28(piVar4,&local_18);
  nNumerator = local_18.cx;
  local_1c = MulDiv(8,local_18.cx,4);
  nNumerator_00 = local_18.cy;
  local_20 = MulDiv(8,local_18.cy,8);
  local_24 = MulDiv(10,nNumerator,4);
  local_28 = MulDiv(10,nNumerator_00,8);
  local_2c = MulDiv(0x32,nNumerator,4);
  uVar11 = 0;
  piVar4 = &DAT_0047d82c;
  local_50 = &PTR_PTR_0047ba90;
  do {
    bVar13 = (byte)uVar11 < 0xf;
    if ((byte)uVar11 < 0x10) {
      bVar13 = (*(byte *)((int)&local_b + ((int)(uVar11 & 0x7f) >> 3)) >> (uVar11 & 7) & 1) != 0;
    }
    if (bVar13) {
      if (*piVar4 == 0) {
        FUN_0040ebe8(0,0,0,&local_64.left,0);
        uVar5 = FUN_00441578((int)local_10);
        uVar5 = uVar5 | 0x420;
        ptVar14 = &local_64;
        iVar3 = -1;
        FUN_00405438((undefined4 *)*local_50,(int *)&local_68);
        pCVar6 = FUN_00403f94(local_68);
        piVar7 = (int *)FUN_0042c57c((int)local_10);
        pHVar8 = (HDC)FUN_00418994(piVar7);
        DrawTextA(pHVar8,pCVar6,iVar3,ptVar14,uVar5);
        *piVar4 = (local_64.right - local_64.left) + 8;
      }
      if (local_2c < *piVar4) {
        local_2c = *piVar4;
      }
    }
    uVar11 = uVar11 + 1;
    local_50 = local_50 + 1;
    piVar4 = piVar4 + 1;
  } while ((char)uVar11 != '\v');
  local_30 = MulDiv(0xe,local_18.cy,8);
  local_34 = MulDiv(4,local_18.cx,4);
  iVar15 = 0;
  uVar11 = FUN_00430158();
  iVar3 = (int)uVar11 >> 1;
  if (iVar3 < 0) {
    iVar3 = iVar3 + (uint)((uVar11 & 1) != 0);
  }
  SetRect(&local_64,0,0,iVar3,iVar15);
  uVar11 = FUN_00441578((int)local_10);
  uVar11 = uVar11 | 0x450;
  ptVar14 = &local_64;
  iVar3 = FUN_00403dd0((int)local_8);
  iVar3 = iVar3 + 1;
  pCVar6 = FUN_00403f94((undefined *)local_8);
  piVar4 = (int *)FUN_0042c57c((int)local_10);
  pHVar8 = (HDC)FUN_00418994(piVar4);
  DrawTextA(pHVar8,pCVar6,iVar3,ptVar14,uVar11);
  pCVar6 = *(LPCSTR *)(&DAT_0047ba50 + (uint)local_9 * 4);
  local_38 = local_64.right;
  local_3c = local_64.bottom;
  if ((pCVar6 != (LPCSTR)0x0) &&
     (local_38 = local_64.right + local_24 + 0x20, local_64.bottom < 0x20)) {
    local_3c = 0x20;
  }
  iVar3 = 0;
  uVar11 = 0;
  do {
    bVar13 = (byte)uVar11 < 0xf;
    if ((byte)uVar11 < 0x10) {
      bVar13 = (*(byte *)((int)&local_b + ((int)(uVar11 & 0x7f) >> 3)) >> (uVar11 & 7) & 1) != 0;
    }
    if (bVar13) {
      iVar3 = iVar3 + 1;
    }
    uVar11 = uVar11 + 1;
  } while ((char)uVar11 != '\v');
  iVar15 = 0;
  if (iVar3 != 0) {
    iVar15 = local_2c * iVar3 + (iVar3 + -1) * local_34;
  }
  iVar3 = FUN_0044be20(local_38,iVar15);
  FUN_0042bb58(local_10,iVar3 + local_1c * 2);
  FUN_0042bb88(local_10,local_3c + local_30 + local_28 + local_20 * 2);
  uVar11 = FUN_00430158();
  iVar3 = (int)uVar11 >> 1;
  if (iVar3 < 0) {
    iVar3 = iVar3 + (uint)((uVar11 & 1) != 0);
  }
  iVar9 = local_10[0xe] >> 1;
  if (iVar9 < 0) {
    iVar9 = iVar9 + (uint)((local_10[0xe] & 1U) != 0);
  }
  FUN_0043ee6c(local_10,iVar3 - iVar9);
  uVar11 = FUN_0043014c();
  iVar3 = (int)uVar11 >> 1;
  if (iVar3 < 0) {
    iVar3 = iVar3 + (uint)((uVar11 & 1) != 0);
  }
  iVar9 = local_10[0xf] >> 1;
  if (iVar9 < 0) {
    iVar9 = iVar9 + (uint)((local_10[0xf] & 1U) != 0);
  }
  FUN_0043ee8c(local_10,iVar3 - iVar9);
  if (local_9 == 4) {
    FUN_00431eb8(*(int *)PTR_DAT_0047c86c,(int *)&local_70);
    FUN_0043f67c((int)local_10,local_70);
  }
  else {
    FUN_00405438((undefined4 *)(&PTR_PTR_0047ba3c)[local_9],(int *)&local_6c);
    FUN_0043f67c((int)local_10,local_6c);
  }
  if (pCVar6 != (LPCSTR)0x0) {
    piVar4 = FUN_0044b088((int *)&PTR_FUN_00449f04,'\x01',local_10);
    (**(code **)(*piVar4 + 0x18))(piVar4,"Image");
    (**(code **)(*piVar4 + 0x60))(piVar4,local_10);
    pHVar10 = LoadIconA((HINSTANCE)0x0,pCVar6);
    piVar7 = (int *)FUN_0041a8dc((int *)piVar4[0x4a]);
    FUN_0041e418(piVar7,pHVar10);
    (**(code **)(*piVar4 + 0x7c))(piVar4,local_1c,local_20,0x20,0x20);
  }
  piVar4 = FUN_00423364((int *)&PTR_FUN_0042022c,'\x01',local_10);
  (**(code **)(*piVar4 + 0x18))(piVar4,"Message");
  (**(code **)(*piVar4 + 0x60))(piVar4,local_10);
  FUN_004237f4(piVar4,CONCAT31((int3)((uint)extraout_EDX >> 8),1),extraout_ECX);
  FUN_0043f67c((int)piVar4,local_8);
  FUN_0043f074(piVar4,&local_64.left);
  (**(code **)(*piVar4 + 0x68))(piVar4,*(undefined1 *)((int)local_10 + 0x4f));
  local_44 = (local_38 - local_64.right) + local_1c;
  cVar1 = FUN_00403088(piVar4,extraout_EDX_00,extraout_ECX_00);
  if (cVar1 != '\0') {
    iVar3 = FUN_0043f0b0(local_10);
    local_44 = (iVar3 - local_44) - piVar4[0xe];
  }
  (**(code **)(*piVar4 + 0x7c))(piVar4,local_44,local_20,local_64.bottom,local_64.right);
  if ((local_b & 4) == 0) {
    if ((local_b & 1) == 0) {
      local_45 = 5;
    }
    else {
      local_45 = 0;
    }
  }
  else {
    local_45 = 2;
  }
  if ((local_b & 8) == 0) {
    if ((local_b & 2) == 0) {
      local_46 = 2;
    }
    else {
      local_46 = 1;
    }
  }
  else {
    local_46 = 3;
  }
  iVar3 = FUN_0043f0b0(local_10);
  local_40 = iVar3 - iVar15 >> 1;
  if (local_40 < 0) {
    local_40 = local_40 + (uint)((iVar3 - iVar15 & 1U) != 0);
  }
  uVar11 = 0;
  local_50 = &PTR_DAT_0047ba64;
  ppuVar12 = &PTR_PTR_0047ba90;
  local_54 = &DAT_0047babc;
  iVar3 = local_64.bottom;
  do {
    bVar2 = (byte)uVar11;
    bVar13 = bVar2 < 0xf;
    if (bVar2 < 0x10) {
      bVar13 = (*(byte *)((int)&local_b + ((int)(uVar11 & 0x7f) >> 3)) >> (uVar11 & 7) & 1) != 0;
    }
    if (bVar13) {
      local_4c = FUN_00425790((int *)&PTR_FUN_00421f80,'\x01',local_10);
      (**(code **)(*local_4c + 0x18))(local_4c,*local_50);
      (**(code **)(*local_4c + 0x60))(local_4c,local_10);
      FUN_00405438((undefined4 *)*ppuVar12,(int *)&local_74);
      FUN_0043f67c((int)local_4c,local_74);
      local_4c[0x7f] = *local_54;
      if (bVar2 == local_45) {
        FUN_00425870(local_4c,1);
      }
      if (bVar2 == local_46) {
        *(undefined1 *)((int)local_4c + 0x1f9) = 1;
      }
      (**(code **)(*local_4c + 0x7c))
                (local_4c,local_40,local_3c + local_20 + local_28,local_30,local_2c);
      local_40 = local_40 + local_2c + local_34;
      if (bVar2 == 10) {
        local_4c[0x43] = (int)local_10;
        local_4c[0x42] = (int)&LAB_0044c058;
      }
    }
    uVar11 = uVar11 + 1;
    local_54 = local_54 + 1;
    ppuVar12 = ppuVar12 + 1;
    local_50 = local_50 + 1;
  } while ((char)uVar11 != '\v');
  *in_FS_OFFSET = iVar3;
  puStack_8c = &LAB_0044c65a;
  FUN_00403b74((int *)&local_74,4);
  return;
}

