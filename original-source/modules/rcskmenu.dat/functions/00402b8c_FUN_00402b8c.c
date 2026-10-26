/*
 * FUN_00402b8c at 00402b8c
 * undefined __register FUN_00402b8c(byte * param_1, int * param_2)
 * Address ranges: 00402b8c-00402c56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402b8c(byte *param_1,int *param_2)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  
  pbVar6 = (byte *)0x0;
  if (param_1 == (byte *)0x0) {
LAB_00402c09:
    pbVar6 = pbVar6 + 1;
  }
  else {
    uVar2 = 0;
    pbVar6 = param_1;
    do {
      pbVar5 = pbVar6;
      bVar3 = *pbVar5;
      pbVar6 = pbVar5 + 1;
    } while (bVar3 == 0x20);
    bVar1 = false;
    if (bVar3 != 0x2d) {
      if (bVar3 == 0x2b) goto LAB_00402c19;
      if (((bVar3 != 0x24) && (bVar3 != 0x78)) && (bVar3 != 0x58)) {
        if (bVar3 == 0x30) {
          bVar3 = *pbVar6;
          pbVar6 = pbVar5 + 2;
          if ((bVar3 != 0x78) && (bVar3 != 0x58)) goto joined_r0x00402bd6;
          goto LAB_00402c1e;
        }
        goto LAB_00402bda;
      }
LAB_00402c1e:
      bVar3 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      if (bVar3 == 0) goto LAB_00402c09;
      do {
        if (0x60 < bVar3) {
          bVar3 = bVar3 - 0x20;
        }
        bVar4 = bVar3 - 0x30;
        if (9 < bVar4) {
          if (5 < (byte)(bVar3 + 0xbf)) goto LAB_00402c12;
          bVar4 = bVar3 - 0x37;
        }
        if (0xfffffff < uVar2) goto LAB_00402c12;
        uVar2 = uVar2 * 0x10 + (uint)bVar4;
        bVar3 = *pbVar6;
        pbVar6 = pbVar6 + 1;
      } while (bVar3 != 0);
      goto LAB_00402c00;
    }
    bVar1 = true;
LAB_00402c19:
    bVar3 = *pbVar6;
    pbVar6 = pbVar5 + 2;
LAB_00402bda:
    if (bVar3 != 0) {
      do {
        if ((9 < (byte)(bVar3 - 0x30)) || (0xccccccc < uVar2)) goto LAB_00402c12;
        uVar2 = uVar2 * 10 + (uint)(byte)(bVar3 - 0x30);
        bVar3 = *pbVar6;
        pbVar6 = pbVar6 + 1;
joined_r0x00402bd6:
      } while (bVar3 != 0);
      if (bVar1) {
        if ((-uVar2 == 0 || 0 < (int)uVar2) || ((int)-uVar2 < 0)) goto LAB_00402c00;
      }
      else if (-1 < (int)uVar2) {
LAB_00402c00:
        iVar7 = 0;
        goto LAB_00402c03;
      }
    }
  }
LAB_00402c12:
  iVar7 = (int)pbVar6 - (int)param_1;
LAB_00402c03:
  *param_2 = iVar7;
  return;
}

