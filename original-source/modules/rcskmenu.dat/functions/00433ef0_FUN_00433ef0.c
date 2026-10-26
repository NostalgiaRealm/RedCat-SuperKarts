/*
 * FUN_00433ef0 at 00433ef0
 * undefined __register FUN_00433ef0(int * param_1, HIMAGELIST param_2)
 * Address ranges: 00433ef0-0043403d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433ef0(int *param_1,HIMAGELIST param_2)

{
  int iVar1;
  int *piVar2;
  HDC pHVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int i;
  undefined4 *in_FS_OFFSET;
  int iVar4;
  int iVar5;
  UINT UVar6;
  undefined4 uStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  RECT local_24;
  int *local_14;
  int *local_10;
  HIMAGELIST local_c;
  int *local_8;
  
  uStack_3c = 0x433f19;
  local_c = param_2;
  local_8 = param_1;
  FUN_0040ebe8(0,0,param_1[10],&local_24.left,param_1[9]);
  FUN_00434960((int)local_8);
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_40 = (undefined1 *)0x433f3b;
  local_10 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
  puStack_44 = &LAB_0043405b;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  puStack_4c = (undefined1 *)0x433f5a;
  puStack_40 = &stack0xfffffffc;
  (**(code **)(*local_10 + 0x34))(local_10,local_8[9]);
  puStack_4c = (undefined1 *)0x433f68;
  (**(code **)(*local_10 + 0x40))(local_10,local_8[10]);
  puStack_4c = (undefined1 *)0x433f74;
  local_14 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_00);
  puStack_50 = &LAB_0043403e;
  uStack_54 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_54;
  puStack_4c = &stack0xfffffffc;
  FUN_0041dabc(local_14,1);
  (**(code **)(*local_14 + 0x34))(local_14,local_8[9]);
  (**(code **)(*local_14 + 0x40))(local_14,local_8[10]);
  iVar1 = ImageList_GetImageCount(local_c);
  if (-1 < iVar1 + -1) {
    i = 0;
    do {
      piVar2 = (int *)FUN_0041cd5c(local_10);
      FUN_00418538(piVar2,&local_24);
      UVar6 = 0;
      iVar5 = 0;
      iVar4 = 0;
      pHVar3 = (HDC)FUN_00418994(piVar2);
      ImageList_Draw(local_c,i,pHVar3,iVar4,iVar5,UVar6);
      piVar2 = (int *)FUN_0041cd5c(local_14);
      FUN_00418538(piVar2,&local_24);
      UVar6 = 0x10;
      iVar5 = 0;
      iVar4 = 0;
      pHVar3 = (HDC)FUN_00418994(piVar2);
      ImageList_Draw(local_c,i,pHVar3,iVar4,iVar5,UVar6);
      FUN_00433ae4(local_8,local_10,local_14);
      i = i + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *in_FS_OFFSET = uStack_54;
  puStack_4c = &LAB_00434045;
  puStack_50 = (undefined1 *)0x43403d;
  FUN_00402eac(local_14);
  return;
}

