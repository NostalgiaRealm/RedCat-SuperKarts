/*
 * FUN_004247f5 at 004247f5
 * undefined4 __cdecl FUN_004247f5(int param_1)
 * Address ranges: 004247f5-0042498d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004247f5(int param_1)

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
  
  CodePage = FUN_0042498e(param_1);
  if (CodePage == DAT_0043e5bc) {
    return 0;
  }
  if (CodePage != 0) {
    iVar11 = 0;
    pUVar5 = &DAT_00437898;
    do {
      if (*pUVar5 == CodePage) {
        puVar13 = &DAT_0043e6e0;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
        local_8 = 0;
        iVar11 = iVar11 * 0x30;
        *(undefined1 *)puVar13 = 0;
        pbVar12 = (byte *)(iVar11 + 0x4378a8);
        do {
          bVar3 = *pbVar12;
          pbVar10 = pbVar12;
          while ((bVar3 != 0 && (bVar3 = pbVar10[1], bVar3 != 0))) {
            uVar7 = (uint)*pbVar10;
            if (uVar7 <= bVar3) {
              bVar4 = (&DAT_00437890)[local_8];
              do {
                pbVar2 = (byte *)((int)&DAT_0043e6e0 + uVar7 + 1);
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
        DAT_0043e5cc = 1;
        DAT_0043e5bc = CodePage;
        DAT_0043e7e4 = FUN_004249d8(CodePage);
        DAT_0043e5c0 = *(undefined4 *)(iVar11 + 0x43789c);
        DAT_0043e5c4 = *(undefined4 *)(iVar11 + 0x4378a0);
        DAT_0043e5c8 = *(undefined4 *)(iVar11 + 0x4378a4);
        goto LAB_0042497d;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar11 = iVar11 + 1;
    } while ((int)pUVar5 < 0x437988);
    BVar6 = GetCPInfo(CodePage,&local_1c);
    if (BVar6 == 1) {
      puVar13 = &DAT_0043e6e0;
      DAT_0043e5bc = CodePage;
      for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      *(undefined1 *)puVar13 = 0;
      DAT_0043e7e4 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_0043e5cc = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar8 = local_1c.LeadByte + 1;
          do {
            bVar3 = *pBVar8;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar8[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              pbVar12 = (byte *)((int)&DAT_0043e6e0 + uVar7 + 1);
              *pbVar12 = *pbVar12 | 4;
            }
            pBVar1 = pBVar8 + 1;
            pBVar8 = pBVar8 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          pbVar12 = (byte *)((int)&DAT_0043e6e0 + uVar7 + 1);
          *pbVar12 = *pbVar12 | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_0043e7e4 = FUN_004249d8(CodePage);
        DAT_0043e5cc = 1;
      }
      DAT_0043e5c0 = 0;
      DAT_0043e5c4 = 0;
      DAT_0043e5c8 = 0;
      goto LAB_0042497d;
    }
    if (DAT_0043e470 == 0) {
      return 0xffffffff;
    }
  }
  FUN_00424a0b();
LAB_0042497d:
  FUN_00424a34();
  return 0;
}

