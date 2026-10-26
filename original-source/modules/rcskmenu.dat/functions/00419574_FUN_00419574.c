/*
 * FUN_00419574 at 00419574
 * undefined __register FUN_00419574(BITMAPINFOHEADER * param_1, undefined4 * param_2, undefined4 param_3, int * param_4)
 * Address ranges: 00419574-00419645
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419574(BITMAPINFOHEADER *param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  HDC hdc;
  HBITMAP pHVar2;
  HANDLE ho;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  
  param_1->biHeight = (uint)param_1->biHeight >> 1;
  iVar1 = FUN_00418f1c(param_1->biWidth,(uint)param_1->biBitCount,0x20);
  param_1->biSizeImage = iVar1 * param_1->biHeight;
  iVar1 = FUN_00418efc(param_1->biBitCount);
  puStack_2c = (undefined1 *)0x4195c3;
  hdc = GetDC((HWND)0x0);
  if (hdc == (HDC)0x0) {
    FUN_00418c90();
  }
  puStack_2c = &LAB_00419720;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  pHVar2 = CreateDIBitmap(hdc,param_1,4,&param_1[1].biSize + iVar1,(BITMAPINFO *)param_1,0);
  ho = (HANDLE)FUN_00418d8c((int)pHVar2);
  uVar4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffc4;
  uVar3 = FUN_00418d9c(ho,param_4,'\0');
  *param_2 = uVar3;
  *in_FS_OFFSET = uVar4;
  DeleteObject(ho);
  return;
}

