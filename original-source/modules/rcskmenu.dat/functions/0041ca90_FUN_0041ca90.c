/*
 * FUN_0041ca90 at 0041ca90
 * undefined FUN_0041ca90(void)
 * Address ranges: 0041ca90-0041cc61;0041cc69-0041cccc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ca90(int *param_1,int *param_2,int *param_3)

{
  HPALETTE hPal;
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  HDC pHVar6;
  HGDIOBJ h;
  int iVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar8;
  int ySrc;
  int iVar9;
  DWORD rop;
  tagPOINT tStack_18;
  char cStack_d;
  HPALETTE pHStack_c;
  int *piStack_8;
  
  iVar9 = param_1[8];
  piStack_8 = param_2;
  FUN_00418a68(param_2,0xf);
  FUN_0041d064((int)param_1);
  pHStack_c = (HPALETTE)0x0;
  cStack_d = 0;
  hPal = *(HPALETTE *)(iVar9 + 0x10);
  if (hPal != (HPALETTE)0x0) {
    pHStack_c = SelectPalette((HDC)piStack_8[1],hPal,-1);
    RealizePalette((HDC)piStack_8[1]);
  }
  cStack_d = hPal != (HPALETTE)0x0;
  iVar3 = GetDeviceCaps((HDC)piStack_8[1],0xc);
  iVar4 = GetDeviceCaps((HDC)piStack_8[1],0xe);
  if ((iVar3 * iVar4 < 9) &&
     (iVar3 * iVar4 < (int)((uint)*(ushort *)(iVar9 + 0x2a) * (uint)*(ushort *)(iVar9 + 0x28)))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    GetBrushOrgEx((HDC)piStack_8[1],&tStack_18);
    SetStretchBltMode((HDC)piStack_8[1],4);
    SetBrushOrgEx((HDC)piStack_8[1],tStack_18.x,tStack_18.y,&tStack_18);
  }
  else {
    uVar8 = FUN_0041ce10((int)param_1);
    if ((char)uVar8 == '\0') {
      iVar3 = 3;
      pHVar6 = (HDC)FUN_00418994(piStack_8);
      SetStretchBltMode(pHVar6,iVar3);
    }
  }
  uVar8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffc8;
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 != '\0') {
    FUN_0041d004(param_1);
  }
  piVar5 = (int *)FUN_0041cd5c(param_1);
  FUN_00418a68(piVar5,0xf);
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 != '\0') {
    *in_FS_OFFSET = &stack0xffffffbc;
    pHVar6 = CreateCompatibleDC((HDC)0x0);
    pHVar6 = (HDC)FUN_00418d8c((int)pHVar6);
    h = SelectObject(pHVar6,*(HGDIOBJ *)(iVar9 + 0xc));
    iVar3 = param_3[2] - *param_3;
    iVar4 = param_3[3] - param_3[1];
    iVar7 = FUN_0041cd5c(param_1);
    uVar8 = 0;
    FUN_00418f30((HDC)piStack_8[1],*param_3,param_3[1],0,0,pHVar6,*(int *)(iVar9 + 0x20),
                 *(int *)(iVar9 + 0x1c),0,0,*(HDC *)(iVar7 + 4),iVar4,iVar3);
    *in_FS_OFFSET = uVar8;
    if (h != (HGDIOBJ)0x0) {
      SelectObject(pHVar6,h);
    }
    if (pHVar6 != (HDC)0x0) {
      DeleteDC(pHVar6);
    }
    return;
  }
  rop = piStack_8[8];
  iVar3 = *(int *)(iVar9 + 0x20);
  iVar9 = *(int *)(iVar9 + 0x1c);
  ySrc = 0;
  iVar7 = 0;
  iVar4 = FUN_0041cd5c(param_1);
  StretchBlt((HDC)piStack_8[1],*param_3,param_3[1],param_3[2] - *param_3,param_3[3] - param_3[1],
             *(HDC *)(iVar4 + 4),iVar7,ySrc,iVar9,iVar3,rop);
  *in_FS_OFFSET = uVar8;
  if (cStack_d != '\0') {
    SelectPalette((HDC)piStack_8[1],pHStack_c,-1);
  }
  return;
}

