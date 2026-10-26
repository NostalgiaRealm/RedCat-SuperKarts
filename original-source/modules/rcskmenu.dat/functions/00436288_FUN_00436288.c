/*
 * FUN_00436288 at 00436288
 * undefined __register FUN_00436288(int param_1, HMENU param_2, byte param_3)
 * Address ranges: 00436288-004364e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436288(int param_1,HMENU param_2,byte param_3)

{
  undefined1 *puVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  DWORD DVar6;
  LPCSTR pCVar7;
  UINT_PTR uIDNewItem;
  uint uVar8;
  int *in_FS_OFFSET;
  byte bVar9;
  int iStack_68;
  int iStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  int local_44;
  MENUITEMINFOA local_3d;
  byte local_d;
  undefined *local_c;
  byte local_5;
  
  puStack_54 = &stack0xfffffffc;
  local_44 = 0;
  local_c = (undefined *)0x0;
  puStack_58 = &LAB_004364e3;
  iStack_5c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_5c;
  puVar1 = &stack0xfffffffc;
  local_5 = param_3;
  if (*(char *)(param_1 + 0x32) == '\0') goto LAB_004364c5;
  FUN_00403be8((int *)&local_c,*(int *)(param_1 + 0x24));
  iVar4 = FUN_00438084(param_1);
  if (iVar4 < 1) {
    if (*(short *)(param_1 + 0x54) != 0) {
      iVar4 = *(int *)(param_1 + 0x58);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x58) == 0)) {
        uVar5 = FUN_00403024(*(int **)(iVar4 + 4),(int)&PTR_FUN_00435264);
        if ((char)uVar5 != '\0') goto LAB_00436324;
      }
      FUN_00435978(*(ushort *)(param_1 + 0x54),&local_44);
      iStack_68 = local_44;
      FUN_00403e90((int *)&local_c,3);
    }
  }
  else {
    local_3d.hSubMenu = (HMENU)FUN_00436734(param_1);
  }
LAB_00436324:
  DVar6 = GetVersion();
  uVar3 = (ushort)DVar6 & 0xff;
  bVar9 = uVar3 == 4;
  if (uVar3 < 4) {
    FUN_00403ee0(*(uint **)(param_1 + 0x24),(uint *)&DAT_00436508);
    uVar8 = *(uint *)(&DAT_0047b884 + (bVar9 & 0x7f) * 4) |
            *(uint *)(&DAT_0047b878 + (uint)*(byte *)(param_1 + 0x3c) * 4) |
            *(uint *)(&DAT_0047b868 + (uint)*(byte *)(param_1 + 0x2c) * 4) |
            *(uint *)(&DAT_0047b870 + (uint)*(byte *)(param_1 + 0x2d) * 4);
    iVar4 = FUN_00438084(param_1);
    if (iVar4 < 1) {
      pCVar7 = FUN_00403f94(local_c);
      InsertMenuA(param_2,0xffffffff,uVar8 | 0x400,(uint)*(ushort *)(param_1 + 0x44),pCVar7);
      puVar1 = puStack_54;
    }
    else {
      pCVar7 = FUN_00403f94(*(undefined **)(param_1 + 0x24));
      uIDNewItem = FUN_00436734(param_1);
      InsertMenuA(param_2,0xffffffff,uVar8 | 0x410,uIDNewItem,pCVar7);
      puVar1 = puStack_54;
    }
    goto LAB_004364c5;
  }
  local_3d.cbSize = 0x2c;
  local_3d.fMask = 0x3f;
  iVar4 = thunk_FUN_004385f4(param_1);
  if (iVar4 == 0) {
LAB_00436364:
    if (*(int *)(param_1 + 0x40) != 0) {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))();
      bVar9 = 1;
      if (cVar2 == '\0') goto LAB_0043637a;
    }
    local_d = 0;
    bVar9 = 1;
  }
  else {
    bVar9 = 0;
    if (*(char *)(iVar4 + 0x34) == '\0') {
      iVar4 = FUN_00437c5c(param_1);
      bVar9 = 0;
      if (iVar4 == 0) goto LAB_00436364;
    }
LAB_0043637a:
    local_d = 1;
  }
  FUN_00403ee0(*(uint **)(param_1 + 0x24),(uint *)&DAT_00436508);
  local_3d.fType =
       *(uint *)(&DAT_0047b8b8 + (bVar9 & 0x7f) * 4) |
       *(uint *)(&DAT_0047b8b0 + (uint)*(byte *)(param_1 + 0x31) * 4) |
       *(uint *)(&DAT_0047b88c + (uint)*(byte *)(param_1 + 0x3c) * 4) |
       *(uint *)(&DAT_0047b8c0 + (uint)local_5 * 4) | *(uint *)(&DAT_0047b8c8 + (uint)local_d * 4);
  local_3d.fState =
       *(uint *)(&DAT_0047b898 + (uint)*(byte *)(param_1 + 0x2c) * 4) |
       *(uint *)(&DAT_0047b8a8 + (uint)*(byte *)(param_1 + 0x2d) * 4) |
       *(uint *)(&DAT_0047b8a0 + (uint)*(byte *)(param_1 + 0x2e) * 4);
  local_3d.wID = (UINT)*(ushort *)(param_1 + 0x44);
  local_3d.hSubMenu = (HMENU)0x0;
  local_3d.hbmpChecked = (HBITMAP)0x0;
  local_3d.hbmpUnchecked = (HBITMAP)0x0;
  local_3d.dwTypeData = FUN_00403f94(local_c);
  iVar4 = FUN_00438084(param_1);
  if (0 < iVar4) {
    local_3d.hSubMenu = (HMENU)FUN_00436734(param_1);
  }
  InsertMenuItemA(param_2,0xffffffff,-1,&local_3d);
  puVar1 = puStack_54;
LAB_004364c5:
  puStack_54 = puVar1;
  *in_FS_OFFSET = iStack_68;
  FUN_00403b50(&local_44);
  FUN_00403b50((int *)&local_c);
  return;
}

