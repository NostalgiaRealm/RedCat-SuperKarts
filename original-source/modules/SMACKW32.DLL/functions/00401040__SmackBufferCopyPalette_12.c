/*
 * _SmackBufferCopyPalette@12 at 00401040
 * undefined __stdcall _SmackBufferCopyPalette@12(uint param_1, int param_2, short param_3)
 * Address ranges: 00401040-0040113b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackBufferCopyPalette_12(uint param_1,int param_2,short param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  UINT UVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  
                    /* 0x1040  13  _SmackBufferCopyPalette@12 */
  if ((param_1 != 0) && (param_2 != 0)) {
    if (param_3 != 0) {
      pbVar7 = *(byte **)(param_1 + 0x448);
      if (*(int *)(param_2 + 0x458) == 0) {
        FUN_00402940();
      }
      uVar6 = param_1;
      puVar9 = (undefined1 *)(param_1 + 0x3c);
      do {
        puVar1 = (undefined1 *)(uVar6 + 0x3d);
        puVar2 = (undefined1 *)(uVar6 + 0x3e);
        puVar3 = (undefined1 *)(uVar6 + 0x3c);
        uVar6 = uVar6 + 4;
        UVar4 = GetNearestPaletteIndex
                          (*(HPALETTE *)(param_2 + 0x458),
                           (uint)CONCAT12(*puVar3,CONCAT11(*puVar1,*puVar2)));
        *puVar9 = (char)UVar4;
        puVar9 = puVar9 + 1;
      } while (uVar6 != param_1 + 0x400);
      uVar6 = uVar6 ^ param_1 + 0x400;
      if (*(int *)(param_1 + 0x14) != 0) {
        do {
          uVar6 = uVar6 + 1;
          FUN_0040661d(pbVar7,*(int *)(param_1 + 0x10),(int)(param_1 + 0x3c));
          pbVar7 = pbVar7 + *(int *)(param_1 + 0x18);
        } while (uVar6 < *(uint *)(param_1 + 0x14));
      }
    }
    puVar8 = (undefined4 *)(param_2 + 0x3c);
    puVar10 = (undefined4 *)(param_1 + 0x3c);
    for (iVar5 = 0x100; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    if (*(HGDIOBJ *)(param_1 + 0x458) != (HGDIOBJ)0x0) {
      DeleteObject(*(HGDIOBJ *)(param_1 + 0x458));
      *(undefined4 *)(param_1 + 0x458) = 0;
    }
  }
  return;
}

