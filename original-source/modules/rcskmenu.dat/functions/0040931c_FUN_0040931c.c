/*
 * FUN_0040931c at 0040931c
 * undefined __register FUN_0040931c(byte * param_1, undefined4 param_2, undefined1 * param_3, undefined1 * param_4)
 * Address ranges: 0040931c-004093e3;0040945d-00409a5c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040931c(byte *param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  undefined1 *extraout_ECX_02;
  undefined1 *extraout_ECX_03;
  undefined1 *puVar5;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  undefined4 extraout_EDX_12;
  byte bVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar10;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 *local_2c;
  undefined4 *local_28;
  byte local_23;
  char local_22;
  undefined1 local_21;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  ushort local_1a;
  undefined1 local_17;
  ushort local_16;
  ushort local_14;
  ushort local_12;
  int local_10;
  byte local_9;
  byte *local_8;
  
  puStack_38 = &stack0xfffffffc;
  local_2c = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  puStack_3c = &LAB_00409a5d;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  local_8 = param_1;
  if ((param_1 != (byte *)0x0) && (*(int *)(param_4 + -0x108) < 2)) {
    *(int *)(param_4 + -0x108) = *(int *)(param_4 + -0x108) + 1;
    local_17 = 0;
    local_21 = 0;
    local_22 = '\0';
    bVar7 = 0x20;
    while (bVar1 = *local_8, pbVar8 = local_8, bVar1 != 0) {
      pbVar8 = local_8 + 1;
      local_9 = bVar1;
      if (((byte)(&DAT_0047b114)[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0) {
        bVar2 = bVar1;
        if ((byte)(bVar1 + 0x9f) < 0x1a) {
          bVar2 = bVar1 - 0x20;
        }
        bVar6 = bVar7;
        if ((((byte)(bVar2 + 0xbf) < 0x1a) && (bVar6 = bVar2, bVar2 == 0x4d)) && (bVar7 == 0x48)) {
          bVar2 = 0x4e;
          bVar6 = bVar2;
        }
        bVar7 = bVar6;
        local_8 = pbVar8;
        switch(bVar2) {
        case 0x22:
        case 0x27:
          while( true ) {
            bVar2 = *local_8;
            if (((bVar2 == 0) || (bVar2 == bVar1)) ||
               ((((byte)(&DAT_0047b114)[(int)(uint)bVar2 >> 3] >> (bVar2 & 7) & 1) != 0 &&
                (local_8 = local_8 + 1, *local_8 == 0)))) break;
            local_8 = local_8 + 1;
          }
          puVar5 = param_4;
          FUN_00408f54((undefined4 *)pbVar8,(int)local_8 - (int)pbVar8,param_3,(int)param_4);
          param_3 = puVar5;
          if (*local_8 != 0) {
            local_8 = local_8 + 1;
          }
          break;
        default:
          puVar5 = param_4;
          FUN_00408f54((undefined4 *)&local_9,1,param_3,(int)param_4);
          param_3 = puVar5;
          break;
        case 0x2f:
          puVar5 = param_4;
          FUN_00408f54((undefined4 *)&DAT_0047d4f9,1,param_3,(int)param_4);
          param_3 = puVar5;
          break;
        case 0x3a:
          puVar5 = param_4;
          FUN_00408f54((undefined4 *)&DAT_0047d504,1,param_3,(int)param_4);
          param_3 = puVar5;
          break;
        case 0x41:
          FUN_00409068();
          pbVar8 = local_8;
          pbVar9 = local_8 + -1;
          iVar4 = FUN_0040846c((char *)pbVar9,"AM/PM",5);
          if (iVar4 == 0) {
            if (0xb < local_1a) {
              pbVar9 = pbVar8 + 2;
            }
            param_3 = param_4;
            FUN_00408f54((undefined4 *)pbVar9,2,extraout_ECX_04,(int)param_4);
            local_8 = local_8 + 4;
            local_22 = '\x01';
          }
          else {
            iVar4 = FUN_0040846c((char *)pbVar9,"A/P",3);
            if (iVar4 == 0) {
              if (0xb < local_1a) {
                pbVar9 = pbVar8 + 1;
              }
              param_3 = param_4;
              FUN_00408f54((undefined4 *)pbVar9,1,extraout_ECX_05,(int)param_4);
              local_8 = local_8 + 2;
              local_22 = '\x01';
            }
            else {
              iVar4 = FUN_0040846c((char *)pbVar9,"AMPM",4);
              if (iVar4 == 0) {
                if (local_1a < 0xc) {
                  param_3 = param_4;
                  FUN_00408f98(DAT_0047d508,extraout_EDX_06,extraout_ECX_06,(int)param_4);
                }
                else {
                  param_3 = param_4;
                  FUN_00408f98(DAT_0047d50c,extraout_EDX_06,extraout_ECX_06,(int)param_4);
                }
                local_8 = local_8 + 3;
                local_22 = '\x01';
              }
              else {
                iVar4 = FUN_0040846c((char *)pbVar9,"AAAA",4);
                if (iVar4 == 0) {
                  puVar5 = &stack0xfffffffc;
                  FUN_00409030();
                  param_3 = param_4;
                  iVar4 = FUN_00408f18(param_4,extraout_EDX_07,puVar5,*(undefined4 *)(param_4 + 8),
                                       *(undefined4 *)(param_4 + 0xc));
                  FUN_00408f98(*(undefined4 **)(&DAT_0047d590 + iVar4 * 4),extraout_EDX_08,
                               extraout_ECX_07,(int)param_3);
                  local_8 = local_8 + 3;
                }
                else {
                  iVar4 = FUN_0040846c((char *)pbVar9,"AAA",3);
                  if (iVar4 == 0) {
                    puVar5 = &stack0xfffffffc;
                    FUN_00409030();
                    param_3 = param_4;
                    iVar4 = FUN_00408f18(param_4,extraout_EDX_09,puVar5,*(undefined4 *)(param_4 + 8)
                                         ,*(undefined4 *)(param_4 + 0xc));
                    FUN_00408f98(*(undefined4 **)(&DAT_0047d574 + iVar4 * 4),extraout_EDX_10,
                                 extraout_ECX_09,(int)param_3);
                    local_8 = local_8 + 2;
                  }
                  else {
                    param_3 = param_4;
                    FUN_00408f54((undefined4 *)&local_9,1,extraout_ECX_08,(int)param_4);
                  }
                }
              }
            }
          }
          break;
        case 0x43:
          puVar5 = &stack0xfffffffc;
          FUN_00409004();
          FUN_0040931c(DAT_0047d4fc,extraout_EDX_11,puVar5,param_4);
          param_3 = &stack0xfffffffc;
          FUN_00409068();
          if (((local_1a != 0) || (local_1c != 0)) || (local_1e != 0)) {
            puVar5 = param_4;
            FUN_00408f54((undefined4 *)&DAT_00409a8c,1,param_3,(int)param_4);
            param_3 = param_4;
            FUN_0040931c(DAT_0047d514,extraout_EDX_12,puVar5,param_4);
          }
          break;
        case 0x44:
          puVar5 = &stack0xfffffffc;
          FUN_00409004();
          if (local_10 - 1U < 2) {
            puVar5 = &stack0xfffffffc;
            FUN_00409030();
            param_3 = param_4;
            FUN_00408fb8((uint)local_16,local_10,puVar5,(int)param_4);
          }
          else if (local_10 == 3) {
            param_3 = param_4;
            iVar4 = FUN_00408f18(param_4,extraout_EDX_02,puVar5,*(undefined4 *)(param_4 + 8),
                                 *(undefined4 *)(param_4 + 0xc));
            FUN_00408f98(*(undefined4 **)(&DAT_0047d574 + iVar4 * 4),extraout_EDX_03,extraout_ECX,
                         (int)param_3);
          }
          else if (local_10 == 4) {
            param_3 = param_4;
            iVar4 = FUN_00408f18(param_4,extraout_EDX_02,puVar5,*(undefined4 *)(param_4 + 8),
                                 *(undefined4 *)(param_4 + 0xc));
            FUN_00408f98(*(undefined4 **)(&DAT_0047d590 + iVar4 * 4),extraout_EDX_04,extraout_ECX_00
                         ,(int)param_3);
          }
          else if (local_10 == 5) {
            param_3 = param_4;
            FUN_0040931c(DAT_0047d4fc,extraout_EDX_02,puVar5,param_4);
          }
          else {
            param_3 = param_4;
            FUN_0040931c(DAT_0047d500,extraout_EDX_02,puVar5,param_4);
          }
          break;
        case 0x45:
          FUN_00409004();
          puVar10 = &stack0xfffffffc;
          FUN_00409030();
          puVar5 = &stack0xfffffffc;
          param_3 = param_4;
          FUN_00409214(local_10,(int *)&local_2c,puVar10,(int)&stack0xfffffffc);
          FUN_00408f98(local_2c,extraout_EDX_00,puVar5,(int)param_3);
          break;
        case 0x47:
          FUN_00409004();
          puVar10 = &stack0xfffffffc;
          FUN_00409030();
          puVar5 = &stack0xfffffffc;
          param_3 = param_4;
          FUN_004090a8(local_10,(int *)&local_28,puVar10,(int)&stack0xfffffffc);
          FUN_00408f98(local_28,extraout_EDX,puVar5,(int)param_3);
          break;
        case 0x48:
          FUN_00409004();
          puVar5 = &stack0xfffffffc;
          FUN_00409068();
          local_23 = 0;
          pbVar8 = local_8;
          while (bVar1 = *pbVar8, bVar1 != 0) {
            if (((byte)(&DAT_0047b114)[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0) {
              bVar1 = *pbVar8;
              if (bVar1 < 0x49) {
                if (bVar1 == 0x48) break;
                if ((bVar1 == 0x22) || (bVar1 == 0x27)) {
                  local_23 = local_23 ^ 1;
                }
                else if (bVar1 == 0x41) goto LAB_0040966f;
              }
              else if (bVar1 == 0x61) {
LAB_0040966f:
                if (local_23 == 0) {
                  iVar4 = FUN_0040846c((char *)pbVar8,"AM/PM",5);
                  puVar5 = extraout_ECX_01;
                  if (((iVar4 == 0) ||
                      (iVar4 = FUN_0040846c((char *)pbVar8,"A/P",3), puVar5 = extraout_ECX_02,
                      iVar4 == 0)) ||
                     (iVar4 = FUN_0040846c((char *)pbVar8,"AMPM",4), puVar5 = extraout_ECX_03,
                     iVar4 == 0)) {
                    local_22 = '\x01';
                  }
                  break;
                }
              }
              else if (bVar1 == 0x68) break;
              pbVar8 = pbVar8 + 1;
            }
            else {
              if (pbVar8[1] == 0) break;
              pbVar8 = pbVar8 + 2;
            }
          }
          uVar3 = local_1a;
          if (local_22 != '\0') {
            if (local_1a == 0) {
              uVar3 = 0xc;
            }
            else if (0xc < local_1a) {
              uVar3 = local_1a - 0xc;
            }
          }
          if (2 < local_10) {
            local_10 = 2;
          }
          param_3 = param_4;
          FUN_00408fb8((uint)uVar3,local_10,puVar5,(int)param_4);
          break;
        case 0x4d:
          FUN_00409004();
          puVar5 = &stack0xfffffffc;
          FUN_00409030();
          if (local_10 - 1U < 2) {
            param_3 = param_4;
            FUN_00408fb8((uint)local_14,local_10,puVar5,(int)param_4);
          }
          else if (local_10 - 1U == 2) {
            param_3 = param_4;
            FUN_00408f98((undefined4 *)(&DAT_0047d514)[local_14],extraout_EDX_01,puVar5,(int)param_4
                        );
          }
          else {
            param_3 = param_4;
            FUN_00408f98(*(undefined4 **)(&DAT_0047d544 + (uint)local_14 * 4),extraout_EDX_01,puVar5
                         ,(int)param_4);
          }
          break;
        case 0x4e:
          FUN_00409004();
          puVar5 = &stack0xfffffffc;
          FUN_00409068();
          if (2 < local_10) {
            local_10 = 2;
          }
          param_3 = param_4;
          FUN_00408fb8((uint)local_1c,local_10,puVar5,(int)param_4);
          break;
        case 0x53:
          FUN_00409004();
          puVar5 = &stack0xfffffffc;
          FUN_00409068();
          if (2 < local_10) {
            local_10 = 2;
          }
          param_3 = param_4;
          FUN_00408fb8((uint)local_1e,local_10,puVar5,(int)param_4);
          break;
        case 0x54:
          puVar5 = &stack0xfffffffc;
          FUN_00409004();
          if (local_10 == 1) {
            param_3 = param_4;
            FUN_0040931c(DAT_0047d510,extraout_EDX_05,puVar5,param_4);
          }
          else {
            param_3 = param_4;
            FUN_0040931c(DAT_0047d514,extraout_EDX_05,puVar5,param_4);
          }
          break;
        case 0x59:
          FUN_00409004();
          puVar5 = &stack0xfffffffc;
          FUN_00409030();
          if (local_10 < 3) {
            param_3 = param_4;
            FUN_00408fb8((uint)local_12 % 100,2,100,(int)param_4);
          }
          else {
            param_3 = param_4;
            FUN_00408fb8((uint)local_12,4,puVar5,(int)param_4);
          }
          break;
        case 0x5a:
          FUN_00409004();
          puVar5 = &stack0xfffffffc;
          FUN_00409068();
          if (3 < local_10) {
            local_10 = 3;
          }
          param_3 = param_4;
          FUN_00408fb8((uint)local_20,local_10,puVar5,(int)param_4);
        }
      }
      else {
        if (*pbVar8 == 0) break;
        local_8 = local_8 + 2;
        bVar7 = 0x20;
      }
    }
    local_8 = pbVar8;
    *(int *)(param_4 + -0x108) = *(int *)(param_4 + -0x108) + -1;
  }
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_00409a64;
  puStack_3c = (undefined1 *)0x409a5c;
  FUN_00403b74((int *)&local_2c,2);
  return;
}

