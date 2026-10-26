/*
 * FUN_004b1850 at 004b1850
 * undefined FUN_004b1850(void)
 * Address ranges: 004b1850-004b1d5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b1850(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  UINT UVar3;
  int *piVar4;
  int unaff_EBX;
  HDC unaff_ESI;
  INT *pIVar5;
  LPSIZE ptVar6;
  int local_1c4 [3];
  tagRECT local_1b8;
  tagRECT local_1a0;
  undefined1 local_190 [400];
  
  cVar1 = FUN_004afcb0();
  if ((cVar1 != '\0') && (param_1 == 0)) {
    GetClientRect(DAT_006a64b4,&local_1a0);
    local_1b8.left = local_1a0.left;
    local_1b8.top = local_1a0.top;
    ClientToScreen(DAT_006a64b4,(LPPOINT)&local_1b8);
    param_2 = param_2 + local_1b8.left;
    param_3 = param_3 + local_1b8.top;
  }
  FUN_004bf568(local_190,param_4,&stack0x00000014);
  if (param_1 == 0) {
    if (DAT_006a64e0 == 0) {
      return 0x2711;
    }
    FUN_004b08e0(DAT_006a64bc);
    iVar2 = (**(code **)(*DAT_006a64bc + 0x44))(DAT_006a64bc,local_1c4);
    if (iVar2 != 0) {
      return 0;
    }
    if (DAT_006a6508 == 0) {
      SetBkColor(unaff_ESI,0xff0000);
      SetTextColor(unaff_ESI,0xffff);
      iVar2 = lstrlenA((LPCSTR)&local_1a0.right);
      TextOutA(unaff_ESI,param_2,param_3,(LPCSTR)&local_1a0.right,iVar2);
      piVar4 = DAT_006a64bc;
    }
    else {
      SelectObject(unaff_ESI,*(HGDIOBJ *)(DAT_004ff910 * 0x10 + 0x4ff918));
      SetTextColor(unaff_ESI,*(COLORREF *)(DAT_004ff910 * 0x10 + 0x4ff924));
      SetBkColor(unaff_ESI,*(COLORREF *)(DAT_004ff910 * 0x10 + 0x4ff920));
      SetBkMode(unaff_ESI,*(int *)(DAT_004ff910 * 0x10 + 0x4ff91c));
      ptVar6 = (LPSIZE)&stack0xfffffe38;
      iVar2 = lstrlenA((LPCSTR)&local_1a0.right);
      GetTextExtentPoint32A(unaff_ESI,(LPCSTR)&local_1a0.right,iVar2,ptVar6);
      SetRect(&local_1b8,param_2,param_3,unaff_EBX + param_2,local_1c4[0] + param_3);
      pIVar5 = (INT *)0x0;
      UVar3 = lstrlenA((LPCSTR)&local_1a0.right);
      ExtTextOutA(unaff_ESI,param_2,param_3,0,&local_1b8,(LPCSTR)&local_1a0.right,UVar3,pIVar5);
      piVar4 = DAT_006a64bc;
    }
  }
  else if (param_1 == 1) {
    if (DAT_006a64e4 == 0) {
      return 0x2711;
    }
    FUN_004b08e0(DAT_006a64c0);
    iVar2 = (**(code **)(*DAT_006a64c0 + 0x44))(DAT_006a64c0,local_1c4);
    if (iVar2 != 0) {
      return 0;
    }
    if (DAT_006a6508 == 0) {
      SetBkColor(unaff_ESI,0xff0000);
      SetTextColor(unaff_ESI,0xffff);
      iVar2 = lstrlenA((LPCSTR)&local_1a0.right);
      TextOutA(unaff_ESI,param_2,param_3,(LPCSTR)&local_1a0.right,iVar2);
      piVar4 = DAT_006a64c0;
    }
    else {
      SelectObject(unaff_ESI,*(HGDIOBJ *)(DAT_004ff910 * 0x10 + 0x4ff918));
      SetTextColor(unaff_ESI,*(COLORREF *)(DAT_004ff910 * 0x10 + 0x4ff924));
      SetBkColor(unaff_ESI,*(COLORREF *)(DAT_004ff910 * 0x10 + 0x4ff920));
      SetBkMode(unaff_ESI,*(int *)(DAT_004ff910 * 0x10 + 0x4ff91c));
      ptVar6 = (LPSIZE)&stack0xfffffe38;
      iVar2 = lstrlenA((LPCSTR)&local_1a0.right);
      GetTextExtentPoint32A(unaff_ESI,(LPCSTR)&local_1a0.right,iVar2,ptVar6);
      SetRect(&local_1b8,param_2,param_3,unaff_EBX + param_2,local_1c4[0] + param_3);
      pIVar5 = (INT *)0x0;
      UVar3 = lstrlenA((LPCSTR)&local_1a0.right);
      ExtTextOutA(unaff_ESI,param_2,param_3,0,&local_1b8,(LPCSTR)&local_1a0.right,UVar3,pIVar5);
      piVar4 = DAT_006a64c0;
    }
  }
  else {
    if (param_1 != 2) {
      FUN_004afee0(s__s__d____unidentified_focus_erro_004ffa38,
                   s_C__libraries_dxdraw_Font_cpp_004ffa60,0x103);
      return 0;
    }
    if (DAT_006a64e8 == 0) {
      return 0x2711;
    }
    FUN_004b08e0(DAT_006a64a0);
    iVar2 = (**(code **)(*DAT_006a64a0 + 0x44))(DAT_006a64a0,local_1c4);
    if (iVar2 != 0) {
      return 0;
    }
    if (DAT_006a6508 == 0) {
      SetBkColor(unaff_ESI,0xff0000);
      SetTextColor(unaff_ESI,0xffff);
      iVar2 = lstrlenA((LPCSTR)&local_1a0.right);
      TextOutA(unaff_ESI,param_2,param_3,(LPCSTR)&local_1a0.right,iVar2);
      piVar4 = DAT_006a64a0;
    }
    else {
      SelectObject(unaff_ESI,*(HGDIOBJ *)(DAT_004ff910 * 0x10 + 0x4ff918));
      SetTextColor(unaff_ESI,*(COLORREF *)(DAT_004ff910 * 0x10 + 0x4ff924));
      SetBkColor(unaff_ESI,*(COLORREF *)(DAT_004ff910 * 0x10 + 0x4ff920));
      SetBkMode(unaff_ESI,*(int *)(DAT_004ff910 * 0x10 + 0x4ff91c));
      ptVar6 = (LPSIZE)&stack0xfffffe38;
      iVar2 = lstrlenA((LPCSTR)&local_1a0.right);
      GetTextExtentPoint32A(unaff_ESI,(LPCSTR)&local_1a0.right,iVar2,ptVar6);
      SetRect(&local_1b8,param_2,param_3,unaff_EBX + param_2,local_1c4[0] + param_3);
      pIVar5 = (INT *)0x0;
      UVar3 = lstrlenA((LPCSTR)&local_1a0.right);
      ExtTextOutA(unaff_ESI,param_2,param_3,0,&local_1b8,(LPCSTR)&local_1a0.right,UVar3,pIVar5);
      piVar4 = DAT_006a64a0;
    }
  }
  (**(code **)(*piVar4 + 0x68))(piVar4,unaff_ESI);
  return 0;
}

