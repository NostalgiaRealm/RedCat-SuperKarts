/*
 * FUN_004b2870 at 004b2870
 * undefined FUN_004b2870(void)
 * Address ranges: 004b2870-004b2c74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b2870(int param_1,undefined4 param_2,byte param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  int iStack_39c;
  int local_390;
  undefined2 uStack_38c;
  undefined1 uStack_38a;
  char local_380;
  char local_37f;
  short local_37c;
  short local_37a;
  short local_378;
  short local_376;
  short local_33e;
  undefined1 local_300 [768];
  
  iVar3 = FUN_004b96d0(param_2);
  if (iVar3 == 0) {
    return 1000;
  }
  if ((param_3 & 2) != 0) {
    FUN_004b2680(iVar3,local_300);
  }
  FUN_004b9570(iVar3,0,0);
  FUN_004bf930(&local_380,0x80,1,iVar3);
  if ((*(byte *)(iVar3 + 0xc) & 0x20) != 0) {
    FUN_004bf2c5(iVar3);
    return 0x3e9;
  }
  if ((((param_3 & 1) != 0) && (local_380 == '\n')) && (local_37f == '\x05')) {
    iVar11 = ((int)local_376 - (int)local_37a) + 1;
    if (DAT_004fe934 < iVar11) {
      iVar11 = DAT_004fe934;
    }
    FUN_004afce0(s_bpl__d__width__d_004fff20,(int)local_33e,((int)local_378 - (int)local_37c) + 1);
    iVar4 = (int)local_33e;
    if (DAT_004fe934 <= iVar11) {
      iVar11 = DAT_004fe934;
    }
    if (param_1 == 0) {
      local_390 = DAT_006a643c;
      iStack_39c = DAT_006a64bc;
    }
    else if (param_1 == 1) {
      local_390 = DAT_006a64a8;
      iStack_39c = DAT_006a64c0;
    }
    else if (param_1 == 2) {
      local_390 = DAT_006a64b8;
      iStack_39c = DAT_006a64a0;
    }
    else {
      FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                   s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0xa7,param_1);
    }
    FUN_004b08e0(iStack_39c);
    iStack_39c = iVar11;
    if (DAT_006ab82c == 0) {
      iVar5 = FUN_004b05a0(param_1);
      if (0 < iVar11) {
        do {
          iVar11 = 0;
          do {
            uVar6 = FUN_004c09f0(iVar3);
            if (((byte)uVar6 & 0xc0) == 0xc0) {
              uVar1 = FUN_004c09f0(iVar3);
              puVar14 = (undefined4 *)(iVar5 + iVar11);
              for (uVar8 = (uVar6 & 0x3f) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar14 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
                puVar14 = puVar14 + 1;
              }
              iVar11 = iVar11 + (uVar6 & 0x3f);
              for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *(undefined1 *)puVar14 = uVar1;
                puVar14 = (undefined4 *)((int)puVar14 + 1);
              }
            }
            else {
              *(byte *)(iVar5 + iVar11) = (byte)uVar6;
              iVar11 = iVar11 + 1;
            }
          } while (iVar11 < iVar4);
          iVar5 = iVar5 + local_390;
          iStack_39c = iStack_39c + -1;
        } while (iStack_39c != 0);
      }
    }
    else {
      if (DAT_006ab82c != 1) {
        if (DAT_006ab82c == 2) {
          iVar5 = FUN_004b05a0(param_1);
          if (0 < iVar11) {
            do {
              iVar11 = 0;
              do {
                uVar6 = FUN_004c09f0(iVar3);
                if (((byte)uVar6 & 0xc0) == 0xc0) {
                  uVar6 = uVar6 & 0x3f;
                  uVar1 = FUN_004c09f0(iVar3);
                  uVar7 = FUN_004b5740(uVar1,8);
                  if (uVar6 != 0) {
                    uStack_38c = (undefined2)uVar7;
                    puVar12 = (undefined2 *)(iVar5 + iVar11 * 3);
                    uStack_38a = (undefined1)((uint)uVar7 >> 0x10);
                    iVar11 = iVar11 + uVar6;
                    *puVar12 = uStack_38c;
                    *(undefined1 *)(puVar12 + 1) = uStack_38a;
                    puVar13 = (undefined1 *)((int)puVar12 + 3);
                    for (iVar9 = uVar6 * 3 + -3; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *puVar13 = *(undefined1 *)puVar12;
                      puVar12 = (undefined2 *)((int)puVar12 + 1);
                      puVar13 = puVar13 + 1;
                    }
                  }
                }
                else {
                  uVar7 = FUN_004b5740(uVar6 & 0xff,8);
                  uStack_38c = (undefined2)uVar7;
                  puVar12 = (undefined2 *)(iVar5 + iVar11 * 3);
                  uStack_38a = (undefined1)((uint)uVar7 >> 0x10);
                  iVar11 = iVar11 + 1;
                  *puVar12 = uStack_38c;
                  *(undefined1 *)(puVar12 + 1) = uStack_38a;
                }
              } while (iVar11 < iVar4);
              iVar5 = iVar5 + local_390;
              iStack_39c = iStack_39c + -1;
            } while (iStack_39c != 0);
          }
          FUN_004b0800(param_1,iVar5);
        }
        goto LAB_004b2c42;
      }
      iVar5 = FUN_004b05a0(param_1);
      if (0 < iVar11) {
        do {
          iVar11 = 0;
          do {
            uVar6 = FUN_004c09f0(iVar3);
            if (((byte)uVar6 & 0xc0) == 0xc0) {
              uVar8 = uVar6 & 0x3f;
              uVar1 = FUN_004c09f0(iVar3);
              uVar2 = FUN_004b5740(uVar1,8);
              if (uVar8 != 0) {
                puVar14 = (undefined4 *)(iVar5 + iVar11 * 2);
                for (uVar10 = uVar8 >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                  *puVar14 = CONCAT22(uVar2,uVar2);
                  puVar14 = puVar14 + 1;
                }
                iVar11 = iVar11 + uVar8;
                for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
                  *(undefined2 *)puVar14 = uVar2;
                  puVar14 = (undefined4 *)((int)puVar14 + 2);
                }
              }
            }
            else {
              uVar2 = FUN_004b5740(uVar6 & 0xff,8);
              *(undefined2 *)(iVar5 + iVar11 * 2) = uVar2;
              iVar11 = iVar11 + 1;
            }
          } while (iVar11 < iVar4);
          iVar5 = iVar5 + local_390;
          iStack_39c = iStack_39c + -1;
        } while (iStack_39c != 0);
      }
    }
    FUN_004b0800(param_1,iVar5);
  }
LAB_004b2c42:
  if ((param_3 & 6) == 6) {
    FUN_004b2340(DAT_006ab468,0,0x100);
  }
  FUN_004b9840(iVar3);
  return 0;
}

