/*
 * _SmackSoundOnOff@8 at 004046a0
 * undefined4 __stdcall _SmackSoundOnOff@8(uint param_1, int param_2)
 * Address ranges: 004046a0-004048b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 _SmackSoundOnOff_8(uint param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint local_14;
  
                    /* 0x46a0  17  _SmackSoundOnOff@8 */
  if (param_1 == 0) {
    uVar5 = 0;
  }
  else {
    uVar1 = param_1 + 0x1c;
    if (param_2 == 0) {
      if (*(int *)(param_1 + 0x428) == 0) {
        *(undefined4 *)(param_1 + 0x428) = 1;
        do {
          if (*(int *)(param_1 + 0x404) != 0) {
            if (DAT_0040e850 != (code *)0x0) {
              (*DAT_0040e850)(*(int *)(param_1 + 0x404));
            }
            puVar10 = *(undefined4 **)(param_1 + 0x404);
            puVar10[3] = *puVar10;
            puVar10[2] = *puVar10;
            iVar6 = puVar10[4];
            puVar10[4] = 0;
            puVar10[10] = puVar10[10] - iVar6;
          }
          param_1 = param_1 + 4;
        } while (param_1 != uVar1);
      }
    }
    else if (*(int *)(param_1 + 0x428) != 0) {
      local_14 = param_1;
      *(undefined4 *)(param_1 + 0x428) = 0;
      do {
        piVar2 = *(int **)(local_14 + 0x404);
        if (piVar2 != (int *)0x0) {
          if (DAT_0040e854 != (code *)0x0) {
            cVar3 = (*DAT_0040e854)(piVar2);
            if (cVar3 == '\0') {
              return 0;
            }
          }
          iVar6 = (*DAT_00410478)(piVar2);
          piVar2[9] = piVar2[9] - piVar2[8];
          piVar2[8] = iVar6 * 0x80;
          piVar2[9] = piVar2[9] + iVar6 * 0x80;
          if ((*(int *)(param_1 + 0x370) != 0) && ((uint)(piVar2[10] - iVar6) < (uint)piVar2[0xc]))
          {
            uVar7 = piVar2[0xc] - (piVar2[10] - iVar6);
            if ((uint)piVar2[6] < piVar2[4] + uVar7) {
              uVar7 = piVar2[6] - piVar2[4];
            }
            uVar9 = uVar7 & 0xfffffffc;
            if (piVar2[0x12] == 0) {
              uVar4 = 0x80;
            }
            else {
              uVar4 = 0;
            }
            puVar10 = (undefined4 *)piVar2[3];
            if ((undefined1 *)((int)puVar10 + uVar9) < (undefined1 *)piVar2[1]) {
              for (uVar7 = uVar7 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar10 = CONCAT22(CONCAT11(uVar4,uVar4),CONCAT11(uVar4,uVar4));
                puVar10 = puVar10 + 1;
              }
              for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                *(undefined1 *)puVar10 = uVar4;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              piVar2[3] = piVar2[3] + uVar9;
            }
            else {
              uVar8 = piVar2[1] - (int)puVar10;
              for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar10 = CONCAT22(CONCAT11(uVar4,uVar4),CONCAT11(uVar4,uVar4));
                puVar10 = puVar10 + 1;
              }
              for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar10 = uVar4;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              uVar8 = uVar9 - (piVar2[1] - piVar2[3]);
              puVar10 = (undefined4 *)*piVar2;
              for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar10 = CONCAT22(CONCAT11(uVar4,uVar4),CONCAT11(uVar4,uVar4));
                puVar10 = puVar10 + 1;
              }
              for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar10 = uVar4;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              piVar2[3] = (*piVar2 + uVar9) - (piVar2[3] - piVar2[1]);
            }
            piVar2[4] = piVar2[4] + uVar9;
            piVar2[10] = piVar2[10] + uVar9;
          }
        }
        local_14 = local_14 + 4;
      } while (local_14 < uVar1);
      return 1;
    }
    uVar5 = 1;
  }
  return uVar5;
}

