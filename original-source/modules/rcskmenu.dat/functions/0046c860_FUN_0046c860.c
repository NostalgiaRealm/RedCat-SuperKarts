/*
 * FUN_0046c860 at 0046c860
 * undefined __register FUN_0046c860(int * param_1, byte param_2, int param_3)
 * Address ranges: 0046c860-0046cb59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046c860(int *param_1,byte param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  HWND pHVar10;
  HWND pHVar11;
  HDC hDC;
  int *piVar12;
  tagRECT *lprc;
  int *piVar13;
  tagRECT tStack_48;
  int aiStack_30 [4];
  int aiStack_20 [4];
  
  if ((*(char *)((int)param_1 + 0x291) == '\0') || (param_2 != *(byte *)((int)param_1 + 0x292))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  piVar1 = (int *)param_1[0x7c];
  FUN_00417fbc((int *)piVar1[5],'\0');
  FUN_00417ea0((int *)piVar1[5],0x8000000f);
  FUN_00417bbc((int *)piVar1[4],0x80000006);
  FUN_00417cc8((int *)piVar1[4],1);
  FUN_00418674(piVar1,param_3,0,param_1[0xf],param_1[0xa9] + param_3);
  if (bVar3) {
    FUN_00417bbc((int *)piVar1[4],0x80000010);
    FUN_00418610(piVar1,param_3 + 1,param_1[0xf] + -2);
    FUN_004185b0(piVar1,param_3 + 1,1);
    FUN_004185b0(piVar1,param_1[0xa9] + param_3 + -1,1);
  }
  else {
    FUN_00417bbc((int *)piVar1[4],0x80000014);
    FUN_00418610(piVar1,param_3 + 1,param_1[0xf] + -2);
    FUN_004185b0(piVar1,param_3 + 1,1);
    FUN_004185b0(piVar1,param_1[0xa9] + param_3 + -1,1);
    FUN_00417bbc((int *)piVar1[4],0x80000010);
    FUN_00418610(piVar1,param_3 + 2,param_1[0xf] + -2);
    FUN_004185b0(piVar1,param_1[0xa9] + param_3 + -2,param_1[0xf] + -2);
    FUN_004185b0(piVar1,param_1[0xa9] + param_3 + -2,1);
  }
  cVar4 = (**(code **)(*param_1 + 0x4c))();
  if ((cVar4 == '\0') && ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
    iVar5 = 1;
  }
  else if (((char)param_1[0xc1] == '\0') || ((*(byte *)(param_1 + 8) & 0x10) != 0)) {
    if (*(char *)((int)param_1 + (uint)param_2 * 0x10 + 0x1f9) == '\0') {
      iVar5 = 1;
    }
    else {
      iVar5 = 0;
      if (*(char *)((int)param_1 + (uint)param_2 * 0x10 + 0x1fa) != '\0') {
        iVar5 = 2;
      }
    }
  }
  else if (*(char *)((int)param_1 + (uint)param_2 * 0x10 + 0x1fb) == '\0') {
    iVar5 = 1;
  }
  else {
    iVar5 = 0;
    if (*(char *)((int)param_1 + (uint)param_2 * 0x10 + 0x1fa) != '\0') {
      iVar5 = 2;
    }
  }
  piVar2 = (int *)param_1[(uint)param_2 * 4 + iVar5 + 0x7f];
  uVar6 = (**(code **)(*piVar2 + 0x2c))();
  iVar5 = (int)uVar6 >> 1;
  if (iVar5 < 0) {
    iVar5 = iVar5 + (uint)((uVar6 & 1) != 0);
  }
  tStack_48.left = param_1[0xa9] >> 1;
  if (tStack_48.left < 0) {
    tStack_48.left = tStack_48.left + (uint)((param_1[0xa9] & 1U) != 0);
  }
  tStack_48.left = tStack_48.left - iVar5;
  uVar6 = (**(code **)(*piVar2 + 0x20))();
  iVar5 = (int)uVar6 >> 1;
  if (iVar5 < 0) {
    iVar5 = iVar5 + (uint)((uVar6 & 1) != 0);
  }
  tStack_48.top = param_1[0xf] >> 1;
  if (tStack_48.top < 0) {
    tStack_48.top = tStack_48.top + (uint)((param_1[0xf] & 1U) != 0);
  }
  tStack_48.top = tStack_48.top - iVar5;
  if (bVar3) {
    tStack_48.left = tStack_48.left + 1;
    tStack_48.top = tStack_48.top + 1;
  }
  uVar7 = (**(code **)(*piVar2 + 0x20))();
  piVar13 = aiStack_30;
  uVar8 = (**(code **)(*piVar2 + 0x2c))();
  FUN_0040ebe8(0,0,uVar8,piVar13,uVar7);
  piVar13 = aiStack_30;
  uVar6 = 0x8080;
  iVar5 = (**(code **)(*piVar2 + 0x20))();
  piVar12 = aiStack_20;
  iVar9 = (**(code **)(*piVar2 + 0x2c))();
  FUN_0040ec04(tStack_48.left + param_3,tStack_48.top,iVar9,piVar12,iVar5);
  FUN_00418110(piVar1,aiStack_20,piVar2,uVar6,piVar13);
  pHVar10 = (HWND)FUN_00445724(param_1);
  pHVar11 = GetFocus();
  if ((pHVar10 == pHVar11) && ((char)uVar6 == (char)param_1[0xb2])) {
    FUN_0040ec04(param_3,0,param_1[0xa9],&tStack_48.left,param_1[0xf]);
    cVar4 = (char)(uVar6 >> 8);
    InflateRect(&tStack_48,-3,-3);
    if (cVar4 != '\0') {
      OffsetRect(&tStack_48,1,1);
    }
    lprc = &tStack_48;
    hDC = (HDC)FUN_00418994((int *)param_1[0x7c]);
    DrawFocusRect(hDC,lprc);
  }
  return;
}

