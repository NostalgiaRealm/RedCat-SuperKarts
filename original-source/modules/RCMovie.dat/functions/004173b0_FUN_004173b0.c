/*
 * FUN_004173b0 at 004173b0
 * undefined4 __cdecl FUN_004173b0(int param_1, int param_2, int param_3, byte * param_4)
 * Address ranges: 004173b0-0041796a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004173b0(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  UINT UVar2;
  tagSIZE *ptVar3;
  INT *pIVar4;
  tagRECT local_1ec;
  tagSIZE local_1dc;
  tagRECT local_1d4;
  tagSIZE local_1c4;
  tagRECT local_1bc;
  tagSIZE local_1ac;
  undefined4 *local_1a4;
  HDC local_1a0;
  HGDIOBJ local_19c;
  int local_198;
  CHAR local_194 [400];
  
  local_1a4 = (undefined4 *)&stack0x00000014;
  local_198 = FUN_0041f64a(local_194,param_4,local_1a4);
  local_1a4 = (undefined4 *)0x0;
  if (param_1 == 0) {
    if (DAT_00438458 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_1a0);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a0,0xff0000);
        SetTextColor(local_1a0,0xffff);
        iVar1 = lstrlenA(local_194);
        TextOutA(local_1a0,param_2,param_3,local_194,iVar1);
      }
      else {
        local_19c = SelectObject(local_1a0,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a0,*(COLORREF *)(&DAT_0043582c + DAT_00435818 * 0x10));
        SetBkColor(local_1a0,*(COLORREF *)(&DAT_00435828 + DAT_00435818 * 0x10));
        SetBkMode(local_1a0,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_1ac;
        iVar1 = lstrlenA(local_194);
        GetTextExtentPoint32A(local_1a0,local_194,iVar1,ptVar3);
        SetRect(&local_1bc,param_2,param_3,param_2 + local_1ac.cx,param_3 + local_1ac.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_194);
        ExtTextOutA(local_1a0,param_2,param_3,0,&local_1bc,local_194,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_1a0);
    }
  }
  else if (param_1 == 1) {
    if (DAT_0043845c == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x44))(DAT_00438438,&local_1a0);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a0,0xff0000);
        SetTextColor(local_1a0,0xffff);
        iVar1 = lstrlenA(local_194);
        TextOutA(local_1a0,param_2,param_3,local_194,iVar1);
      }
      else {
        local_19c = SelectObject(local_1a0,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a0,*(COLORREF *)(&DAT_0043582c + DAT_00435818 * 0x10));
        SetBkColor(local_1a0,*(COLORREF *)(&DAT_00435828 + DAT_00435818 * 0x10));
        SetBkMode(local_1a0,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_1c4;
        iVar1 = lstrlenA(local_194);
        GetTextExtentPoint32A(local_1a0,local_194,iVar1,ptVar3);
        SetRect(&local_1d4,param_2,param_3,param_2 + local_1c4.cx,param_3 + local_1c4.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_194);
        ExtTextOutA(local_1a0,param_2,param_3,0,&local_1d4,local_194,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438438 + 0x68))(DAT_00438438,local_1a0);
    }
  }
  else if (param_1 == 2) {
    if (DAT_00438460 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438418 + 0x44))(DAT_00438418,&local_1a0);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a0,0xff0000);
        SetTextColor(local_1a0,0xffff);
        iVar1 = lstrlenA(local_194);
        TextOutA(local_1a0,param_2,param_3,local_194,iVar1);
      }
      else {
        local_19c = SelectObject(local_1a0,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a0,*(COLORREF *)(&DAT_0043582c + DAT_00435818 * 0x10));
        SetBkColor(local_1a0,*(COLORREF *)(&DAT_00435828 + DAT_00435818 * 0x10));
        SetBkMode(local_1a0,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_1dc;
        iVar1 = lstrlenA(local_194);
        GetTextExtentPoint32A(local_1a0,local_194,iVar1,ptVar3);
        SetRect(&local_1ec,param_2,param_3,param_2 + local_1dc.cx,param_3 + local_1dc.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_194);
        ExtTextOutA(local_1a0,param_2,param_3,0,&local_1ec,local_194,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438418 + 0x68))(DAT_00438418,local_1a0);
    }
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0043594c);
  }
  return 0;
}

