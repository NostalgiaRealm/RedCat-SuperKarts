/*
 * FUN_004b2c80 at 004b2c80
 * undefined FUN_004b2c80(void)
 * Address ranges: 004b2c80-004b3077
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b2c80(undefined4 param_1,int *param_2,int *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  undefined4 *puVar13;
  int local_3a0;
  int local_394;
  undefined4 local_390;
  undefined4 local_38c;
  int local_388;
  int local_384;
  char local_380;
  char local_37f;
  short local_37c;
  short local_37a;
  short local_378;
  short local_376;
  short local_33e;
  undefined1 local_300 [768];
  
  iVar3 = FUN_004b96d0(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  local_388 = iVar3;
  if (DAT_006ab82c != 0) {
    FUN_004b2680(iVar3,local_300);
  }
  FUN_004b9570(iVar3,0,0);
  FUN_004bf930(&local_380,0x80,1,iVar3);
  FUN_004afce0(s__s__d____header_read__004fff84,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x25f);
  if ((*(byte *)(iVar3 + 0xc) & 0x20) == 0) {
    FUN_004afce0(s__s__d____no_error_header_read__004fff60,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,
                 0x265);
    uVar5 = local_38c;
    if ((local_380 == '\n') && (local_37f == '\x05')) {
      iVar4 = ((int)local_376 - (int)local_37a) + 1;
      *param_2 = ((int)local_378 - (int)local_37c) + 1;
      *param_3 = iVar4;
      FUN_004afce0(s_creating_surface__d__d_004fdaf4,*param_2,iVar4);
      uVar5 = FUN_004b0900(*param_2,*param_3);
      local_38c = uVar5;
      FUN_004afce0(s_creation_succesfull_004fff48);
      local_384 = (int)local_33e;
      local_3a0 = *param_3;
      FUN_004b08e0(uVar5);
      if (DAT_006ab82c == 0) {
        iVar4 = FUN_004b0770(uVar5,&local_394);
        if (0 < local_3a0) {
          do {
            iVar10 = 0;
            do {
              uVar6 = FUN_004c09f0(iVar3);
              if (((byte)uVar6 & 0xc0) == 0xc0) {
                uVar1 = FUN_004c09f0(iVar3);
                puVar13 = (undefined4 *)(iVar4 + iVar10);
                for (uVar7 = (uVar6 & 0x3f) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *puVar13 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
                  puVar13 = puVar13 + 1;
                }
                iVar10 = iVar10 + (uVar6 & 0x3f);
                for (uVar6 = uVar6 & 3; iVar3 = local_388, uVar6 != 0; uVar6 = uVar6 - 1) {
                  *(undefined1 *)puVar13 = uVar1;
                  puVar13 = (undefined4 *)((int)puVar13 + 1);
                }
              }
              else {
                *(byte *)(iVar4 + iVar10) = (byte)uVar6;
                iVar10 = iVar10 + 1;
              }
            } while (iVar10 < local_384);
            iVar4 = iVar4 + local_394;
            local_3a0 = local_3a0 + -1;
            uVar5 = local_38c;
          } while (local_3a0 != 0);
        }
        FUN_004b08a0(uVar5,iVar4);
      }
      else if (DAT_006ab82c == 1) {
        iVar4 = FUN_004b0770(uVar5,&local_394);
        if (0 < local_3a0) {
          do {
            iVar10 = 0;
            do {
              uVar6 = FUN_004c09f0(iVar3);
              if (((byte)uVar6 & 0xc0) == 0xc0) {
                uVar7 = uVar6 & 0x3f;
                uVar1 = FUN_004c09f0(iVar3);
                uVar2 = FUN_004b5740(uVar1,8);
                if (uVar7 != 0) {
                  puVar13 = (undefined4 *)(iVar4 + iVar10 * 2);
                  for (uVar9 = uVar7 >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *puVar13 = CONCAT22(uVar2,uVar2);
                    puVar13 = puVar13 + 1;
                  }
                  iVar10 = iVar10 + uVar7;
                  for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
                    *(undefined2 *)puVar13 = uVar2;
                    puVar13 = (undefined4 *)((int)puVar13 + 2);
                  }
                }
              }
              else {
                uVar2 = FUN_004b5740(uVar6 & 0xff,8);
                *(undefined2 *)(iVar4 + iVar10 * 2) = uVar2;
                iVar10 = iVar10 + 1;
              }
            } while (iVar10 < local_384);
            iVar4 = iVar4 + local_394;
            local_3a0 = local_3a0 + -1;
            uVar5 = local_38c;
          } while (local_3a0 != 0);
        }
        FUN_004b08a0(uVar5,iVar4);
      }
      else if (DAT_006ab82c == 2) {
        iVar4 = FUN_004b0770(uVar5,&local_394);
        if (0 < local_3a0) {
          do {
            iVar10 = 0;
            do {
              uVar6 = FUN_004c09f0(iVar3);
              if (((byte)uVar6 & 0xc0) == 0xc0) {
                uVar6 = uVar6 & 0x3f;
                uVar1 = FUN_004c09f0(local_388);
                uVar5 = FUN_004b5740(uVar1,8);
                iVar3 = local_388;
                local_390 = uVar5;
                if (uVar6 != 0) {
                  puVar11 = (undefined2 *)(iVar4 + iVar10 * 3);
                  local_390._2_1_ = (undefined1)((uint)uVar5 >> 0x10);
                  iVar10 = iVar10 + uVar6;
                  *puVar11 = (short)uVar5;
                  *(undefined1 *)(puVar11 + 1) = local_390._2_1_;
                  puVar12 = (undefined1 *)((int)puVar11 + 3);
                  for (iVar8 = uVar6 * 3 + -3; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar12 = *(undefined1 *)puVar11;
                    puVar11 = (undefined2 *)((int)puVar11 + 1);
                    puVar12 = puVar12 + 1;
                  }
                }
              }
              else {
                uVar5 = FUN_004b5740(uVar6 & 0xff,8);
                local_390._0_2_ = (undefined2)uVar5;
                puVar11 = (undefined2 *)(iVar4 + iVar10 * 3);
                local_390._2_1_ = (undefined1)((uint)uVar5 >> 0x10);
                iVar10 = iVar10 + 1;
                *puVar11 = (undefined2)local_390;
                *(undefined1 *)(puVar11 + 1) = local_390._2_1_;
                local_390 = uVar5;
              }
            } while (iVar10 < local_384);
            iVar4 = iVar4 + local_394;
            local_3a0 = local_3a0 + -1;
            uVar5 = local_38c;
          } while (local_3a0 != 0);
        }
        FUN_004b08a0(uVar5,iVar4);
      }
    }
    FUN_004afce0(s__s__d____closing_004fff34,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x270,*param_2
                 ,*param_3);
    FUN_004b9840(iVar3);
    return uVar5;
  }
  FUN_004b9840(iVar3);
  return 0;
}

