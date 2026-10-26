/*
 * FUN_004b3080 at 004b3080
 * undefined FUN_004b3080(void)
 * Address ranges: 004b3080-004b3491
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004b3080(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 *param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  char **ppcVar14;
  undefined1 *puVar15;
  char *apcStack_3d0 [2];
  int iStack_3c8;
  undefined4 uStack_3c4;
  undefined4 *puStack_3c0;
  char *pcStack_3bc;
  char *pcStack_3b8;
  int *piStack_3b4;
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
  
  puVar12 = param_5;
  ppcVar14 = apcStack_3d0;
  for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
    *ppcVar14 = (char *)*puVar12;
    puVar12 = puVar12 + 1;
    ppcVar14 = ppcVar14 + 1;
  }
  FUN_004b5c20();
  iVar8 = FUN_004b96d0(param_1);
  if (iVar8 != 0) {
    local_388 = iVar8;
    if (DAT_006ab82c != 0) {
      piStack_3b4 = (int *)local_300;
      pcStack_3bc = (char *)0x4b30e0;
      pcStack_3b8 = (char *)iVar8;
      FUN_004b2680();
    }
    piStack_3b4 = (int *)0x0;
    pcStack_3b8 = (char *)0x0;
    puStack_3c0 = (undefined4 *)0x4b30ed;
    pcStack_3bc = (char *)iVar8;
    FUN_004b9570();
    uStack_3c4 = 1;
    apcStack_3d0[1] = &local_380;
    iStack_3c8 = 0x80;
    apcStack_3d0[0] = (char *)0x4b30ff;
    puStack_3c0 = (undefined4 *)iVar8;
    FUN_004bf930();
    apcStack_3d0[0] = (char *)0x2b1;
    FUN_004afce0(s__s__d____header_read__004fff84,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00);
    if ((*(byte *)(iVar8 + 0xc) & 0x20) == 0) {
      piStack_3b4 = (int *)0x2b7;
      pcStack_3b8 = s_C__libraries_dxdraw_Rcpcx_cpp_004fff00;
      pcStack_3bc = s__s__d____no_error_header_read__004fff60;
      puStack_3c0 = (undefined4 *)0x4b3147;
      FUN_004afce0();
      uVar4 = local_38c;
      if ((local_380 == '\n') && (local_37f == '\x05')) {
        piStack_3b4 = (int *)(((int)local_376 - (int)local_37a) + 1);
        *param_2 = ((int)local_378 - (int)local_37c) + 1;
        *param_3 = (int)piStack_3b4;
        pcStack_3b8 = (char *)*param_2;
        pcStack_3bc = s_creating_surface__d__d_004fdaf4;
        puStack_3c0 = (undefined4 *)0x4b319b;
        FUN_004afce0();
        iStack_3c8 = *param_3;
        apcStack_3d0[1] = (char *)*param_2;
        puStack_3c0 = param_5;
        uStack_3c4 = param_4;
        apcStack_3d0[0] = (char *)0x4b31af;
        uVar4 = FUN_004b0a10();
        apcStack_3d0[0] = s_creation_succesfull_004fff48;
        local_38c = uVar4;
        FUN_004afce0();
        local_384 = (int)local_33e;
        local_3a0 = *param_3;
        FUN_004b08e0(uVar4);
        pcStack_3b8 = (char *)uVar4;
        if (DAT_006ab82c == 0) {
          piStack_3b4 = &local_394;
          pcStack_3bc = (char *)0x4b33cd;
          iVar5 = FUN_004b0770();
          if (0 < local_3a0) {
            do {
              iVar11 = 0;
              do {
                pcStack_3b8 = (char *)0x4b33e6;
                piStack_3b4 = (int *)iVar8;
                uVar6 = FUN_004c09f0();
                if (((byte)uVar6 & 0xc0) == 0xc0) {
                  pcStack_3b8 = (char *)0x4b33fe;
                  piStack_3b4 = (int *)iVar8;
                  uVar2 = FUN_004c09f0();
                  puVar12 = (undefined4 *)(iVar5 + iVar11);
                  for (uVar7 = (uVar6 & 0x3f) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *puVar12 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
                    puVar12 = puVar12 + 1;
                  }
                  iVar11 = iVar11 + (uVar6 & 0x3f);
                  for (uVar6 = uVar6 & 3; iVar8 = local_388, uVar6 != 0; uVar6 = uVar6 - 1) {
                    *(undefined1 *)puVar12 = uVar2;
                    puVar12 = (undefined4 *)((int)puVar12 + 1);
                  }
                }
                else {
                  *(byte *)(iVar5 + iVar11) = (byte)uVar6;
                  iVar11 = iVar11 + 1;
                }
              } while (iVar11 < local_384);
              iVar5 = iVar5 + local_394;
              local_3a0 = local_3a0 + -1;
              uVar4 = local_38c;
            } while (local_3a0 != 0);
          }
          pcStack_3bc = (char *)0x4b345a;
          pcStack_3b8 = (char *)uVar4;
          piStack_3b4 = (int *)iVar5;
          FUN_004b08a0();
        }
        else if (DAT_006ab82c == 1) {
          piStack_3b4 = &local_394;
          pcStack_3bc = (char *)0x4b3301;
          iVar5 = FUN_004b0770();
          if (0 < local_3a0) {
            do {
              iVar11 = 0;
              do {
                pcStack_3b8 = (char *)0x4b331e;
                piStack_3b4 = (int *)iVar8;
                uVar6 = FUN_004c09f0();
                if (((byte)uVar6 & 0xc0) == 0xc0) {
                  uVar7 = uVar6 & 0x3f;
                  pcStack_3b8 = (char *)0x4b333a;
                  piStack_3b4 = (int *)iVar8;
                  bVar1 = FUN_004c09f0();
                  pcStack_3b8 = (char *)0x8;
                  pcStack_3bc = (char *)(uint)bVar1;
                  puStack_3c0 = (undefined4 *)0x4b334f;
                  uVar3 = FUN_004b5740();
                  if (uVar7 != 0) {
                    puVar12 = (undefined4 *)(iVar5 + iVar11 * 2);
                    for (uVar10 = uVar7 >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                      *puVar12 = CONCAT22(uVar3,uVar3);
                      puVar12 = puVar12 + 1;
                    }
                    iVar11 = iVar11 + uVar7;
                    for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
                      *(undefined2 *)puVar12 = uVar3;
                      puVar12 = (undefined4 *)((int)puVar12 + 2);
                    }
                  }
                }
                else {
                  piStack_3b4 = (int *)0x8;
                  pcStack_3b8 = (char *)(uVar6 & 0xff);
                  pcStack_3bc = (char *)0x4b3388;
                  uVar3 = FUN_004b5740();
                  *(undefined2 *)(iVar5 + iVar11 * 2) = uVar3;
                  iVar11 = iVar11 + 1;
                }
              } while (iVar11 < local_384);
              iVar5 = iVar5 + local_394;
              local_3a0 = local_3a0 + -1;
              uVar4 = local_38c;
            } while (local_3a0 != 0);
          }
          pcStack_3bc = (char *)0x4b33ba;
          pcStack_3b8 = (char *)uVar4;
          piStack_3b4 = (int *)iVar5;
          FUN_004b08a0();
        }
        else if (DAT_006ab82c == 2) {
          piStack_3b4 = &local_394;
          pcStack_3bc = (char *)0x4b3201;
          iVar5 = FUN_004b0770();
          if (0 < local_3a0) {
            do {
              iVar11 = 0;
              do {
                pcStack_3b8 = (char *)0x4b3222;
                piStack_3b4 = (int *)iVar8;
                uVar6 = FUN_004c09f0();
                if (((byte)uVar6 & 0xc0) == 0xc0) {
                  uVar6 = uVar6 & 0x3f;
                  piStack_3b4 = (int *)local_388;
                  pcStack_3b8 = (char *)0x4b3242;
                  bVar1 = FUN_004c09f0();
                  pcStack_3b8 = (char *)0x8;
                  pcStack_3bc = (char *)(uint)bVar1;
                  puStack_3c0 = (undefined4 *)0x4b3257;
                  uVar4 = FUN_004b5740();
                  iVar8 = local_388;
                  local_390 = uVar4;
                  if (uVar6 != 0) {
                    puVar13 = (undefined2 *)(iVar5 + iVar11 * 3);
                    local_390._2_1_ = (undefined1)((uint)uVar4 >> 0x10);
                    iVar11 = iVar11 + uVar6;
                    *puVar13 = (short)uVar4;
                    *(undefined1 *)(puVar13 + 1) = local_390._2_1_;
                    puVar15 = (undefined1 *)((int)puVar13 + 3);
                    for (iVar9 = uVar6 * 3 + -3; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *puVar15 = *(undefined1 *)puVar13;
                      puVar13 = (undefined2 *)((int)puVar13 + 1);
                      puVar15 = puVar15 + 1;
                    }
                  }
                }
                else {
                  piStack_3b4 = (int *)0x8;
                  pcStack_3b8 = (char *)(uVar6 & 0xff);
                  pcStack_3bc = (char *)0x4b329c;
                  uVar4 = FUN_004b5740();
                  local_390._0_2_ = (undefined2)uVar4;
                  puVar13 = (undefined2 *)(iVar5 + iVar11 * 3);
                  local_390._2_1_ = (undefined1)((uint)uVar4 >> 0x10);
                  iVar11 = iVar11 + 1;
                  *puVar13 = (undefined2)local_390;
                  *(undefined1 *)(puVar13 + 1) = local_390._2_1_;
                  local_390 = uVar4;
                }
              } while (iVar11 < local_384);
              iVar5 = iVar5 + local_394;
              local_3a0 = local_3a0 + -1;
              uVar4 = local_38c;
            } while (local_3a0 != 0);
          }
          pcStack_3bc = (char *)0x4b32ee;
          pcStack_3b8 = (char *)uVar4;
          piStack_3b4 = (int *)iVar5;
          FUN_004b08a0();
        }
      }
      piStack_3b4 = (int *)0x2c2;
      pcStack_3b8 = s_C__libraries_dxdraw_Rcpcx_cpp_004fff00;
      pcStack_3bc = s__s__d____closing_004fff34;
      puStack_3c0 = (undefined4 *)0x4b3477;
      FUN_004afce0();
      uStack_3c4 = 0x4b347d;
      puStack_3c0 = (undefined4 *)iVar8;
      FUN_004b9840();
      piStack_3b4 = (int *)0x4b3485;
      FUN_004b5ad0();
      return uVar4;
    }
    pcStack_3b8 = (char *)0x4b3123;
    piStack_3b4 = (int *)iVar8;
    FUN_004b9840();
    return 0;
  }
  return 0;
}

