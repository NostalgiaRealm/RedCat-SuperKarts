/*
 * FUN_00407490 at 00407490
 * undefined FUN_00407490(void)
 * Address ranges: 00407490-00407576
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407490(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  iVar3 = 0;
  if (0 < DAT_00508610) {
    iVar2 = 0;
    puVar4 = &DAT_00503f10;
    do {
      FUN_00401000();
      FUN_004023a0(0,iVar3);
      FUN_004094e0(iVar3);
      *(undefined4 *)(DAT_00504f98 + 0x60 + iVar2) = 0;
      iVar5 = iVar3;
      FUN_0040fb40(iVar3);
      uVar1 = FUN_0040fba0(iVar5);
      *(undefined4 *)(puVar4 + 0x4c) = uVar1;
      FUN_004afce0(s_InitNewRacerAI_index__d_004de8b0,iVar3);
      FUN_004057f0(*(undefined4 *)(puVar4 + -0x20),&local_8,local_4);
      FUN_00406470(iVar3,local_8);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x6c;
      puVar4 = puVar4 + 0x11c;
    } while (iVar3 < DAT_00508610);
  }
  if (DAT_00508610 < 0xf) {
    puVar4 = &DAT_00503f24 + DAT_00508610 * 0x11c;
    iVar3 = DAT_00508610;
    do {
      *(undefined4 *)(puVar4 + -0x34) = 0xffffffff;
      FUN_00401000();
      FUN_004094e0(iVar3);
      puVar4 = puVar4 + 0x11c;
      iVar3 = iVar3 + 1;
    } while ((int)puVar4 < 0x504fc8);
  }
  FUN_00407150();
  FUN_00407310();
  FUN_00411220();
  return;
}

