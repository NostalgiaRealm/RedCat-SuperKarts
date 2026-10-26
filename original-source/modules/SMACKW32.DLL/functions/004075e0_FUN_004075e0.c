/*
 * FUN_004075e0 at 004075e0
 * ulonglong __fastcall FUN_004075e0(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004075e0-00407791
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

ulonglong __fastcall FUN_004075e0(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined1 uVar2;
  int in_EAX;
  MMRESULT MVar3;
  DWORD DVar4;
  DWORD DVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  WORD local_28;
  ushort local_26;
  DWORD local_24;
  DWORD local_20;
  WORD local_1c;
  ushort local_1a;
  
  local_28 = 1;
  local_26 = (ushort)(byte)(*(char *)(in_EAX + 0x4c) + 1);
  if (*(int *)(in_EAX + 0x48) == 0) {
    local_1a = 8;
  }
  else {
    local_1a = 0x10;
  }
  local_24 = *(DWORD *)(in_EAX + 0x40);
  local_20 = local_24 * ((int)(uint)local_1a >> 3) * (uint)local_26;
  local_1c = local_26 * (short)((int)(uint)local_1a >> 3);
  MVar3 = waveOutOpen((LPHWAVEOUT)(in_EAX + 0x38),0xffffffff,(LPCWAVEFORMATEX)&local_28,0,
                      *(DWORD_PTR *)(in_EAX + 0x68),0);
  if (MVar3 == 0) {
    puVar10 = *(undefined4 **)(in_EAX + 0x54);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar10 = *(undefined4 **)(in_EAX + 0x58);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    **(int **)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 0x20;
    **(int **)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) + 0x20;
    uVar6 = *(undefined4 *)(in_EAX + 0x3c);
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = uVar6;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 4) = uVar6;
    waveOutPrepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x54),0x20);
    waveOutPrepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x58),0x20);
    pbVar1 = (byte *)(*(int *)(in_EAX + 0x58) + 0x10);
    *pbVar1 = *pbVar1 | 1;
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = 4;
    uVar9 = *(uint *)(in_EAX + 0x3c);
    if (*(int *)(in_EAX + 0x48) == 0) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = 0;
    }
    puVar10 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x20);
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar10 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
      puVar10 = puVar10 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar10 = uVar2;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    waveOutWrite(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x54),0x20);
    DVar4 = timeGetTime();
    do {
      DVar5 = timeGetTime();
      if (DVar4 + 1000 <= DVar5) {
        pbVar1 = (byte *)(*(int *)(in_EAX + 0x54) + 0x10);
        *pbVar1 = *pbVar1 | 1;
        uVar6 = FUN_004077a0();
        return CONCAT44(param_2,uVar6) & 0xffffffffffffff00;
      }
    } while ((*(byte *)(*(int *)(in_EAX + 0x54) + 0x10) & 1) == 0);
    uVar9 = CONCAT31((int3)((uint)*(int *)(in_EAX + 0x54) >> 8),1);
  }
  else {
    uVar9 = MVar3 & 0xffffff00;
  }
  return CONCAT44(param_2,uVar9);
}

