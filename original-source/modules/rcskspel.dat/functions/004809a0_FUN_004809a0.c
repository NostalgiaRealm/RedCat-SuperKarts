/*
 * FUN_004809a0 at 004809a0
 * undefined FUN_004809a0(void)
 * Address ranges: 004809a0-00480a43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_004809a0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined4 *local_10;
  
  local_10 = *(undefined4 **)(param_1 + 4);
  if ((undefined4 *)local_10[1] != DAT_00544fb0) {
    uVar1 = *(uint *)(param_2 + 8);
    puVar5 = (undefined4 *)local_10[1];
    do {
      pbVar8 = &DAT_004d2404;
      if (*(byte **)(param_2 + 4) != (byte *)0x0) {
        pbVar8 = *(byte **)(param_2 + 4);
      }
      uVar2 = puVar5[5];
      uVar3 = uVar2;
      if (uVar1 <= uVar2) {
        uVar3 = uVar1;
      }
      bVar9 = false;
      uVar4 = 0;
      bVar10 = true;
      pbVar7 = (byte *)puVar5[4];
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        bVar9 = *pbVar7 < *pbVar8;
        bVar10 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (!bVar10) {
        uVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
      if (uVar4 == 0) {
        if (uVar1 <= uVar2) {
          uVar4 = (uint)(uVar2 != uVar1);
          goto LAB_00480a15;
        }
LAB_00480a17:
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
LAB_00480a15:
        if ((int)uVar4 < 0) goto LAB_00480a17;
        puVar6 = (undefined4 *)*puVar5;
        local_10 = puVar5;
      }
      puVar5 = puVar6;
    } while (puVar6 != DAT_00544fb0);
  }
  return local_10;
}

