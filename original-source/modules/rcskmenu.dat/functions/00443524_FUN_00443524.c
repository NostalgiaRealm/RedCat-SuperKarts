/*
 * FUN_00443524 at 00443524
 * undefined __register FUN_00443524(int param_1, HDC param_2, int param_3)
 * Address ranges: 00443524-00443753
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443524(int param_1,HDC param_2,int param_3)

{
  int iVar1;
  BOOL BVar2;
  int nSavedDC;
  int iVar3;
  COLORREF CVar4;
  HBRUSH pHVar5;
  int iVar6;
  HBRUSH pHVar7;
  int iStack_24;
  RECT RStack_20;
  
  if (((*(char *)(param_1 + 0x144) != '\0') && (*(char *)(param_1 + 0x17c) != '\0')) &&
     (*(int *)(param_1 + 0x148) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x148) + 0x20))(*(int **)(param_1 + 0x148),param_2);
  }
  if (*(int *)(param_1 + 0x134) != 0) {
    iVar6 = 0;
    if ((param_3 != 0) && (iVar6 = FUN_0040f70c(*(int *)(param_1 + 0x134),param_3), iVar6 < 0)) {
      iVar6 = 0;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x134) + 8);
    for (; iVar6 < iVar3; iVar6 = iVar6 + 1) {
      iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x134),iVar6);
      if ((*(char *)(iVar1 + 0x47) != '\0') ||
         (((*(byte *)(iVar1 + 0x20) & 0x10) != 0 && ((*(byte *)(iVar1 + 0x41) & 4) == 0)))) {
        FUN_0040ebe8(*(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34),
                     *(int *)(iVar1 + 0x30) + *(int *)(iVar1 + 0x38),&RStack_20.left,
                     *(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x3c));
        BVar2 = RectVisible(param_2,&RStack_20);
        if (BVar2 != 0) {
          if ((*(byte *)(param_1 + 0x44) & 0x80) != 0) {
            *(ushort *)(iVar1 + 0x44) = *(ushort *)(iVar1 + 0x44) | 0x80;
          }
          nSavedDC = SaveDC(param_2);
          FUN_0043e140(param_2,*(int *)(iVar1 + 0x30),*(int *)(iVar1 + 0x34));
          IntersectClipRect(param_2,0,0,*(int *)(iVar1 + 0x38),*(int *)(iVar1 + 0x3c));
          FUN_004405f0(iVar1,0xf,param_2,0);
          RestoreDC(param_2,nSavedDC);
          *(ushort *)(iVar1 + 0x44) = *(ushort *)(iVar1 + 0x44) & 0xff7f;
        }
      }
    }
  }
  if ((*(int *)(param_1 + 0x180) != 0) &&
     (iStack_24 = *(int *)(*(int *)(param_1 + 0x180) + 8), -1 < iStack_24 + -1)) {
    iVar6 = 0;
    do {
      iVar3 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x180),iVar6);
      if (((*(char *)(iVar3 + 0x138) != '\0') && ((*(byte *)(iVar3 + 0x40) & 0x10) != 0)) &&
         ((*(char *)(iVar3 + 0x47) != '\0' ||
          (((*(byte *)(iVar3 + 0x20) & 0x10) != 0 && ((*(byte *)(iVar3 + 0x41) & 4) == 0)))))) {
        CVar4 = FUN_00417210(0x80000010);
        pHVar5 = CreateSolidBrush(CVar4);
        pHVar7 = pHVar5;
        FUN_0040ebe8(*(int *)(iVar3 + 0x30) + -1,*(int *)(iVar3 + 0x34) + -1,
                     *(int *)(iVar3 + 0x30) + *(int *)(iVar3 + 0x38),&RStack_20.left,
                     *(int *)(iVar3 + 0x34) + *(int *)(iVar3 + 0x3c));
        FrameRect(param_2,&RStack_20,pHVar7);
        DeleteObject(pHVar5);
        CVar4 = FUN_00417210(0x80000014);
        pHVar5 = CreateSolidBrush(CVar4);
        pHVar7 = pHVar5;
        FUN_0040ebe8(*(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x34),
                     *(int *)(iVar3 + 0x30) + *(int *)(iVar3 + 0x38) + 1,&RStack_20.left,
                     *(int *)(iVar3 + 0x34) + *(int *)(iVar3 + 0x3c) + 1);
        FrameRect(param_2,&RStack_20,pHVar7);
        DeleteObject(pHVar5);
      }
      iVar6 = iVar6 + 1;
      iStack_24 = iStack_24 + -1;
    } while (iStack_24 != 0);
  }
  return;
}

