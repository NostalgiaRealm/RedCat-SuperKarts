/*
 * FUN_0041b148 at 0041b148
 * undefined __register FUN_0041b148(int param_1, int * param_2)
 * Address ranges: 0041b148-0041b207
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b148(int param_1,int *param_2)

{
  int iVar1;
  HENHMETAFILE pHVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_84;
  undefined1 *puStack_80;
  undefined1 *puStack_7c;
  undefined4 local_6c [6];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  UINT local_3c;
  BYTE *local_8;
  
  puStack_7c = (undefined1 *)0x41b15c;
  FUN_0041b0b4(param_1);
  puStack_7c = (undefined1 *)0x41b16b;
  FUN_004118e8(param_2,local_6c,100);
  if (local_44 != 0x464d4520) {
    puStack_7c = (undefined1 *)0x41b179;
    FUN_00418c84();
  }
  puStack_7c = (undefined1 *)0x41b181;
  local_8 = (BYTE *)FUN_00402714(local_3c);
  iVar1 = *(int *)(param_1 + 0x20);
  puStack_80 = &LAB_0041b208;
  uStack_84 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_84;
  puStack_7c = &stack0xfffffffc;
  FUN_0040282c(local_6c,(undefined4 *)local_8,100);
  FUN_004118e8(param_2,local_8 + 100,local_3c - 100);
  pHVar2 = SetEnhMetaFileBits(local_3c,local_8);
  *(HENHMETAFILE *)(iVar1 + 8) = pHVar2;
  if (pHVar2 == (HENHMETAFILE)0x0) {
    FUN_00418c84();
  }
  *(undefined2 *)(iVar1 + 0x18) = 0;
  *(int *)(iVar1 + 0xc) = local_4c - local_54;
  *(int *)(iVar1 + 0x10) = local_48 - local_50;
  *(undefined1 *)(param_1 + 0x24) = 1;
  *in_FS_OFFSET = uStack_84;
  puStack_7c = &LAB_0041b20f;
  puStack_80 = (undefined1 *)0x41b207;
  FUN_0040272c((int)local_8);
  return;
}

