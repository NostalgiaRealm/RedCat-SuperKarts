/*
 * FUN_004c6f00 at 004c6f00
 * undefined FUN_004c6f00(void)
 * Address ranges: 004c6f00-004c7098
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c6f00(undefined4 param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  BYTE *pBVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  _cpinfo local_1c;
  uint local_8;
  
  CodePage = FUN_004c7099(param_1);
  if (CodePage == DAT_006b6b64) {
    return 0;
  }
  if (CodePage != 0) {
    iVar11 = 0;
    pUVar5 = &DAT_00503358;
    do {
      if (*pUVar5 == CodePage) {
        puVar13 = &DAT_006b6c80;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
        local_8 = 0;
        iVar11 = iVar11 * 0x30;
        *(undefined1 *)puVar13 = 0;
        pbVar12 = (byte *)(iVar11 + 0x503368);
        do {
          bVar3 = *pbVar12;
          pbVar10 = pbVar12;
          while ((bVar3 != 0 && (bVar3 = pbVar10[1], bVar3 != 0))) {
            uVar7 = (uint)*pbVar10;
            if (uVar7 <= bVar3) {
              bVar4 = (&DAT_00503350)[local_8];
              do {
                pbVar2 = (byte *)((int)&DAT_006b6c80 + uVar7 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar7 = uVar7 + 1;
              } while (uVar7 <= bVar3);
            }
            pbVar10 = pbVar10 + 2;
            bVar3 = *pbVar10;
          }
          local_8 = local_8 + 1;
          pbVar12 = pbVar12 + 8;
        } while (local_8 < 4);
        DAT_006b6b7c = 1;
        DAT_006b6b64 = CodePage;
        DAT_006b6d84 = FUN_004c70e3(CodePage);
        DAT_006b6b70 = *(undefined4 *)(iVar11 + 0x50335c);
        DAT_006b6b74 = *(undefined4 *)(iVar11 + 0x503360);
        DAT_006b6b78 = *(undefined4 *)(iVar11 + 0x503364);
        goto LAB_004c7088;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar11 = iVar11 + 1;
    } while ((int)pUVar5 < 0x503448);
    BVar6 = GetCPInfo(CodePage,&local_1c);
    if (BVar6 == 1) {
      puVar13 = &DAT_006b6c80;
      DAT_006b6b64 = CodePage;
      for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      *(undefined1 *)puVar13 = 0;
      DAT_006b6d84 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_006b6b7c = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar8 = local_1c.LeadByte + 1;
          do {
            bVar3 = *pBVar8;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar8[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              pbVar12 = (byte *)((int)&DAT_006b6c80 + uVar7 + 1);
              *pbVar12 = *pbVar12 | 4;
            }
            pBVar1 = pBVar8 + 1;
            pBVar8 = pBVar8 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          pbVar12 = (byte *)((int)&DAT_006b6c80 + uVar7 + 1);
          *pbVar12 = *pbVar12 | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_006b6d84 = FUN_004c70e3(CodePage);
        DAT_006b6b7c = 1;
      }
      DAT_006b6b70 = 0;
      DAT_006b6b74 = 0;
      DAT_006b6b78 = 0;
      goto LAB_004c7088;
    }
    if (DAT_006b67c4 == 0) {
      return 0xffffffff;
    }
  }
  FUN_004c7116();
LAB_004c7088:
  FUN_004c713f();
  return 0;
}

