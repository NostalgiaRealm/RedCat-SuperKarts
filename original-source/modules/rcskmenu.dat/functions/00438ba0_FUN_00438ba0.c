/*
 * FUN_00438ba0 at 00438ba0
 * undefined __register FUN_00438ba0(int param_1, char param_2)
 * Address ranges: 00438ba0-00438fd2;00438fda-00439011
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438ba0(int param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  PCNZCH pCVar13;
  int iVar14;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int *in_FS_OFFSET;
  undefined1 uVar15;
  int local_44;
  byte *local_40;
  undefined4 *local_3c;
  byte *local_38;
  undefined1 *puVar16;
  int local_30;
  undefined4 *local_2c;
  undefined1 *local_28;
  int *local_24;
  undefined4 uStack_20;
  undefined1 *local_1c;
  int local_8;
  
  local_1c = &stack0xfffffffc;
  iVar14 = 8;
  do {
    local_8 = 0;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  local_24 = (int *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_24;
  uStack_20 = &LAB_00439012;
  puVar16 = &stack0xfffffffc;
  if (param_2 == '\0') {
    if ((*(byte *)(param_1 + 0x20) & 0x10) == 0) {
      local_28 = (undefined1 *)0x438bdd;
      cVar1 = FUN_004391bc(param_1);
      puVar16 = local_1c;
      if (cVar1 != '\0') goto LAB_00438be5;
    }
    *in_FS_OFFSET = (int)local_24;
    local_1c = &LAB_00439019;
    uStack_20 = (undefined1 *)0x438ff4;
    FUN_00403b74(&local_44,4);
    uStack_20 = (undefined1 *)0x439001;
    FUN_00403b74(&local_30,3);
    uStack_20 = (undefined1 *)0x439009;
    FUN_00403b50((int *)&local_1c);
    uStack_20 = (undefined1 *)0x439011;
    FUN_00403b50(&local_8);
    return;
  }
LAB_00438be5:
  local_1c = puVar16;
  local_28 = (undefined1 *)0x438bf3;
  FUN_00403be8(&local_8,(int)PTR_s_1234567890ABCDEFGHIJKLMNOPQRSTUV_0047b80c);
  local_28 = (undefined1 *)0x438bff;
  piVar3 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX);
  local_28 = (undefined1 *)0x438c0e;
  piVar4 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX_00);
  local_28 = (undefined1 *)0x438c1d;
  local_24 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX_01);
  local_28 = (undefined1 *)0x438c2c;
  piVar5 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX_02);
  local_2c = (undefined4 *)&LAB_00438fd3;
  local_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_30;
  local_28 = &stack0xfffffffc;
  iVar14 = FUN_00438084(param_1);
  if (-1 < iVar14 + -1) {
    iVar14 = 0;
    do {
      puVar16 = (undefined1 *)0x438c61;
      iVar6 = FUN_00438094(param_1,iVar14);
      uVar15 = *(char *)(iVar6 + 0x32) == '\0';
      if (!(bool)uVar15) {
        iVar6 = FUN_00438094(param_1,iVar14);
        puVar16 = (undefined1 *)0x438c81;
        FUN_00403ee0(*(uint **)(iVar6 + 0x24),(uint *)&DAT_0043902c);
        if (!(bool)uVar15) {
          puVar16 = (undefined1 *)0x438c90;
          iVar6 = FUN_00438094(param_1,iVar14);
          if (*(int *)(iVar6 + 0x24) != 0) {
            iVar6 = FUN_00438094(param_1,iVar14);
            FUN_0043a9b0(*(int *)(iVar6 + 0x24),(int *)&local_38);
            FUN_00407ca8(local_38,(int *)&local_28);
            if (local_28 == (undefined *)0x0) {
              puVar16 = (undefined1 *)FUN_00438094(param_1,iVar14);
              local_38 = (byte *)0x438cd2;
              iVar6 = FUN_00438094(param_1,iVar14);
              local_38 = (byte *)0x438cdf;
              FUN_00410cf0(local_24,0,*(undefined4 *)(iVar6 + 0x24),puVar16);
            }
            else {
              puVar16 = (undefined1 *)0x438cef;
              pCVar13 = FUN_0040b75c(local_28,PTR_s_1234567890ABCDEFGHIJKLMNOPQRSTUV_0047b80c);
              if (pCVar13 != (PCNZCH)0x0) {
                local_38 = (byte *)0x438cfc;
                puVar16 = &stack0xfffffffc;
                bVar2 = FUN_0043898c(local_28,extraout_EDX,extraout_ECX_03,(int)&stack0xfffffffc);
                if (!bVar2) {
                  iVar6 = FUN_00438094(param_1,iVar14);
                  piVar7 = (int *)(iVar6 + 0x24);
                  local_38 = (byte *)0x438d17;
                  iVar6 = FUN_00438094(param_1,iVar14);
                  local_38 = (byte *)0x438d22;
                  FUN_0043a918(*(undefined4 **)(iVar6 + 0x24),(int *)&local_3c);
                  FUN_00403ba4(piVar7,local_3c);
                  puVar16 = (undefined1 *)FUN_00438094(param_1,iVar14);
                  local_38 = (byte *)0x438d3e;
                  iVar6 = FUN_00438094(param_1,iVar14);
                  local_38 = (byte *)0x438d4b;
                  FUN_00410cf0(local_24,0,*(undefined4 *)(iVar6 + 0x24),puVar16);
                }
              }
            }
          }
        }
      }
      iVar14 = iVar14 + 1;
    } while (puVar16 != (undefined1 *)0x1);
  }
  FUN_00403be8(&local_30,local_8);
  iVar14 = (**(code **)(*local_24 + 0x14))();
  if (-1 < iVar14 + -1) {
    do {
      FUN_00403be8(&local_8,local_30);
      (**(code **)(*piVar4 + 8))(piVar4,local_24);
      (**(code **)(*piVar3 + 0x40))();
      iVar14 = (**(code **)(*piVar4 + 0x14))();
      iVar14 = iVar14 + -1;
      if (-1 < iVar14) {
        do {
          (**(code **)(*piVar4 + 0xc))(piVar4,iVar14,&local_2c);
          for (iVar6 = 1; iVar10 = FUN_00403dd0((int)local_2c), iVar6 <= iVar10; iVar6 = iVar6 + 1)
          {
            uVar8 = (uint)*(byte *)((int)local_2c + iVar6 + -1);
            if (((byte)PTR_DAT_0047c9c8[(int)uVar8 >> 3] >> (uVar8 & 7) & 1) == 0) {
              local_38 = (byte *)0x438deb;
              FUN_00403fd8((int)local_2c,iVar6,1,(int *)&local_40);
              FUN_00407ca8(local_40,(int *)&local_28);
              local_38 = (byte *)0x438dff;
              bVar2 = FUN_0043898c(local_28,extraout_EDX_00,extraout_ECX_04,(int)&stack0xfffffffc);
              if (bVar2) {
                if (PTR_DAT_0047c9d8[8] == '\0') {
                  FUN_00404060((undefined4 *)&LAB_00439038,(int *)&local_2c,iVar6);
                }
                else {
                  FUN_00438a40((int *)&local_2c,local_28,iVar6);
                }
                uVar9 = (**(code **)(*piVar4 + 0x18))(piVar4,iVar14);
                (**(code **)(*piVar3 + 0x38))(piVar3,local_2c,uVar9);
                (**(code **)(*piVar4 + 0x44))(piVar4,iVar14);
                break;
              }
            }
            else {
              iVar6 = iVar6 + 1;
            }
          }
          iVar14 = iVar14 + -1;
        } while (iVar14 != -1);
      }
      iVar14 = (**(code **)(*piVar3 + 0x14))();
      if (0 < iVar14) {
        local_38 = (byte *)0x438e7e;
        FUN_004389bc();
      }
      iVar14 = (**(code **)(*piVar4 + 0x14))();
      if (iVar14 < 1) break;
      iVar6 = 0x438e93;
      iVar14 = (**(code **)(*piVar4 + 0x14))();
      if (-1 < iVar14 + -1) {
        iVar10 = 0;
        do {
          iVar6 = (**(code **)(*piVar4 + 0x18))(piVar4,iVar10);
          iVar11 = FUN_00410cbc(local_24,iVar6);
          iVar12 = (**(code **)(*local_24 + 0x14))();
          iVar6 = 0x438ec8;
          (**(code **)(*local_24 + 0x60))(local_24,iVar11,iVar12 + -1);
          iVar10 = iVar10 + 1;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
      }
    } while (iVar6 != 1);
  }
  local_38 = (byte *)0x438ee1;
  FUN_004389bc();
  iVar14 = (**(code **)(*piVar5 + 0x14))();
  uStack_20 = (undefined1 *)CONCAT13(0 < iVar14,(undefined3)uStack_20);
  iVar14 = (**(code **)(*piVar5 + 0x14))();
  if (-1 < iVar14 + -1) {
    iVar14 = 0;
    do {
      (**(code **)(*piVar5 + 0xc))(piVar5,iVar14,&local_2c);
      if ((((PTR_DAT_0047c9d8[8] != '\0') &&
           (pCVar13 = FUN_0040b75c(&LAB_00439038,(undefined *)local_2c), pCVar13 == (PCNZCH)0x0)) &&
          (local_1c != (undefined1 *)0x0)) &&
         (pCVar13 = FUN_0040b75c(&LAB_00439038,(undefined *)local_2c), pCVar13 == (PCNZCH)0x0)) {
        piVar7 = &local_44;
        local_38 = (byte *)0x438f53;
        iVar6 = FUN_00403dd0((int)local_1c);
        local_38 = (byte *)0x438f62;
        FUN_00403fd8((int)local_1c,iVar6,1,piVar7);
        FUN_00438a40((int *)&local_2c,local_44,0);
        iVar6 = FUN_00403dd0((int)local_1c);
        FUN_00404018((int *)&local_1c,iVar6,1);
      }
      iVar6 = (**(code **)(*piVar5 + 0x18))(piVar5,iVar14);
      iVar10 = 0x438f9b;
      FUN_00403ba4((int *)(iVar6 + 0x24),local_2c);
      iVar14 = iVar14 + 1;
    } while (iVar10 != 1);
  }
  *in_FS_OFFSET = local_30;
  local_28 = (undefined1 *)0x438fda;
  local_2c = (undefined4 *)0x438fba;
  FUN_00402eac(piVar5);
  local_2c = (undefined4 *)0x438fc2;
  FUN_00402eac(local_24);
  local_2c = (undefined4 *)0x438fca;
  FUN_00402eac(piVar4);
  local_2c = (undefined4 *)0x438fd2;
  FUN_00402eac(piVar3);
  return;
}

