/*
 * FUN_0049e2f0 at 0049e2f0
 * undefined FUN_0049e2f0(void)
 * Address ranges: 0049e2f0-0049e362
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0049e2f0(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x220)) {
    puVar4 = (undefined4 *)(param_1 + 0x24);
    do {
      pbVar5 = (byte *)*puVar4;
      pbVar2 = param_2;
      if (pbVar5 == (byte *)0x0) {
        pbVar5 = &DAT_004d2404;
      }
      do {
        bVar1 = *pbVar2;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_0049e339:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0049e33e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_0049e339;
        pbVar5 = pbVar5 + 2;
        pbVar2 = pbVar2 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0049e33e:
      if (iVar3 == 0) {
        return 1 << ((byte)iVar6 & 0x1f);
      }
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar6 < *(int *)(param_1 + 0x220));
  }
  return 0;
}

