/*
 * FUN_00446bd4 at 00446bd4
 * undefined __register FUN_00446bd4(int * param_1, int * param_2, uint * param_3)
 * Address ranges: 00446bd4-00446ce0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446bd4(int *param_1,int *param_2,uint *param_3)

{
  HWND hWnd;
  int iVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  HWND hWndInsertAfter;
  int X;
  int Y;
  int cx;
  UINT uFlags;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int local_18 [4];
  int *local_8;
  
  puStack_28 = &stack0xfffffffc;
  piVar2 = local_18;
  for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = *param_2;
    param_2 = param_2 + 1;
    piVar2 = piVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x7e) = 1;
  puStack_2c = &LAB_00446ce1;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  local_8 = param_1;
  FUN_0043f67c((int)param_1,param_3);
  local_18[3] = local_18[3] + 4;
  FUN_00440694((int)local_8,local_18);
  iVar1 = FUN_0043017c();
  if (iVar1 < local_8[0xf] + local_18[1]) {
    local_18[1] = FUN_0043017c();
    local_18[1] = local_18[1] - local_8[0xf];
  }
  iVar1 = FUN_00430188();
  if (iVar1 < local_8[0xe] + local_18[0]) {
    local_18[0] = FUN_00430188();
    local_18[0] = local_18[0] - local_8[0xe];
  }
  iVar1 = FUN_00430170();
  if (local_18[0] < iVar1) {
    local_18[0] = FUN_00430170();
  }
  iVar1 = FUN_00430164();
  if (local_18[3] < iVar1) {
    local_18[3] = FUN_00430164();
  }
  uFlags = 0x50;
  iVar1 = local_8[0xf];
  cx = local_8[0xe];
  hWndInsertAfter = (HWND)0xffffffff;
  X = local_18[0];
  Y = local_18[1];
  hWnd = (HWND)FUN_00445724(local_8);
  SetWindowPos(hWnd,hWndInsertAfter,X,Y,cx,iVar1,uFlags);
  (**(code **)(*local_8 + 0x74))();
  *in_FS_OFFSET = uStack_30;
  *(undefined1 *)(local_8 + 0x7e) = 0;
  return;
}

