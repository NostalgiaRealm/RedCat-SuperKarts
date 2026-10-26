/*
 * FUN_0040c920 at 0040c920
 * undefined8 __fastcall FUN_0040c920(undefined4 param_1, undefined4 param_2, uint * param_3, int param_4, byte * param_5)
 * Address ranges: 00409f20-00409fd0;0040c920-0040cae5;0040caf0-0040cbba;0040cbc0-0040cc04;0040cc10-0040ccb3;0040ccc0-0040cce6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_0040c920(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,byte *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  uint *puVar6;
  ushort *puVar7;
  char cVar8;
  undefined4 uVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  undefined4 extraout_ECX;
  undefined4 uVar13;
  uint *puVar14;
  short sVar15;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  uint uVar16;
  undefined4 *puVar17;
  uint *puVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  undefined8 uVar21;
  byte *in_stack_ffffffe4;
  
  _DAT_0040e9a4 = param_4;
  puVar17 = (undefined4 *)(param_4 + 0x7414);
  DAT_0040e9d0 = CONCAT22(DAT_0040e9d0._2_2_,(short)*(undefined4 *)(param_4 + 0x7410));
  puVar20 = &DAT_0040e910;
  iVar12 = 4;
  do {
    uVar9 = *puVar17;
    *puVar20 = uVar9;
    puVar1 = (undefined4 *)puVar17[1];
    puVar20[1] = puVar1;
    *puVar1 = uVar9;
    puVar1 = puVar17 + 3;
    puVar2 = (undefined4 *)puVar17[2];
    puVar3 = puVar20 + 3;
    puVar20[2] = puVar2;
    *puVar2 = uVar9;
    puVar17 = puVar17 + 4;
    puVar1 = (undefined4 *)*puVar1;
    puVar20 = puVar20 + 4;
    *puVar3 = puVar1;
    *puVar1 = uVar9;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  _DAT_0040e900 = param_4 + 0x10;
  _DAT_0040e904 = param_4 + 0x2010;
  _DAT_0040e908 = param_4 + 0x3010;
  DAT_0040e90c = param_4 + 0x7010;
  uVar16 = *param_3;
  puVar18 = param_3 + 1;
  DAT_0040e9c0 = 0x21;
  _DAT_0040e9ac = *param_5 & 1 ^ 1;
  if ((param_5[1] & 1) == 0) {
    if (_DAT_0040e9ac == 0) {
      _DAT_0040e950 = &DAT_0040baf0;
      _DAT_0040e954 = &DAT_0040be30;
      _DAT_0040e958 = &DAT_0040c640;
      _DAT_0040e95c = &DAT_0040c790;
    }
    else {
      _DAT_0040e950 = &DAT_0040bb40;
      _DAT_0040e954 = &DAT_0040be80;
      _DAT_0040e958 = &DAT_0040c684;
      _DAT_0040e95c = &DAT_0040c7e0;
    }
    _DAT_0040e9a8 = 0;
  }
  else {
    if (_DAT_0040e9ac == 0) {
      _DAT_0040e950 = &DAT_0040a040;
      _DAT_0040e954 = &DAT_0040a3a0;
      _DAT_0040e958 = &DAT_0040c640;
      _DAT_0040e95c = &DAT_0040abb0;
    }
    else {
      _DAT_0040e950 = &DAT_0040a090;
      _DAT_0040e954 = &DAT_0040a3f0;
      _DAT_0040e958 = &DAT_0040c684;
      _DAT_0040e95c = &DAT_0040ac00;
    }
    _DAT_0040e9a8 = 1;
  }
  if (_DAT_0040e9ac == 0) {
    _DAT_0040e968 = *(uint *)(param_5 + 8);
    DAT_0040e970 = *(uint *)(param_5 + 0xc);
    _DAT_0040e96c = *(uint *)(param_5 + 0x10);
    _DAT_0040e984 = *(uint *)(param_5 + 0x14);
    _DAT_0040e960 = *(uint *)(param_5 + 0x18);
    _DAT_0040e988 = *(uint *)(param_5 + 0x1c);
    in_stack_ffffffe4 = *(byte **)(param_5 + 4);
    DAT_0040e974 = _DAT_0040e968;
    param_5[0x20] = 0;
    param_5[0x21] = 0;
    param_5[0x22] = 0;
    param_5[0x23] = 0;
    param_5[0x2c] = 0;
    param_5[0x2d] = 0;
    param_5[0x2e] = 0;
    param_5[0x2f] = 0;
    param_5[0x30] = 0;
    param_5[0x31] = 0;
    param_5[0x32] = 0;
    param_5[0x33] = 0;
    _DAT_0040eaf8 = param_5 + 0x38;
    _DAT_0040eaf4 = 0;
    DAT_0040eaf0 = 0;
  }
  else {
    DAT_0040e99c = *(code **)(param_5 + 4);
    _DAT_0040e980 = (byte *)(uint)*(ushort *)(param_5 + 8);
    DAT_0040e9a0 = (ushort *)(param_5 + 10);
    if (_DAT_0040e9ac == 0) {
LAB_0040ccc0:
      pbVar19 = in_stack_ffffffe4;
      if ((_DAT_0040e9ac & 1) == 0) {
        pbVar19 = _DAT_0040eaf8 + (DAT_0040eaf0 >> 4);
        *pbVar19 = 0;
      }
      return CONCAT44(in_stack_ffffffe4,pbVar19);
    }
    uVar13 = 0;
    in_stack_ffffffe4 = _DAT_0040e980;
    do {
      puVar7 = DAT_0040e9a0;
      uVar4 = *DAT_0040e9a0;
      if (uVar4 < 0xfffd) {
        (*DAT_0040e99c)(in_stack_ffffffe4,param_2);
        uVar13 = extraout_ECX;
        uVar9 = extraout_EDX_00;
      }
      else if (uVar4 != 0xfffe) {
        if (uVar4 != 0xffff) {
          puVar17 = *(undefined4 **)(DAT_0040e9a0 + 1);
          pbVar19 = *(byte **)(DAT_0040e9a0 + 3);
          uVar11 = DAT_0040e974;
          for (uVar16 = (uint)DAT_0040e9a0[5]; DAT_0040e974 = uVar11, uVar16 != 0;
              uVar16 = uVar16 - 1) {
            for (; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pbVar19 = *puVar17;
              puVar17 = puVar17 + 1;
              pbVar19 = pbVar19 + 4;
            }
            pbVar19 = pbVar19 + (int)_DAT_0040e980;
            uVar11 = DAT_0040e974;
          }
          for (uVar16 = (uint)puVar7[6]; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)pbVar19 = *puVar17;
            puVar17 = puVar17 + 1;
            pbVar19 = pbVar19 + 4;
          }
          (*DAT_0040e99c)(uVar9,uVar13,puVar18,0x40cb43);
          pbVar19 = pbVar19 + 0xffff0000;
          for (uVar16 = (uint)*(ushort *)(extraout_EDX + 0x10); uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)pbVar19 = *puVar17;
            puVar17 = puVar17 + 1;
            pbVar19 = pbVar19 + 4;
          }
          pbVar19 = pbVar19 + (int)_DAT_0040e980;
          uVar11 = DAT_0040e974;
          for (uVar16 = (uint)*(ushort *)(extraout_EDX + 0x12); DAT_0040e974 = uVar11, uVar16 != 0;
              uVar16 = uVar16 - 1) {
            for (; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pbVar19 = *puVar17;
              puVar17 = puVar17 + 1;
              pbVar19 = pbVar19 + 4;
            }
            pbVar19 = pbVar19 + (int)_DAT_0040e980;
            uVar11 = DAT_0040e974;
          }
          _DAT_0040e960 = (uint)*(ushort *)(extraout_EDX + 0x14);
          DAT_0040e974 = (uint)*(ushort *)(extraout_EDX + 0x16);
          _DAT_0040e968 = (uint)*(ushort *)(extraout_EDX + 0x16);
          _DAT_0040e96c = (uint)*(ushort *)(extraout_EDX + 0x18);
          _DAT_0040e984 = (uint)*(ushort *)(extraout_EDX + 0x1a);
          _DAT_0040e988 = (uint)*(ushort *)(extraout_EDX + 0x1c);
          DAT_0040e970 = (uint)*(ushort *)(extraout_EDX + 0x1e);
          DAT_0040e9a0 = (ushort *)(extraout_EDX + 0x20);
          return CONCAT44(uVar9,(uint)*(ushort *)(extraout_EDX + 0x1e));
        }
        goto LAB_0040ccc0;
      }
      _DAT_0040e960 = (uint)puVar7[1];
      _DAT_0040e968 = (uint)puVar7[2];
      _DAT_0040e96c = (uint)puVar7[3];
      _DAT_0040e984 = (uint)puVar7[4];
      _DAT_0040e988 = (uint)puVar7[5];
      DAT_0040e970 = (uint)puVar7[8];
      DAT_0040e9a0 = puVar7 + 9;
      DAT_0040e974 = _DAT_0040e968;
    } while (DAT_0040e970 == 0);
  }
  puVar6 = DAT_0040e948;
  if (DAT_0040e9c0 < 9) {
    uVar11 = *puVar18;
    puVar18 = (uint *)((int)param_3 + 6);
    uVar16 = uVar11 << (DAT_0040e9c0 - 1 & 0x1f) | uVar16;
    uVar11 = *(uint *)(DAT_0040e90c + (uVar16 & 0xff) * 4);
    bVar10 = (byte)uVar11;
    uVar16 = uVar16 >> (bVar10 & 0x1f);
    cVar8 = (DAT_0040e9c0 + 0x10) - bVar10;
    puVar14 = (uint *)((uVar11 >> 8) + _DAT_0040e9a4);
    uVar11 = *puVar14;
    sVar15 = (short)uVar11;
  }
  else {
    uVar11 = *(uint *)(DAT_0040e90c + (uVar16 & 0xff) * 4);
    bVar10 = (byte)uVar11;
    uVar16 = uVar16 >> (bVar10 & 0x1f);
    cVar8 = DAT_0040e9c0 - bVar10;
    puVar14 = (uint *)((uVar11 >> 8) + _DAT_0040e9a4);
    uVar11 = *puVar14;
    sVar15 = (short)uVar11;
  }
  uVar9 = CONCAT31((int3)((uint)in_stack_ffffffe4 >> 8),cVar8);
  while (DAT_0040e9c0 = (byte)uVar9, (short)DAT_0040e9d0 == sVar15) {
    cVar8 = DAT_0040e9c0 + -1;
    if (cVar8 == '\0') {
      uVar16 = *puVar18;
      puVar18 = puVar18 + 1;
      cVar8 = ' ';
    }
    uVar9 = CONCAT31((int3)((uint)uVar9 >> 8),cVar8);
    uVar11 = uVar11 >> 0xd & 0xffff8;
    if ((uVar16 & 1) == 0) {
      uVar11 = 4;
    }
    puVar14 = (uint *)((int)puVar14 + uVar11);
    uVar11 = *puVar14;
    uVar16 = uVar16 >> 1;
    sVar15 = (short)uVar11;
  }
  uVar16 = CONCAT22((short)((uint)uVar9 >> 0x10),(short)(uVar11 >> 0x10));
  if (*DAT_0040e944 != uVar11) {
    uVar5 = *DAT_0040e944;
    DAT_0040e978 = uVar16;
    *DAT_0040e944 = uVar11;
    puVar18 = DAT_0040e94c;
    uVar11 = *puVar6;
    *puVar6 = uVar5;
    uVar16 = DAT_0040e978;
    *puVar18 = uVar11;
  }
  _DAT_0040e964 = *(undefined4 *)(&DAT_0040e9e0 + (uVar16 & 0xfc));
                    /* WARNING: Jumptable at 0x0040ccad did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
  uVar21 = (**(code **)(&DAT_0040e950 + (uVar16 & 3) * 4))();
  return uVar21;
}

