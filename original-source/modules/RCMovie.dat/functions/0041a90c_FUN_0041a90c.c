/*
 * FUN_0041a90c at 0041a90c
 * undefined4 __cdecl FUN_0041a90c(HDC param_1, HWND param_2)
 * Address ranges: 0041a90c-0041a989
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041a90c(HDC param_1,HWND param_2)

{
  int iVar1;
  HWND pHVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00412b01((int)param_2);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    pHVar2 = GetFocus();
    if (param_2 == pHVar2) {
      SetTextColor(param_1,*(COLORREF *)(iVar1 + 0x24));
      SetBkColor(param_1,*(COLORREF *)(iVar1 + 0x20));
      uVar3 = *(undefined4 *)(iVar1 + 0x28);
    }
    else {
      SetTextColor(param_1,*(COLORREF *)(iVar1 + 0x18));
      SetBkColor(param_1,*(COLORREF *)(iVar1 + 0x14));
      uVar3 = *(undefined4 *)(iVar1 + 0x1c);
    }
  }
  return uVar3;
}

