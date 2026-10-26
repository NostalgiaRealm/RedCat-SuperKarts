/*
 * FUN_00479960 at 00479960
 * undefined FUN_00479960(void)
 * Address ranges: 00479960-004799e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00479960(int param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != *(int *)(param_1 + 8)) {
    uVar1 = *(uint *)(param_2 + 8);
    param_2 = *(byte **)(param_2 + 4);
    do {
      pbVar7 = &DAT_004d2404;
      if (param_2 != (byte *)0x0) {
        pbVar7 = param_2;
      }
      uVar2 = *(uint *)(iVar5 + 8);
      uVar4 = uVar2;
      if (uVar1 <= uVar2) {
        uVar4 = uVar1;
      }
      bVar8 = false;
      iVar3 = 0;
      bVar9 = true;
      pbVar6 = *(byte **)(iVar5 + 4);
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (((iVar3 == 0) && (uVar1 <= uVar2)) && (uVar2 == uVar1)) {
        return *(undefined4 *)(iVar5 + 0x10);
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(param_1 + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&param_2,&DAT_004d9d80);
}

