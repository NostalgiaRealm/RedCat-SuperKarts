/*
 * FUN_0047fbb0 at 0047fbb0
 * undefined FUN_0047fbb0(void)
 * Address ranges: 0047fbb0-0047fcd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047fbb0(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  do {
    uVar3 = 0xffffffff;
    pcVar7 = &DAT_004f95c0;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar2 = *(uint *)(param_1 + 0x1c);
    uVar4 = ~uVar3 - 1;
    uVar3 = uVar2;
    if (uVar4 <= uVar2) {
      uVar3 = uVar4;
    }
    bVar9 = false;
    iVar5 = 0;
    bVar10 = true;
    pbVar6 = *(byte **)(param_1 + 0x18);
    pbVar8 = &DAT_004f95c0;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar9 = *pbVar6 < *pbVar8;
      bVar10 = *pbVar6 == *pbVar8;
      pbVar6 = pbVar6 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar10);
    if (!bVar10) {
      iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
    }
    if (((iVar5 == 0) && (uVar4 <= uVar2)) && (uVar2 == uVar4)) {
      return;
    }
    uVar3 = 0xffffffff;
    pcVar7 = &DAT_004f95c4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar2 = *(uint *)(param_1 + 0x1c);
    uVar4 = ~uVar3 - 1;
    uVar3 = uVar2;
    if (uVar4 <= uVar2) {
      uVar3 = uVar4;
    }
    bVar9 = false;
    iVar5 = 0;
    bVar10 = true;
    pbVar6 = *(byte **)(param_1 + 0x18);
    pbVar8 = &DAT_004f95c4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar9 = *pbVar6 < *pbVar8;
      bVar10 = *pbVar6 == *pbVar8;
      pbVar6 = pbVar6 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar10);
    if (!bVar10) {
      iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
    }
    if (((iVar5 == 0) && (uVar4 <= uVar2)) && (uVar2 == uVar4)) {
      return;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      if (*(code **)(param_1 + 0x9c) != (code *)0x0) {
        (**(code **)(param_1 + 0x9c))(param_1 + 4,0);
      }
      FUN_0047f370();
      FUN_0047f3a0();
      FUN_0047f4b0();
      FUN_0047f6f0();
      if (*(int *)(param_1 + 0x6c) != 0) {
        return;
      }
    }
    else {
      FUN_0047fb70();
      if (*(code **)(param_1 + 0x94) != (code *)0x0) {
        (**(code **)(param_1 + 0x94))(param_1 + 4,0);
      }
      FUN_0047f130(param_1 + 0x14);
      if (*(code **)(param_1 + 0x90) != (code *)0x0) {
        (**(code **)(param_1 + 0x90))(param_1 + 4,0);
      }
      FUN_0047f5d0();
      FUN_0047f6f0();
    }
  } while( true );
}

