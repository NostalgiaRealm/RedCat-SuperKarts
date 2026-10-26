/*
 * FUN_00467fc8 at 00467fc8
 * undefined __register FUN_00467fc8(int * param_1, int param_2)
 * Address ranges: 00467fc8-004689d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467fc8(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  LPCSTR pCVar4;
  HDC pHVar5;
  HWND pHVar6;
  HWND pHVar7;
  int iVar8;
  LONG LVar9;
  int iVar10;
  int iVar11;
  undefined4 *in_FS_OFFSET;
  RECT *pRVar12;
  LONG LVar13;
  UINT UVar14;
  undefined4 uStack_88;
  undefined1 *puStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  undefined1 *puStack_74;
  undefined *local_64;
  int local_60;
  undefined *local_5c;
  int local_58;
  undefined1 local_54 [4];
  int local_50;
  undefined1 local_44 [8];
  int local_3c;
  int local_38;
  RECT local_34;
  int local_24;
  char local_1e;
  char local_1d;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  puStack_74 = &stack0xfffffffc;
  local_64 = (undefined *)0x0;
  local_60 = 0;
  local_5c = (undefined *)0x0;
  local_58 = 0;
  puStack_78 = &LAB_00468a23;
  uStack_7c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_7c;
  puStack_80 = (undefined1 *)0x467ffe;
  local_8 = param_1;
  local_c = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',0);
  puStack_84 = &LAB_004689d9;
  uStack_88 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_88;
  puStack_80 = &stack0xfffffffc;
  iVar1 = FUN_004674c4((int)local_8);
  if (-1 < iVar1 + -1) {
    iVar10 = 0;
    local_24 = iVar1;
    do {
      iVar1 = FUN_004674ac((int)local_8,iVar10);
      iVar1 = FUN_00417e98(*(int *)(iVar1 + 0x130));
      if (iVar1 != local_8[0x94]) {
        iVar1 = FUN_004674ac((int)local_8,iVar10);
        FUN_00417ea0(*(int **)(iVar1 + 0x130),local_8[0x94]);
      }
      iVar10 = iVar10 + 1;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  piVar2 = (int *)FUN_0040303c(local_c,(int)&PTR_FUN_0043aeac);
  FUN_0043e3e0(piVar2,(int)local_8);
  FUN_00418a14(local_c,param_2);
  (**(code **)(*(int *)local_c[3] + 8))((int *)local_c[3],local_8[0x16]);
  FUN_00417ea0((int *)local_c[5],local_8[0x94]);
  FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
  (**(code **)(*local_8 + 0x40))(local_8,&local_34);
  local_34.top = 0;
  local_34.left = 0;
  FUN_00418538(local_c,&local_34);
  FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
  FUN_00418610(local_c,0,0x14);
  (**(code **)(*local_8 + 0x40))(local_8,local_44);
  iVar10 = local_3c + -1;
  FUN_00418610(local_c,iVar10,0x14);
  (**(code **)(*local_8 + 0x40))(local_8,local_44);
  iVar1 = local_38;
  (**(code **)(*local_8 + 0x40))(local_8,local_54);
  iVar1 = (iVar1 - local_50) + -1;
  FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x18));
  FUN_004185b0(local_c,iVar10,iVar1);
  FUN_004185b0(local_c,0,iVar1);
  FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
  FUN_004185b0(local_c,0,0x14);
  if (*(char *)((int)local_8 + 0x255) != '\0') {
    FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
    FUN_00418610(local_c,1,0x16);
    (**(code **)(*local_8 + 0x40))(local_8,local_44);
    iVar1 = local_3c + -2;
    FUN_00418610(local_c,iVar1,0x16);
    (**(code **)(*local_8 + 0x40))(local_8,local_44);
    (**(code **)(*local_8 + 0x40))(local_8,local_54);
    iVar10 = (local_38 - local_50) + -2;
    FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0xc));
    FUN_004185b0(local_c,iVar1,iVar10);
    FUN_004185b0(local_c,1,iVar10);
    FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
    FUN_004185b0(local_c,1,0x15);
  }
  FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
  iVar10 = 0;
  iVar1 = FUN_004674c4((int)local_8);
  if (-1 < iVar1 + -1) {
    iVar11 = 0;
    local_24 = iVar1;
    do {
      iVar1 = FUN_004674ac((int)local_8,iVar11);
      if (*(char *)(iVar1 + 0x1f8) != '\0') {
        iVar8 = iVar10 + 6;
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        if (iVar1 == local_8[0x91]) {
          LVar9 = 3;
        }
        else {
          LVar9 = 5;
        }
        if (local_8[0x7f] != 0) {
          iVar1 = FUN_004674ac((int)local_8,iVar11);
          if (-1 < *(int *)(iVar1 + 0x1f0)) {
            iVar1 = FUN_004674ac((int)local_8,iVar11);
            iVar1 = *(int *)(iVar1 + 0x1f0);
            iVar3 = FUN_00433bb0((int *)local_8[0x7f]);
            if (iVar1 < iVar3) {
              LVar13 = LVar9;
              iVar1 = FUN_004674ac((int)local_8,iVar11);
              FUN_00433ea4((int *)local_8[0x7f],local_c,iVar10 + 5,1,*(undefined4 *)(iVar1 + 0x1f0),
                           LVar13);
            }
          }
        }
        if (local_8[0x7f] != 0) {
          iVar8 = iVar8 + *(int *)(local_8[0x7f] + 0x28) + 2;
        }
        UVar14 = 0x400;
        pRVar12 = &local_34;
        local_34.left = iVar8;
        local_34.top = LVar9;
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        FUN_0043f64c(iVar1,&local_58);
        iVar1 = FUN_00403dd0(local_58);
        iVar10 = FUN_004674ac((int)local_8,iVar11);
        FUN_0043f64c(iVar10,(int *)&local_5c);
        pCVar4 = FUN_00403f94(local_5c);
        pHVar5 = (HDC)FUN_00418994(local_c);
        DrawTextA(pHVar5,pCVar4,iVar1,pRVar12,UVar14);
        UVar14 = 0x20;
        pRVar12 = &local_34;
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        FUN_0043f64c(iVar1,&local_60);
        iVar1 = FUN_00403dd0(local_60);
        iVar10 = FUN_004674ac((int)local_8,iVar11);
        FUN_0043f64c(iVar10,(int *)&local_64);
        pCVar4 = FUN_00403f94(local_64);
        pHVar5 = (HDC)FUN_00418994(local_c);
        DrawTextA(pHVar5,pCVar4,iVar1,pRVar12,UVar14);
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        if (iVar1 == local_8[0x91]) {
          pHVar6 = (HWND)FUN_00445724(local_8);
          pHVar7 = GetFocus();
          if (pHVar6 == pHVar7) {
            InflateRect(&local_34,1,1);
            FUN_00418504(local_c,&local_34);
            InflateRect(&local_34,-1,-1);
          }
        }
        if (iVar11 < 1) {
LAB_00468462:
          local_1d = '\0';
        }
        else {
          iVar1 = FUN_004674ac((int)local_8,iVar11 + -1);
          if (iVar1 != local_8[0x91]) goto LAB_00468462;
          local_1d = '\x01';
        }
        iVar1 = FUN_004674c4((int)local_8);
        if (iVar1 + -2 < iVar11) {
LAB_00468490:
          local_1e = '\0';
        }
        else {
          iVar1 = FUN_004674ac((int)local_8,iVar11 + 1);
          if (iVar1 != local_8[0x91]) goto LAB_00468490;
          local_1e = '\x01';
        }
        FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        if (iVar1 == local_8[0x91]) {
          iVar1 = local_34.left + -6;
          if (iVar11 == 0) {
            iVar10 = 0x15;
          }
          else {
            iVar10 = 0x14;
          }
          local_1c = 0x13;
        }
        else {
          iVar1 = local_34.left + -4;
          iVar10 = 0x14;
          local_1c = 0x10;
        }
        FUN_00418610(local_c,iVar1,iVar10);
        iVar8 = iVar10 - local_1c;
        local_14 = iVar10;
        local_10 = iVar1;
        if (local_1d == '\0') {
          FUN_004185b0(local_c,iVar1,iVar8);
        }
        else {
          FUN_00418610(local_c,iVar1,iVar8);
        }
        if ((*(char *)((int)local_8 + 0x255) != '\0') && (local_1d == '\0')) {
          FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
          FUN_00418610(local_c,local_10 + 1,local_14);
          local_14 = local_14 - (local_1c + 1);
          iVar10 = FUN_004674ac((int)local_8,iVar11);
          if (iVar10 == local_8[0x91]) {
            local_14 = local_14 + -1;
          }
          FUN_004185b0(local_c,local_10 + 1,local_14);
          FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
          FUN_00418610(local_c,iVar1,iVar8);
        }
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        if (iVar1 == local_8[0x91]) {
          iVar1 = local_34.left + -4;
          iVar10 = 0;
          local_18 = (local_34.right - local_34.left) + 0xc;
        }
        else {
          iVar1 = local_34.left + -2;
          iVar10 = 2;
          local_18 = (local_34.right - local_34.left) + 8;
        }
        if (local_1d == '\0') {
          FUN_004185b0(local_c,iVar1,iVar10);
        }
        else {
          FUN_00418610(local_c,iVar1,iVar10);
        }
        iVar1 = iVar1 + local_18;
        FUN_004185b0(local_c,iVar1,iVar10);
        if (*(char *)((int)local_8 + 0x255) != '\0') {
          FUN_00418610(local_c,iVar1,iVar10 + 1);
          FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
          FUN_004185b0(local_c,(iVar1 - local_18) + -1,iVar10 + 1);
          FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
        }
        FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x18));
        if (local_1e != '\x01') {
          FUN_00418610(local_c,iVar1,iVar10 + 1);
          iVar8 = iVar1 + 1;
          FUN_004185b0(local_c,iVar8,iVar10 + 2);
          local_14 = iVar10 + 2;
          local_10 = iVar8;
          iVar10 = FUN_004674ac((int)local_8,iVar11);
          if (iVar10 == local_8[0x91]) {
            iVar10 = 0x15;
          }
          else {
            iVar10 = 0x14;
          }
          FUN_004185b0(local_c,iVar8,iVar10);
          if (*(char *)((int)local_8 + 0x255) != '\0') {
            FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0xc));
            FUN_00418610(local_c,iVar1,iVar10 + -1);
            FUN_004185b0(local_c,local_10 + -1,local_14 + -1);
          }
        }
        iVar1 = FUN_004674ac((int)local_8,iVar11);
        if (iVar1 == local_8[0x91]) {
          FUN_00417bbc((int *)local_c[4],local_8[0x94]);
          iVar1 = local_34.left + -5;
          if (*(char *)((int)local_8 + 0x255) != '\0') {
            iVar1 = local_34.left + -4;
          }
          local_18 = (local_34.right - local_34.left) + 0xe;
          if (*(char *)((int)local_8 + 0x255) != '\0') {
            local_18 = (local_34.right - local_34.left) + 0xc;
          }
          FUN_00418610(local_c,iVar1,0x14);
          iVar1 = iVar1 + local_18;
          FUN_004185b0(local_c,iVar1,0x14);
          iVar10 = FUN_004674c4((int)local_8);
          if (iVar11 == iVar10 + -1) {
            if (*(char *)((int)local_8 + 0x255) == '\0') {
              iVar1 = iVar1 + 1;
            }
            else {
              iVar1 = iVar1 + 2;
            }
            FUN_00418610(local_c,iVar1,0x14);
            FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
            (**(code **)(*local_8 + 0x40))(local_8,local_44);
            FUN_004185b0(local_c,local_3c + -1,0x14);
            if (*(char *)((int)local_8 + 0x255) != '\0') {
              FUN_00418610(local_c,iVar1,0x15);
              FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
              (**(code **)(*local_8 + 0x40))(local_8,local_44);
              FUN_004185b0(local_c,local_3c + -1,0x15);
            }
          }
        }
        else {
          FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x10));
          if (iVar11 == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = local_34.left + -4;
            if (local_1d != '\0') {
              iVar1 = local_34.left + -2;
            }
          }
          local_10 = iVar1;
          FUN_00418610(local_c,iVar1,0x14);
          iVar10 = FUN_004674c4((int)local_8);
          if (iVar11 == iVar10 + -1) {
            (**(code **)(*local_8 + 0x40))(local_8,local_44);
            iVar1 = local_3c + -1;
          }
          else {
            iVar10 = local_34.right - local_34.left;
            local_18 = iVar10 + 0xc;
            if (local_1d == '\0') {
              if (local_1e != '\x01') {
                local_18 = iVar10 + 0xf;
              }
            }
            else {
              local_18 = iVar10 + 10;
            }
            iVar1 = iVar1 + local_18;
          }
          FUN_004185b0(local_c,iVar1,0x14);
          if (*(char *)((int)local_8 + 0x255) != '\0') {
            if (iVar11 == 0) {
              FUN_00418610(local_c,local_10 + 1,0x15);
              FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
              FUN_004185b0(local_c,iVar1 + 1,0x15);
            }
            else {
              if (local_1d == '\0') {
                FUN_00418610(local_c,local_10,0x15);
              }
              else {
                FUN_00418610(local_c,local_10 + -2,0x15);
              }
              FUN_00417bbc((int *)local_c[4],*(undefined4 *)(local_8[0x96] + 0x14));
              if (local_1e == '\x01') {
                FUN_004185b0(local_c,iVar1 + -1,0x15);
              }
              else {
                FUN_004185b0(local_c,iVar1,0x15);
              }
            }
          }
        }
        iVar10 = local_34.right + 6;
      }
      iVar11 = iVar11 + 1;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  *in_FS_OFFSET = uStack_88;
  puStack_80 = &LAB_004689e0;
  puStack_84 = (undefined1 *)0x4689d8;
  FUN_00402eac(local_c);
  return;
}

