/*
 * FUN_00407400 at 00407400
 * undefined FUN_00407400(void)
 * Address ranges: 00407400-00407512
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407400(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  uint uVar6;
  uint uVar7;
  LPWAVEHDR pwh;
  
  for (puVar2 = DAT_0040e894; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[0xd]) {
    if ((3 < (uint)puVar2[4]) &&
       ((pwh = (LPWAVEHDR)puVar2[0x15], (pwh->dwFlags & 1) != 0 ||
        (pwh = (LPWAVEHDR)puVar2[0x16], (pwh->dwFlags & 1) != 0)))) {
      uVar7 = puVar2[4];
      if ((uint)puVar2[0xf] < (uint)puVar2[4]) {
        uVar7 = puVar2[0xf];
      }
      puVar4 = FUN_00402c70(uVar7,puVar2[1],(undefined4 *)*puVar2,(undefined4 *)puVar2[2],
                            &pwh[1].lpData);
      puVar2[2] = puVar4;
      puVar2[4] = puVar2[4] - uVar7;
      pwh->dwBufferLength = uVar7;
      *(byte *)&pwh->dwFlags = (byte)pwh->dwFlags & 0xfe;
      iVar1 = puVar2[0xf];
      if (puVar2[0x12] == 0) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = 0;
      }
      puVar4 = (undefined4 *)((int)&pwh[1].lpData + uVar7);
      for (uVar6 = iVar1 - uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar4 = CONCAT22(CONCAT11(uVar3,uVar3),CONCAT11(uVar3,uVar3));
        puVar4 = puVar4 + 1;
      }
      for (uVar6 = iVar1 - uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar4 = uVar3;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      waveOutWrite((HWAVEOUT)puVar2[0xe],pwh,0x20);
      if (puVar2[0x17] == 0) {
        DVar5 = timeGetTime();
        puVar2[0x17] = DVar5;
        puVar2[0x19] = uVar7;
      }
      else {
        DVar5 = timeGetTime();
        if ((uint)(puVar2[0x17] + puVar2[0x18]) < DVar5) {
          puVar2[0x17] = DVar5;
          iVar1 = puVar2[0x19];
          puVar2[0x19] = uVar7;
          puVar2[0x14] = puVar2[0x14] + iVar1;
        }
        else {
          puVar2[0x19] = puVar2[0x19] + uVar7;
        }
      }
      puVar2[0x18] = (int)(((ulonglong)(uint)puVar2[0x19] * 1000) / (ulonglong)(uint)puVar2[5]);
    }
  }
  return;
}

