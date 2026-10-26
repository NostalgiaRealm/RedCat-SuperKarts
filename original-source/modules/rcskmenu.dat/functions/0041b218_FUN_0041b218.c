/*
 * FUN_0041b218 at 0041b218
 * undefined __register FUN_0041b218(int param_1, int * param_2, int param_3)
 * Address ranges: 0041b218-0041b386
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b218(int param_1,int *param_2,int param_3)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  HENHMETAFILE pHVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_b4;
  undefined1 *puStack_b0;
  undefined1 *puStack_ac;
  undefined1 local_9a [104];
  LONG local_32;
  LONG local_2e;
  undefined4 local_2a;
  int local_26;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  ushort local_18;
  ushort local_12;
  BYTE *local_10;
  UINT local_c;
  int *local_8;
  
  puStack_ac = (undefined1 *)0x41b233;
  local_c = param_3;
  local_8 = param_2;
  FUN_0041b0b4(param_1);
  puStack_ac = (undefined1 *)0x41b243;
  (**(code **)(*local_8 + 4))(local_8,&local_26,0x16);
  if (local_26 == -0x65393229) {
    puStack_ac = (undefined1 *)0x41b254;
    uVar2 = FUN_00419ad4((ushort *)&local_26);
    if (uVar2 == local_12) goto LAB_0041b25f;
  }
  puStack_ac = (undefined1 *)0x41b25f;
  FUN_00418c84();
LAB_0041b25f:
  local_c = local_c - 0x16;
  puStack_ac = (undefined1 *)0x41b26b;
  local_10 = (BYTE *)FUN_00402714(local_c);
  iVar1 = *(int *)(param_1 + 0x20);
  puStack_b0 = &LAB_0041b387;
  uStack_b4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_b4;
  puStack_ac = &stack0xfffffffc;
  (**(code **)(*local_8 + 4))(local_8,local_10,local_c);
  *(ushort *)(*(int *)(param_1 + 0x20) + 0x18) = local_18;
  if (local_18 == 0) {
    local_18 = 0x60;
  }
  iVar3 = MulDiv((int)local_1c - (int)local_20,0x9ec,(uint)local_18);
  *(int *)(iVar1 + 0xc) = iVar3;
  iVar3 = MulDiv((int)local_1a - (int)local_1e,0x9ec,(uint)local_18);
  *(int *)(iVar1 + 0x10) = iVar3;
  local_9a._100_4_ = 8;
  local_32 = 0;
  local_2e = 0;
  local_2a = 0;
  pHVar4 = SetWinMetaFileBits(local_c,local_10,(HDC)0x0,(METAFILEPICT *)(local_9a + 100));
  *(HENHMETAFILE *)(iVar1 + 8) = pHVar4;
  if (pHVar4 == (HENHMETAFILE)0x0) {
    FUN_00418c84();
  }
  GetEnhMetaFileHeader(*(HENHMETAFILE *)(iVar1 + 8),100,(LPENHMETAHEADER)local_9a);
  local_9a._100_4_ = 8;
  local_32 = local_9a._32_4_;
  local_2e = local_9a._36_4_;
  local_2a = 0;
  DeleteEnhMetaFile(*(HENHMETAFILE *)(iVar1 + 8));
  pHVar4 = SetWinMetaFileBits(local_c,local_10,(HDC)0x0,(METAFILEPICT *)(local_9a + 100));
  *(HENHMETAFILE *)(iVar1 + 8) = pHVar4;
  if (pHVar4 == (HENHMETAFILE)0x0) {
    FUN_00418c84();
  }
  *(undefined1 *)(param_1 + 0x24) = 0;
  *in_FS_OFFSET = uStack_b4;
  puStack_ac = &LAB_0041b38e;
  puStack_b0 = (undefined1 *)0x41b386;
  FUN_0040272c((int)local_10);
  return;
}

