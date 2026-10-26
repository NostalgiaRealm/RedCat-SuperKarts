/*
 * FUN_0041796b at 0041796b
 * undefined4 __cdecl FUN_0041796b(int param_1, int param_2, int param_3, COLORREF param_4, COLORREF param_5, byte * param_6)
 * Address ranges: 0041796b-00417ebe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_0041796b(int param_1,int param_2,int param_3,COLORREF param_4,COLORREF param_5,byte *param_6)

{
  int iVar1;
  UINT UVar2;
  tagSIZE *ptVar3;
  INT *pIVar4;
  tagRECT local_1dc;
  tagRECT local_1cc;
  tagRECT local_1bc;
  undefined4 *local_1ac;
  HDC local_1a8;
  HGDIOBJ local_1a4;
  int local_1a0;
  CHAR local_19c [400];
  tagSIZE local_c;
  
  local_1ac = (undefined4 *)&stack0x0000001c;
  local_1a0 = FUN_0041f64a(local_19c,param_6,local_1ac);
  local_1ac = (undefined4 *)0x0;
  if (param_1 == 0) {
    if (DAT_00438458 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_1a8);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a8,param_4);
        SetTextColor(local_1a8,param_5);
        iVar1 = lstrlenA(local_19c);
        TextOutA(local_1a8,param_2,param_3,local_19c,iVar1);
      }
      else {
        local_1a4 = SelectObject(local_1a8,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a8,param_5);
        SetBkColor(local_1a8,param_4);
        SetBkMode(local_1a8,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_c;
        iVar1 = lstrlenA(local_19c);
        GetTextExtentPoint32A(local_1a8,local_19c,iVar1,ptVar3);
        SetRect(&local_1bc,param_2,param_3,param_2 + local_c.cx,param_3 + local_c.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_19c);
        ExtTextOutA(local_1a8,param_2,param_3,0,&local_1bc,local_19c,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_1a8);
    }
  }
  else if (param_1 == 1) {
    if (DAT_0043845c == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x44))(DAT_00438438,&local_1a8);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a8,param_4);
        SetTextColor(local_1a8,param_5);
        iVar1 = lstrlenA(local_19c);
        TextOutA(local_1a8,param_2,param_3,local_19c,iVar1);
      }
      else {
        local_1a4 = SelectObject(local_1a8,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a8,param_5);
        SetBkColor(local_1a8,param_4);
        SetBkMode(local_1a8,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_c;
        iVar1 = lstrlenA(local_19c);
        GetTextExtentPoint32A(local_1a8,local_19c,iVar1,ptVar3);
        SetRect(&local_1cc,param_2,param_3,param_2 + local_c.cx,param_3 + local_c.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_19c);
        ExtTextOutA(local_1a8,param_2,param_3,0,&local_1cc,local_19c,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438438 + 0x68))(DAT_00438438,local_1a8);
    }
  }
  else if (param_1 == 2) {
    if (DAT_00438460 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438418 + 0x44))(DAT_00438418,&local_1a8);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a8,param_4);
        SetTextColor(local_1a8,param_5);
        iVar1 = lstrlenA(local_19c);
        TextOutA(local_1a8,param_2,param_3,local_19c,iVar1);
      }
      else {
        local_1a4 = SelectObject(local_1a8,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a8,param_5);
        SetBkColor(local_1a8,param_4);
        SetBkMode(local_1a8,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_c;
        iVar1 = lstrlenA(local_19c);
        GetTextExtentPoint32A(local_1a8,local_19c,iVar1,ptVar3);
        SetRect(&local_1dc,param_2,param_3,param_2 + local_c.cx,param_3 + local_c.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_19c);
        ExtTextOutA(local_1a8,param_2,param_3,0,&local_1dc,local_19c,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438418 + 0x68))(DAT_00438418,local_1a8);
    }
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00435980);
  }
  return 0;
}

