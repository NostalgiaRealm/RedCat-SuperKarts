/*
 * _SmackToScreen@24 at 00403900
 * undefined __stdcall _SmackToScreen@24(int param_1, uint param_2, int param_3, int param_4, int param_5, int param_6)
 * Address ranges: 00403900-00403e59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackToScreen_24(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  short sVar17;
  undefined4 *local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  int local_2c;
  int local_28;
  short local_24;
  int local_20;
  short local_1c;
  uint local_18;
  undefined4 *local_14;
  
                    /* 0x3900  22  _SmackToScreen@24 */
  local_44 = (undefined4 *)0x0;
  if (param_1 != 0) {
    if (param_4 == 0x140) {
      param_6 = 0;
      param_5 = 0xa0000;
    }
    pcVar2 = *(char **)(param_1 + 0x3a0);
    if (pcVar2 != (char *)0x0) {
      if (*pcVar2 == '\x01') {
        local_2c = *(int *)(pcVar2 + 0x18);
        local_44 = *(undefined4 **)(pcVar2 + 4);
      }
      FUN_00402c10();
      *(int *)(param_1 + 0x45c) = *(int *)(param_1 + 0x45c) - *(int *)(param_1 + 0x3a4);
    }
    local_20 = param_4;
    local_18 = 4;
    local_38 = 0;
    local_24 = 3;
    iVar1 = param_4 * 2;
    uVar12 = *(uint *)(param_1 + 8) >> 1;
    uVar13 = uVar12;
    iVar14 = iVar1;
    iVar6 = iVar1;
    if (((*(byte *)(param_1 + 0x386) & 0x10) == 0) &&
       (uVar13 = *(uint *)(param_1 + 8), iVar14 = param_4, iVar6 = local_20,
       (*(byte *)(param_1 + 0x386) & 0x20) != 0)) {
      local_38 = param_4;
      local_18 = 8;
      local_24 = 7;
      uVar13 = uVar12;
      iVar14 = iVar1;
    }
    local_20 = iVar6;
    iVar1 = *(int *)(param_1 + 4);
    iVar6 = *(int *)(param_1 + 4) * local_18 * (param_3 * param_4 + iVar14 * uVar13 >> 0x10) + 0x400
    ;
    *(int *)(param_1 + 0x3a4) = iVar6;
    uVar12 = *(int *)(param_1 + 0x45c) + iVar6;
    *(uint *)(param_1 + 0x45c) = uVar12;
    if (*(uint *)(param_1 + 0x49c) < uVar12) {
      *(uint *)(param_1 + 0x49c) = uVar12;
    }
    iVar6 = FUN_00402c30(uVar12,iVar6,iVar6);
    *(int *)(param_1 + 0x3a0) = iVar6;
    if (iVar6 != 0) {
      param_2 = param_2 & 0xfffffffc;
      *(int *)(param_1 + 0x38c) = param_3;
      *(uint *)(param_1 + 0x388) = param_2;
      local_14 = (undefined4 *)(*(int *)(param_1 + 0x3a0) + 0x400);
      puVar3 = *(undefined1 **)(param_1 + 0x3a0);
      *puVar3 = 0;
      puVar3[1] = (*(byte *)(param_1 + 0x386) & 0x20) != 0;
      local_3c = param_2 + param_4 * param_3;
      local_40 = local_3c >> 0x10;
      *(int *)(puVar3 + 4) = param_6;
      sVar4 = (short)local_20;
      *(short *)(puVar3 + 8) = sVar4 - *(short *)(param_1 + 4);
      if (param_6 == 0) {
        uVar11 = 0xfffe;
      }
      else {
        iVar6 = local_40 * 2;
        local_40 = local_40 + 1;
        uVar11 = *(undefined2 *)(iVar6 + param_5);
      }
      *(undefined2 *)(puVar3 + 10) = uVar11;
      sVar17 = (short)local_18;
      piVar7 = (int *)FUN_00403e60(local_24,sVar4,sVar17);
      piVar9 = piVar7 + 1;
      if (param_6 == 0) {
        *piVar7 = param_5 + local_3c;
        *(short *)piVar9 = (short)(uVar13 >> 2);
        *(undefined2 *)((int)piVar7 + 6) = 0xffff;
      }
      else {
        local_3c = local_3c & 0xffff;
        *piVar7 = local_3c + 0xa0000;
        local_1c = 0;
        local_28 = *(int *)(param_1 + 4) * uVar13;
        if (local_28 != 0) {
          local_1c = 0;
          do {
            if (local_3c < 0x10001) {
              if (local_3c + local_38 + iVar14 * 3 + iVar1 < 0x10001) {
                if (local_44 != (undefined4 *)0x0) {
                  local_44 = local_44 + local_2c;
                }
                local_1c = local_1c + 1;
                local_3c = local_3c + iVar14 * 4;
              }
              else {
                *(short *)piVar9 = local_1c;
                *(short *)((int)piVar9 + 2) = -2;
                local_1c = 0;
                puVar8 = (undefined4 *)
                         FUN_00403e60(local_24,(short)*(undefined4 *)(param_1 + 4),sVar17);
                *puVar8 = local_14;
                *(undefined2 *)(puVar8 + 1) = 1;
                *(undefined2 *)((int)puVar8 + 6) = 0xfffd;
                puVar8[2] = local_14;
                if (local_44 == (undefined4 *)0x0) {
                  local_14 = (undefined4 *)((int)local_14 + *(int *)(param_1 + 4) * local_18);
                }
                else {
                  uVar13 = 0;
                  if (local_18 != 0) {
                    do {
                      uVar12 = *(uint *)(param_1 + 4);
                      puVar15 = local_44;
                      puVar16 = local_14;
                      for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                        *puVar16 = *puVar15;
                        puVar15 = puVar15 + 1;
                        puVar16 = puVar16 + 1;
                      }
                      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
                        *(undefined1 *)puVar16 = *(undefined1 *)puVar15;
                        puVar15 = (undefined4 *)((int)puVar15 + 1);
                        puVar16 = (undefined4 *)((int)puVar16 + 1);
                      }
                      uVar13 = uVar13 + 1;
                      local_14 = (undefined4 *)((int)local_14 + *(int *)(param_1 + 4));
                      local_44 = (undefined4 *)((int)local_44 + local_2c);
                    } while (uVar13 < local_18);
                  }
                }
                uVar13 = 0;
                puVar8[3] = local_3c + 0xa0000;
                while (local_3c + local_20 < 0x10001) {
                  uVar13 = uVar13 + 1;
                  local_3c = local_3c + local_20;
                }
                sVar5 = (short)uVar13;
                *(short *)(puVar8 + 4) = sVar5;
                if (local_3c < 0x10001) {
                  uVar12 = 0x10000 - local_3c;
                  if (*(uint *)(param_1 + 4) < 0x10000 - local_3c) {
                    uVar12 = *(uint *)(param_1 + 4);
                  }
                  *(undefined2 *)((int)puVar8 + 0x12) = (short)(uVar12 >> 2);
                  *(undefined2 *)(puVar8 + 5) = *(undefined2 *)(local_40 * 2 + param_5);
                  *(short *)((int)puVar8 + 0x16) = (short)(*(int *)(param_1 + 4) - uVar12 >> 2);
                  sVar5 = (sVar17 - sVar5) + -1;
                }
                else {
                  *(undefined2 *)((int)puVar8 + 0x12) = 0;
                  *(undefined2 *)(puVar8 + 5) = *(undefined2 *)(local_40 * 2 + param_5);
                  *(undefined2 *)((int)puVar8 + 0x16) = 0;
                  sVar5 = sVar17 - sVar5;
                }
                local_40 = local_40 + 1;
                *(short *)(puVar8 + 6) = sVar5;
                local_3c = (local_18 - (uVar13 & 0xffff)) * local_20 + local_3c & 0xffff;
                piVar9 = (int *)FUN_00403e60(local_24,sVar4,sVar17);
              }
              local_28 = local_28 + *(int *)(param_1 + 4) * -4;
            }
            else {
              *(short *)piVar9 = local_1c;
              local_1c = 0;
              *(short *)((int)piVar9 + 2) = *(short *)(local_40 * 2 + param_5);
              piVar7 = (int *)FUN_00403e60(local_24,sVar4,sVar17);
              local_3c = local_3c & 0xffff;
              piVar9 = piVar7 + 1;
              *piVar7 = local_3c + 0xa0000;
              local_40 = local_40 + 1;
            }
          } while (local_28 != 0);
        }
        *(short *)piVar9 = local_1c;
        *(short *)((int)piVar9 + 2) = -1;
      }
    }
  }
  return;
}

