/*
 * FUN_00445544 at 00445544
 * undefined FUN_00445544(void)
 * Address ranges: 00445544-00445595
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445544(int *param_1,int *param_2)

{
  HWND pHVar1;
  HDC pHVar2;
  int *piVar3;
  HRGN hrgnClip;
  DWORD flags;
  
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    pHVar1 = (HWND)FUN_00445724(param_1);
    pHVar2 = GetDC(pHVar1);
  }
  else {
    flags = 0x12;
    hrgnClip = (HRGN)0x0;
    pHVar1 = (HWND)FUN_00445724(param_1);
    pHVar2 = GetDCEx(pHVar1,hrgnClip,flags);
  }
  if (pHVar2 == (HDC)0x0) {
    piVar3 = FUN_0040ad20((int *)&DAT_0040ddb0,'\x01',(undefined4 *)PTR_PTR_0047c850);
    FUN_00403604(piVar3);
  }
  *param_2 = param_1[0x53];
  return;
}

