/*
 * FUN_0040ccf0 at 0040ccf0
 * undefined __cdecl FUN_0040ccf0(uint * param_1, int param_2, uint * param_3, uint * param_4, uint * param_5, uint * param_6)
 * Address ranges: 0040ccf0-0040d517
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0040cd56) */
/* WARNING: Removing unreachable block (ram,0x0040cd73) */
/* WARNING: Removing unreachable block (ram,0x0040d03d) */
/* WARNING: Removing unreachable block (ram,0x0040ce88) */
/* WARNING: Removing unreachable block (ram,0x0040d05a) */
/* WARNING: Removing unreachable block (ram,0x0040cd90) */
/* WARNING: Removing unreachable block (ram,0x0040d209) */

void __cdecl
FUN_0040ccf0(uint *param_1,int param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  undefined2 uVar9;
  ushort uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  
  DAT_0040ef20 = param_2;
  DAT_0040ef24 = param_3;
  DAT_0040ef28 = param_4;
  DAT_0040ef2c = param_5;
  DAT_0040ef30 = param_6;
  uVar12 = *param_1;
  puVar13 = param_1 + 1;
  DAT_0040e9c0 = 0x20;
  if ((uVar12 & 1) != 0) {
    if ((uVar12 >> 1 & 1) == 0) {
      if ((uVar12 >> 2 & 1) == 0) {
        DAT_0040e9c0 = 0x1d;
        DAT_0040e98c = param_3;
        FUN_00409800();
        bVar2 = DAT_0040e9c0;
        if (DAT_0040ef20 != 0) {
          DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
          if (DAT_0040ef2c < DAT_0040eafc) {
            DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
          }
          bVar8 = (byte)(uVar12 >> 4);
          puVar14 = DAT_0040ef30;
          if (DAT_0040e9c0 < 9) {
            DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
            uVar12 = *puVar13;
            bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
            puVar13 = param_1 + 2;
            uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
          }
          else {
            DAT_0040e9c0 = DAT_0040e9c0 - 8;
            uVar12 = uVar12 >> 0xc;
          }
          while( true ) {
            *(byte *)puVar14 = bVar8;
            puVar14 = (uint *)((int)puVar14 + 1);
            if (DAT_0040eafc == puVar14) break;
            if (DAT_0040ef2c == puVar14) {
              puVar14 = DAT_0040ef28;
            }
            uVar5 = *DAT_0040e98c;
            puVar11 = DAT_0040e98c;
            while ((uVar5 & 0x80000000) == 0) {
              DAT_0040e9c0 = DAT_0040e9c0 - 1;
              if (DAT_0040e9c0 == 0) {
                uVar12 = *puVar13;
                puVar13 = puVar13 + 1;
                DAT_0040e9c0 = 0x20;
              }
              if ((uVar12 & 1) == 0) {
                uVar5 = 4;
              }
              puVar11 = (uint *)((int)puVar11 + uVar5);
              uVar12 = uVar12 >> 1;
              uVar5 = *puVar11;
            }
            bVar8 = bVar8 + (char)uVar5;
          }
        }
      }
      else {
        DAT_0040e9c0 = '\x1d';
        uVar12 = uVar12 >> 4;
        DAT_0040e98c = param_3;
        FUN_00409800();
        DAT_0040e9c0 = DAT_0040e9c0 - 1;
        if (DAT_0040e9c0 == 0) {
          uVar12 = *puVar13;
          puVar13 = param_1 + 2;
          DAT_0040e9c0 = 0x20;
        }
        DAT_0040e990 = DAT_0040ef24 + 0x200;
        FUN_00409800();
        bVar2 = DAT_0040e9c0;
        if (DAT_0040ef20 != 0) {
          DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
          if (DAT_0040ef2c < DAT_0040eafc) {
            DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
          }
          bVar8 = (byte)(uVar12 >> 1);
          if (DAT_0040e9c0 < 9) {
            DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
            uVar12 = *puVar13;
            bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
            puVar13 = puVar13 + 1;
            uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
          }
          else {
            DAT_0040e9c0 = DAT_0040e9c0 - 8;
            uVar12 = uVar12 >> 9;
          }
          bVar3 = DAT_0040e9c0;
          bVar2 = (byte)uVar12;
          if (DAT_0040e9c0 < 9) {
            DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
            uVar12 = *puVar13;
            bVar2 = bVar2 | (byte)(uVar12 << (bVar3 - 1 & 0x1f));
            puVar13 = puVar13 + 1;
            uVar12 = uVar12 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
          }
          else {
            DAT_0040e9c0 = DAT_0040e9c0 - 8;
            uVar12 = uVar12 >> 8;
          }
          uVar9 = CONCAT11(bVar8,bVar2);
          puVar14 = DAT_0040ef30;
          while( true ) {
            *(undefined2 *)puVar14 = uVar9;
            puVar14 = (uint *)((int)puVar14 + 2);
            if (DAT_0040eafc == puVar14) break;
            if (DAT_0040ef2c == puVar14) {
              puVar14 = DAT_0040ef28;
            }
            uVar5 = *DAT_0040e98c;
            puVar11 = DAT_0040e98c;
            while ((uVar5 & 0x80000000) == 0) {
              DAT_0040e9c0 = DAT_0040e9c0 - 1;
              if (DAT_0040e9c0 == 0) {
                uVar12 = *puVar13;
                puVar13 = puVar13 + 1;
                DAT_0040e9c0 = 0x20;
              }
              if ((uVar12 & 1) == 0) {
                uVar5 = 4;
              }
              puVar11 = (uint *)((int)puVar11 + uVar5);
              uVar12 = uVar12 >> 1;
              uVar5 = *puVar11;
            }
            uVar6 = *DAT_0040e990;
            puVar11 = DAT_0040e990;
            while ((uVar6 & 0x80000000) == 0) {
              DAT_0040e9c0 = DAT_0040e9c0 - 1;
              if (DAT_0040e9c0 == 0) {
                uVar12 = *puVar13;
                puVar13 = puVar13 + 1;
                DAT_0040e9c0 = 0x20;
              }
              if ((uVar12 & 1) == 0) {
                uVar6 = 4;
              }
              puVar11 = (uint *)((int)puVar11 + uVar6);
              uVar12 = uVar12 >> 1;
              uVar6 = *puVar11;
            }
            uVar9 = CONCAT11((char)((ushort)uVar9 >> 8) + CARRY1((byte)uVar9,(byte)uVar5) +
                             (char)uVar6,(byte)uVar9 + (byte)uVar5);
          }
        }
      }
    }
    else if ((uVar12 >> 2 & 1) == 0) {
      DAT_0040e9c0 = '\x1d';
      uVar12 = uVar12 >> 4;
      DAT_0040e98c = param_3;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 - 1;
      if (DAT_0040e9c0 == 0) {
        uVar12 = *puVar13;
        puVar13 = param_1 + 2;
        DAT_0040e9c0 = 0x20;
      }
      DAT_0040e990 = DAT_0040ef24 + 0x200;
      FUN_00409800();
      bVar2 = DAT_0040e9c0;
      if (DAT_0040ef20 != 0) {
        DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
        if (DAT_0040ef2c < DAT_0040eafc) {
          DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
        }
        bVar8 = (byte)(uVar12 >> 1);
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 9;
        }
        bVar3 = DAT_0040e9c0;
        bVar2 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar2 = bVar2 | (byte)(uVar12 << (bVar3 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        uVar9 = CONCAT11(bVar8,bVar2);
        puVar14 = DAT_0040ef30;
        while( true ) {
          *(undefined2 *)puVar14 = uVar9;
          puVar14 = (uint *)((int)puVar14 + 2);
          if (DAT_0040eafc == puVar14) break;
          if (DAT_0040ef2c == puVar14) {
            puVar14 = DAT_0040ef28;
          }
          uVar5 = *DAT_0040e98c;
          puVar11 = DAT_0040e98c;
          while ((uVar5 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar5 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar5);
            uVar12 = uVar12 >> 1;
            uVar5 = *puVar11;
          }
          uVar6 = *DAT_0040e990;
          puVar11 = DAT_0040e990;
          while ((uVar6 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar6 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar6);
            uVar12 = uVar12 >> 1;
            uVar6 = *puVar11;
          }
          uVar9 = CONCAT11((char)((ushort)uVar9 >> 8) + (char)uVar6,(char)uVar9 + (char)uVar5);
        }
      }
    }
    else {
      DAT_0040e9c0 = '\x1d';
      uVar12 = uVar12 >> 4;
      DAT_0040e98c = param_3;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar12 = *puVar13;
        puVar13 = param_1 + 2;
        DAT_0040e9c0 = ' ';
      }
      uVar12 = uVar12 >> 1;
      DAT_0040e990 = DAT_0040ef24 + 0x200;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar12 = *puVar13;
        puVar13 = puVar13 + 1;
        DAT_0040e9c0 = ' ';
      }
      uVar12 = uVar12 >> 1;
      DAT_0040e994 = DAT_0040ef24 + 0x400;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 - 1;
      if (DAT_0040e9c0 == 0) {
        uVar12 = *puVar13;
        puVar13 = puVar13 + 1;
        DAT_0040e9c0 = 0x20;
      }
      DAT_0040e998 = DAT_0040ef24 + 0x600;
      FUN_00409800();
      bVar2 = DAT_0040e9c0;
      if (DAT_0040ef20 != 0) {
        DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
        if (DAT_0040ef2c < DAT_0040eafc) {
          DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
        }
        bVar8 = (byte)(uVar12 >> 1);
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 9;
        }
        bVar3 = DAT_0040e9c0;
        bVar2 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar2 = bVar2 | (byte)(uVar12 << (bVar3 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        bVar4 = DAT_0040e9c0;
        bVar3 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar3 = bVar3 | (byte)(uVar12 << (bVar4 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar4 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        bVar1 = DAT_0040e9c0;
        bVar4 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar4 = bVar4 | (byte)(uVar12 << (bVar1 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        uVar5 = CONCAT31(CONCAT21(CONCAT11(bVar8,bVar2),bVar3),bVar4);
        puVar14 = DAT_0040ef30;
        while( true ) {
          *puVar14 = uVar5;
          puVar14 = puVar14 + 1;
          if (DAT_0040eafc == puVar14) break;
          if (DAT_0040ef2c == puVar14) {
            puVar14 = DAT_0040ef28;
          }
          uVar6 = *DAT_0040e98c;
          puVar11 = DAT_0040e98c;
          while ((uVar6 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar6 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar6);
            uVar12 = uVar12 >> 1;
            uVar6 = *puVar11;
          }
          uVar7 = *DAT_0040e990;
          puVar11 = DAT_0040e990;
          while ((uVar7 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar7 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar7);
            uVar12 = uVar12 >> 1;
            uVar7 = *puVar11;
          }
          uVar10 = CONCAT11((char)(uVar5 >> 8) + CARRY1((byte)uVar5,(byte)uVar6) + (char)uVar7,
                            (byte)uVar5 + (byte)uVar6);
          uVar6 = *DAT_0040e994;
          puVar11 = DAT_0040e994;
          while ((uVar6 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar6 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar6);
            uVar12 = uVar12 >> 1;
            uVar6 = *puVar11;
          }
          bVar2 = (byte)(uVar5 >> 0x10);
          uVar7 = *DAT_0040e998;
          puVar11 = DAT_0040e998;
          while ((uVar7 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar7 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar7);
            uVar12 = uVar12 >> 1;
            uVar7 = *puVar11;
          }
          uVar5 = (uint)uVar10 |
                  CONCAT22(uVar10,CONCAT11((char)(uVar5 >> 0x18) + CARRY1(bVar2,(byte)uVar6) +
                                           (char)uVar7,bVar2 + (byte)uVar6)) << 0x10;
        }
      }
    }
  }
  return;
}

