/*
 * FUN_0041d2ec at 0041d2ec
 * undefined __register FUN_0041d2ec(undefined4 param_1, int * param_2, int param_3)
 * Address ranges: 0041d2ec-0041d63c;0041d670-0041d6cf;0041d6e8-0041d700
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d2ec(undefined4 param_1,int *param_2,int param_3)

{
  WORD WVar1;
  uint uVar2;
  BITMAPINFO *pBVar3;
  DWORD DVar4;
  HDC pHVar5;
  HBITMAP h;
  HGDIOBJ ho;
  undefined4 extraout_ECX;
  undefined2 extraout_var;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uStack_c4;
  undefined1 *puStack_c0;
  undefined1 *puStack_bc;
  undefined4 uStack_b8;
  undefined1 *puStack_b4;
  undefined1 *puStack_b0;
  ushort local_48;
  ushort local_46;
  WORD local_44;
  WORD local_42;
  BITMAPINFO *local_40;
  int *local_3c;
  HPALETTE local_38;
  HPALETTE local_34;
  HGDIOBJ local_30;
  HBITMAP local_2c;
  byte local_25;
  DWORD local_24;
  undefined4 *local_20;
  BITMAPINFO *local_1c;
  void *local_18;
  HDC local_14;
  HDC local_10;
  int *local_c;
  undefined4 local_8;
  
  local_34 = (HPALETTE)0x0;
  local_2c = (HBITMAP)0x0;
  local_3c = (int *)0x0;
  puStack_b0 = (undefined1 *)0x41d31f;
  local_c = param_2;
  local_8 = param_1;
  (**(code **)(*param_2 + 4))(param_2,&local_24,4);
  local_25 = local_24 == 0xc;
  if ((bool)local_25) {
    local_24 = 0x28;
  }
  puStack_b0 = (undefined1 *)0x41d344;
  local_40 = (BITMAPINFO *)FUN_00402714(local_24 + 0x40c);
  puStack_b4 = &LAB_0041d7b3;
  uStack_b8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_b8;
  puStack_c0 = &LAB_0041d786;
  uStack_c4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_c4;
  local_1c = local_40;
  if (local_25 == 0) {
    puStack_bc = &stack0xfffffffc;
    puStack_b0 = &stack0xfffffffc;
    (**(code **)(*local_c + 4))(local_c,&(local_40->bmiHeader).biWidth,local_24 - 4);
    iVar7 = param_3 - local_24;
    DVar4 = (local_40->bmiHeader).biCompression;
    if ((DVar4 != 3) && (DVar4 != 0)) {
      local_3c = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',extraout_ECX);
      (**(code **)(*local_3c + 8))(local_3c,&local_24,4);
      (**(code **)(*local_3c + 8))(local_3c,&(local_1c->bmiHeader).biWidth,local_24 - 4);
      FUN_00411958(local_3c,local_c,iVar7);
      (**(code **)(*local_3c + 0xc))(local_3c,iVar7,CONCAT22(extraout_var,2));
      local_c = local_3c;
    }
  }
  else {
    puStack_bc = &stack0xfffffffc;
    puStack_b0 = &stack0xfffffffc;
    (**(code **)(*local_c + 4))(local_c,&local_48,8);
    pBVar3 = local_40;
    FUN_00402b54((undefined4 *)local_40,0x28,0);
    (pBVar3->bmiHeader).biWidth = (uint)local_48;
    (pBVar3->bmiHeader).biHeight = (uint)local_46;
    (pBVar3->bmiHeader).biPlanes = local_44;
    (pBVar3->bmiHeader).biBitCount = local_42;
    iVar7 = param_3 + -0xc;
  }
  pBVar3 = local_40;
  (local_40->bmiHeader).biSize = local_24;
  local_20 = (undefined4 *)
             ((int)&(((BITMAPINFO *)(local_1c->bmiColors + -10))->bmiHeader).biSize + local_24);
  if ((local_40->bmiHeader).biPlanes != 1) {
    FUN_00418c6c();
  }
  if ((local_24 == 0x28) &&
     (((WVar1 = (pBVar3->bmiHeader).biBitCount, WVar1 == 0x10 || (WVar1 == 0x20)) &&
      ((pBVar3->bmiHeader).biCompression == 3)))) {
    FUN_004118e8(local_c,local_20,0xc);
    local_20 = local_20 + 3;
    iVar7 = iVar7 + -0xc;
  }
  if ((pBVar3->bmiHeader).biClrUsed == 0) {
    DVar4 = FUN_00418efc((pBVar3->bmiHeader).biBitCount);
    (pBVar3->bmiHeader).biClrUsed = DVar4;
  }
  uVar8 = (uint)local_25;
  FUN_004118e8(local_c,local_20,(pBVar3->bmiHeader).biClrUsed * (uint)(byte)(&DAT_0047b5e0)[uVar8]);
  uVar8 = iVar7 - (pBVar3->bmiHeader).biClrUsed * (uint)(byte)(&DAT_0047b5e0)[uVar8];
  if ((pBVar3->bmiHeader).biSizeImage == 0) {
    iVar7 = FUN_00418f1c((pBVar3->bmiHeader).biWidth,(uint)(pBVar3->bmiHeader).biBitCount,0x20);
    uVar2 = (pBVar3->bmiHeader).biHeight;
    uVar6 = (int)uVar2 >> 0x1f;
    (pBVar3->bmiHeader).biSizeImage = iVar7 * ((uVar2 ^ uVar6) - uVar6);
  }
  uVar2 = (pBVar3->bmiHeader).biSizeImage;
  if (uVar2 < uVar8) {
    uVar8 = uVar2;
  }
  if (local_25 != 0) {
    FUN_004191c4((int)local_20);
  }
  pHVar5 = GetDC((HWND)0x0);
  local_10 = (HDC)FUN_00418d8c((int)pHVar5);
  uVar9 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffff30;
  DVar4 = (local_40->bmiHeader).biCompression;
  if (((DVar4 == 0) || (DVar4 == 3)) && (DAT_0047b3a0 == '\0')) {
    local_2c = CreateDIBSection(local_10,local_1c,0,&local_18,(HANDLE)0x0,0);
    if ((local_2c == (HBITMAP)0x0) || (local_18 == (void *)0x0)) {
      DVar4 = GetLastError();
      if (DVar4 == 0) {
        FUN_00418c6c();
      }
      else {
        FUN_0040bd58();
      }
    }
    uVar10 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffff24;
    FUN_004118e8(local_c,local_18,uVar8);
    *in_FS_OFFSET = uVar10;
    *in_FS_OFFSET = uVar9;
    ReleaseDC((HWND)0x0,local_10);
    return;
  }
  local_14 = (HDC)0x0;
  local_18 = (void *)FUN_00402714(uVar8);
  *in_FS_OFFSET = &stack0xffffff24;
  FUN_004118e8(local_c,local_18,uVar8);
  pHVar5 = CreateCompatibleDC(local_10);
  local_14 = (HDC)FUN_00418d8c((int)pHVar5);
  h = CreateCompatibleBitmap(local_10,1,1);
  local_30 = SelectObject(local_14,h);
  local_38 = (HPALETTE)0x0;
  DVar4 = (local_40->bmiHeader).biClrUsed;
  if (DVar4 != 0) {
    local_34 = FUN_0041947c((HGDIOBJ)0x0,local_20,DVar4);
    local_38 = SelectPalette(local_14,local_34,0);
    RealizePalette(local_14);
  }
  uVar9 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffff18;
  local_2c = CreateDIBitmap(local_14,&local_1c->bmiHeader,4,local_18,local_1c,0);
  if (local_2c == (HBITMAP)0x0) {
    DVar4 = GetLastError();
    if (DVar4 == 0) {
      FUN_00418c6c();
    }
    else {
      FUN_0040bd58();
    }
  }
  *in_FS_OFFSET = uVar9;
  if (local_38 != (HPALETTE)0x0) {
    SelectPalette(local_14,local_38,-1);
  }
  ho = SelectObject(local_14,local_30);
  DeleteObject(ho);
  return;
}

