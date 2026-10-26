/*
 * FUN_004324ec at 004324ec
 * undefined __register FUN_004324ec(int param_1, LPCSTR param_2, LPCSTR param_3, UINT param_4)
 * Address ranges: 004324ec-00432630
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004324ec(int param_1,LPCSTR param_2,LPCSTR param_3,UINT param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  tagRECT local_54;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  HWND local_10;
  int local_c;
  int local_8;
  
  local_8 = param_1;
  local_10 = GetActiveWindow();
  local_18 = (**(code **)PTR_DAT_0047c7b0)();
  local_1c = (**(code **)PTR_DAT_0047c7b0)();
  if (local_18 != local_1c) {
    local_44 = 0x28;
    (**(code **)PTR_DAT_0047c704)();
    GetWindowRect(*(HWND *)(local_8 + 0x24),&local_54);
    iVar2 = local_34 - local_3c >> 1;
    if (iVar2 < 0) {
      iVar2 = iVar2 + (uint)((local_34 - local_3c & 1U) != 0);
    }
    iVar3 = local_38 - local_40 >> 1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + (uint)((local_38 - local_40 & 1U) != 0);
    }
    SetWindowPos(*(HWND *)(local_8 + 0x24),(HWND)0x0,iVar3 + local_40,iVar2 + local_3c,0,0,0x1d);
  }
  local_14 = (undefined4 *)FUN_00429334(0);
  uVar1 = FUN_0043152c(local_8);
  if ((char)uVar1 != '\0') {
    param_4 = param_4 | 0x100000;
  }
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffff84;
  local_c = MessageBoxA(*(HWND *)(local_8 + 0x24),param_2,param_3,param_4);
  *in_FS_OFFSET = uVar1;
  if (local_18 != local_1c) {
    iVar2 = local_54.bottom - local_54.top >> 1;
    if (iVar2 < 0) {
      iVar2 = iVar2 + (uint)((local_54.bottom - local_54.top & 1U) != 0);
    }
    iVar3 = local_54.right - local_54.left >> 1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + (uint)((local_54.right - local_54.left & 1U) != 0);
    }
    SetWindowPos(*(HWND *)(local_8 + 0x24),(HWND)0x0,iVar3 + local_54.left,iVar2 + local_54.top,0,0,
                 0x1d);
  }
  FUN_004293e8(local_14);
  SetActiveWindow(local_10);
  return;
}

