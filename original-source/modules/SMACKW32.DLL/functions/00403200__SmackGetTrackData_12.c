/*
 * _SmackGetTrackData@12 at 00403200
 * uint __stdcall _SmackGetTrackData@12(int param_1, uint * param_2, uint param_3)
 * Address ranges: 00403200-00403317
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint _SmackGetTrackData_12(int param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  
                    /* 0x3200  26  _SmackGetTrackData@12 */
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x2000;
    bVar4 = 0;
    do {
      if ((uVar2 & param_3) != 0) goto LAB_0040323d;
      bVar4 = bVar4 + 1;
      uVar2 = uVar2 * 2;
    } while (bVar4 < 7);
    bVar4 = 0xff;
LAB_0040323d:
    if (6 < bVar4) {
      return 0;
    }
    iVar3 = (uint)bVar4 * 4 + param_1;
    puVar1 = *(uint **)(iVar3 + 0x3c4);
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    if ((*(uint *)(iVar3 + 0x48) >> 0x18 & 0x80) != 0) {
      if ((puVar1[1] != 0) && (puVar1[1] != 0xffffffff)) {
        if (DAT_0040e840 == (uint *)0x0) {
          uVar5 = *(int *)(param_1 + 0x45c) + 0x2000;
          uVar2 = *(uint *)(param_1 + 0x49c);
          *(uint *)(param_1 + 0x45c) = uVar5;
          if (uVar2 < uVar5) {
            *(uint *)(param_1 + 0x49c) = uVar5;
          }
          DAT_0040e840 = (uint *)FUN_00402c30(param_1,uVar2,0x2000);
          if (DAT_0040e840 == (uint *)0x0) {
            return 0;
          }
        }
        FUN_0040ccf0(puVar1 + 2,puVar1[1],DAT_0040e840,param_2,param_2 + 0x400000,param_2);
      }
      return puVar1[1];
    }
    uVar2 = *puVar1 - 4;
    if ((uVar2 != 0) && (uVar2 != 0xffffffff)) {
      puVar6 = puVar1;
      for (uVar5 = uVar2 >> 2; puVar6 = puVar6 + 1, uVar5 != 0; uVar5 = uVar5 - 1) {
        *param_2 = *puVar6;
        param_2 = param_2 + 1;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(char *)param_2 = (char)*puVar6;
        puVar6 = (uint *)((int)puVar6 + 1);
        param_2 = (uint *)((int)param_2 + 1);
      }
    }
    uVar2 = *puVar1 - 4;
  }
  return uVar2;
}

