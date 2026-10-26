/*
 * FUN_00418d9c at 00418d9c
 * undefined __register FUN_00418d9c(HANDLE param_1, int * param_2, char param_3)
 * Address ranges: 00418d9c-00418e58;00418e60-00418ee9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418d9c(HANDLE param_1,int *param_2,char param_3)

{
  HGDIOBJ h;
  HGDIOBJ h_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar1;
  undefined4 uStack_50;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  HDC local_20;
  HDC local_1c;
  HDC local_18;
  HBITMAP local_14;
  int local_10;
  int local_c;
  HANDLE local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_1;
  local_1c = CreateCompatibleDC((HDC)0x0);
  local_20 = CreateCompatibleDC((HDC)0x0);
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  GetObjectA(local_8,0x18,local_38);
  if (param_3 != '\0') {
    local_14 = CreateBitmap(local_10,local_c,1,1,(void *)0x0);
    if (local_14 != (HBITMAP)0x0) {
      h = SelectObject(local_1c,local_8);
      h_00 = SelectObject(local_20,local_14);
      StretchBlt(local_20,0,0,local_10,local_c,local_1c,0,0,local_34,local_30,0xcc0020);
      if (h != (HGDIOBJ)0x0) {
        SelectObject(local_1c,h);
      }
      if (h_00 != (HGDIOBJ)0x0) {
        SelectObject(local_20,h_00);
      }
    }
    *in_FS_OFFSET = uStack_50;
    uStack_50 = 0x418ee0;
    DeleteDC(local_1c);
    uStack_50 = 0x418ee9;
    DeleteDC(local_20);
    return;
  }
  local_18 = GetDC((HWND)0x0);
  if (local_18 == (HDC)0x0) {
    FUN_00418ce4();
  }
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffa4;
  local_14 = CreateCompatibleBitmap(local_18,local_10,local_c);
  if (local_14 == (HBITMAP)0x0) {
    FUN_00418ce4();
  }
  *in_FS_OFFSET = uVar1;
  ReleaseDC((HWND)0x0,local_18);
  return;
}

