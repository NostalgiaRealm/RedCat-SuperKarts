/*
 * _SmackBufferNewPalette@12 at 00401910
 * undefined __stdcall _SmackBufferNewPalette@12(int param_1, int param_2, byte param_3)
 * Address ranges: 00401910-00401b3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SmackBufferNewPalette_12(int param_1,int param_2,byte param_3)

{
  PALETTEENTRY *pPVar1;
  int iVar2;
  byte bVar3;
  HPALETTE pHVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  LOGPALETTE local_420 [128];
  int local_1c;
  uint local_18;
  byte local_14;
  
                    /* 0x1910  5  _SmackBufferNewPalette@12 */
  if ((param_1 != 0) && (*(undefined4 *)(param_1 + 0x444) = 1, 0xff < *(uint *)(param_1 + 0x2c))) {
    if (*(int *)(param_1 + 0x34) != 0) {
      uVar6 = 0;
      do {
        uVar7 = uVar6;
        if (uVar6 == *(uint *)(param_1 + 0x34)) {
          uVar7 = *(uint *)(param_1 + 0x38);
        }
        uVar6 = uVar7 + 1;
        local_420[0].palPalEntry[uVar7].peRed = *(BYTE *)(param_1 + 0x3a + uVar6 * 4);
        local_420[0].palPalEntry[uVar7].peGreen = *(BYTE *)(param_1 + 0x39 + uVar6 * 4);
        local_420[0].palPalEntry[uVar7].peBlue = *(BYTE *)(param_1 + 0x38 + uVar6 * 4);
        local_420[0].palPalEntry[uVar7].peFlags = '\0';
      } while (uVar6 < 0x100);
    }
    local_18 = *(uint *)(param_1 + 0x34);
    if (local_18 < *(uint *)(param_1 + 0x38)) {
      local_1c = local_18 * 4 + param_1;
      pbVar8 = (byte *)(*(int *)(param_1 + 0x34) * (((param_3 & 1) != 0) + 3) + param_2);
      do {
        iVar2 = local_1c;
        pbVar9 = pbVar8 + 3;
        if ((param_3 & 4) == 0) {
          bVar3 = *pbVar8;
          bVar5 = pbVar8[1];
          local_14 = pbVar8[2];
        }
        else {
          local_14 = *pbVar8;
          bVar5 = pbVar8[1];
          bVar3 = pbVar8[2];
        }
        if ((param_3 & 2) == 0) {
          bVar3 = bVar3 << 2;
          local_14 = local_14 << 2;
          bVar5 = bVar5 << 2;
        }
        if ((param_3 & 1) != 0) {
          pbVar9 = pbVar8 + 4;
        }
        if (*(uint *)(param_1 + 0x38) < 0x100) {
          uVar6 = *(uint *)(param_1 + 0x38) * 4 + param_1;
          do {
            if ((bVar3 == *(byte *)(uVar6 + 0x3e)) && (bVar5 == *(byte *)(uVar6 + 0x3d))) {
              if (local_14 == *(byte *)(uVar6 + 0x3c)) {
                if ((bVar3 & 3) == 3) {
                  bVar3 = bVar3 - 1;
                }
                else {
                  bVar3 = bVar3 + 1;
                }
              }
            }
            uVar6 = uVar6 + 4;
          } while (uVar6 < param_1 + 0x400U);
        }
        local_420[0].palPalEntry[local_18].peRed = bVar3;
        *(byte *)(iVar2 + 0x3e) = bVar3;
        local_420[0].palPalEntry[local_18].peGreen = bVar5;
        bVar3 = local_14;
        *(byte *)(iVar2 + 0x3d) = bVar5;
        uVar6 = local_18 + 1;
        local_420[0].palPalEntry[local_18].peBlue = local_14;
        *(byte *)(iVar2 + 0x3c) = bVar3;
        pPVar1 = local_420[0].palPalEntry + local_18;
        local_18 = uVar6;
        pPVar1->peFlags = '\x04';
        local_1c = local_1c + 4;
        pbVar8 = pbVar9;
      } while (uVar6 < *(uint *)(param_1 + 0x38));
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      if (*(HGDIOBJ *)(param_1 + 0x458) != (HGDIOBJ)0x0) {
        DeleteObject(*(HGDIOBJ *)(param_1 + 0x458));
      }
      local_420[0].palVersion = 0x300;
      local_420[0].palNumEntries = *(WORD *)(param_1 + 0x2c);
      pHVar4 = CreatePalette(local_420);
      *(HPALETTE *)(param_1 + 0x458) = pHVar4;
      if (*(int *)(param_1 + 8) == 4) {
        (*DAT_00410454)(*(undefined4 *)(param_1 + 0x45c),0,*(undefined4 *)(param_1 + 0x2c),
                        param_1 + 0x3c);
      }
    }
    else {
      FUN_00402a00();
    }
    if (0x100 < _DAT_0040e808) {
      *(undefined4 *)(param_1 + 0x440) = 1;
    }
  }
  return;
}

