/*
 * FUN_0043ff48 at 0043ff48
 * undefined __register FUN_0043ff48(undefined4 param_1, int * param_2, char param_3)
 * Address ranges: 0043ff48-00440068
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ff48(undefined4 param_1,int *param_2,char param_3)

{
  int y;
  int h;
  HGDIOBJ h_00;
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  byte bVar4;
  undefined4 uVar5;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  HGDIOBJ local_14;
  HDC local_10;
  HWND local_c;
  char local_5;
  
  bVar4 = 0;
  local_5 = param_3;
  h = (**(code **)(*param_2 + 0x34))();
  if (local_5 == '\0') {
    piVar2 = param_2 + 0x11;
    piVar3 = &local_24;
    for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + (uint)bVar4 * -2 + 1;
      piVar3 = piVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  else {
    piVar2 = param_2 + 0x17;
    piVar3 = &local_24;
    for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + (uint)bVar4 * -2 + 1;
      piVar3 = piVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  local_c = GetDesktopWindow();
  local_10 = GetDCEx(local_c,(HRGN)0x0,0x402);
  uVar5 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffc4;
  h_00 = (HGDIOBJ)FUN_00417ed4(param_2[0x10]);
  local_14 = SelectObject(local_10,h_00);
  y = local_20;
  iVar1 = local_24;
  PatBlt(local_10,local_24 + h,local_20,(local_1c - local_24) - h,h,0x5a0049);
  PatBlt(local_10,local_1c - h,y + h,h,(local_18 - y) - h,0x5a0049);
  PatBlt(local_10,iVar1,local_18 - h,(local_1c - local_24) - h,h,0x5a0049);
  PatBlt(local_10,iVar1,y,h,(local_18 - local_20) - h,0x5a0049);
  SelectObject(local_10,local_14);
  *in_FS_OFFSET = uVar5;
  ReleaseDC(local_c,local_10);
  return;
}

