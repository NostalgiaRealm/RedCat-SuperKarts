/*
 * FUN_00417328 at 00417328
 * LONG __cdecl FUN_00417328(LPCSTR param_1, int param_2)
 * Address ranges: 00417328-004173af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LONG __cdecl FUN_00417328(LPCSTR param_1,int param_2)

{
  int iVar1;
  HDC local_10;
  tagSIZE local_c;
  
  FUN_004028c2(DAT_00438434);
  iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_10);
  if (iVar1 == 0) {
    if (DAT_0043dca8 != 0) {
      SelectObject(local_10,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
    }
    GetTextExtentPoint32A(local_10,param_1,param_2,&local_c);
    (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_10);
  }
  else {
    local_c.cy = -1;
  }
  return local_c.cy;
}

