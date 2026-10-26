/*
 * FUN_0041ae70 at 0041ae70
 * undefined __register FUN_0041ae70(int * param_1, int * param_2, LONG * param_3)
 * Address ranges: 0041ae70-0041af02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ae70(int *param_1,int *param_2,LONG *param_3)

{
  HPALETTE pHVar1;
  HDC pHVar2;
  int iVar3;
  HPALETTE pHVar4;
  RECT *pRVar5;
  byte bVar6;
  HENHMETAFILE hmf;
  BOOL BVar7;
  RECT RStack_20;
  
  bVar6 = 0;
  if (param_1[8] != 0) {
    pHVar1 = (HPALETTE)(**(code **)(*param_1 + 0x24))();
    pHVar4 = (HPALETTE)0x0;
    if (pHVar1 != (HPALETTE)0x0) {
      BVar7 = -1;
      pHVar4 = pHVar1;
      pHVar2 = (HDC)FUN_00418994(param_2);
      pHVar4 = SelectPalette(pHVar2,pHVar4,BVar7);
      pHVar2 = (HDC)FUN_00418994(param_2);
      RealizePalette(pHVar2);
    }
    pRVar5 = &RStack_20;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      pRVar5->left = *param_3;
      param_3 = param_3 + (uint)bVar6 * -2 + 1;
      pRVar5 = (RECT *)((int)pRVar5 + ((uint)bVar6 * -2 + 1) * 4);
    }
    RStack_20.right = RStack_20.right + -1;
    RStack_20.bottom = RStack_20.bottom + -1;
    pRVar5 = &RStack_20;
    hmf = *(HENHMETAFILE *)(param_1[8] + 8);
    pHVar2 = (HDC)FUN_00418994(param_2);
    PlayEnhMetaFile(pHVar2,hmf,pRVar5);
    if (pHVar1 != (HPALETTE)0x0) {
      BVar7 = -1;
      pHVar2 = (HDC)FUN_00418994(param_2);
      SelectPalette(pHVar2,pHVar4,BVar7);
    }
  }
  return;
}

