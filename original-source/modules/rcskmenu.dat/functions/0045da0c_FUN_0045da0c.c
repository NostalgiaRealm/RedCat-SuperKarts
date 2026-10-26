/*
 * FUN_0045da0c at 0045da0c
 * undefined FUN_0045da0c(void)
 * Address ranges: 0045da0c-0045daac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045da0c(int *param_1)

{
  uint uVar1;
  LPCSTR lpchText;
  HDC hdc;
  undefined4 *in_FS_OFFSET;
  int cchText;
  tagRECT *lprc;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined *puStack_18;
  tagRECT tStack_14;
  
  puStack_20 = &stack0xfffffffc;
  puStack_18 = (undefined *)0x0;
  puStack_24 = &LAB_0045daad;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  FUN_00418458((int *)param_1[0x7c],0,0,(int *)param_1[0x80]);
  (**(code **)(*param_1 + 0x40))(param_1,&tStack_14);
  tStack_14.left = tStack_14.left + 2;
  (**(code **)(**(int **)(param_1[0x7c] + 0xc) + 8))(*(int **)(param_1[0x7c] + 0xc),param_1[0x81]);
  uVar1 = FUN_00441578((int)param_1);
  uVar1 = uVar1 | 0x814;
  lprc = &tStack_14;
  cchText = -1;
  FUN_0043f64c((int)param_1,(int *)&puStack_18);
  lpchText = FUN_00403f94(puStack_18);
  hdc = (HDC)FUN_00418994((int *)param_1[0x7c]);
  DrawTextA(hdc,lpchText,cchText,lprc,uVar1);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0045dab4;
  puStack_24 = (undefined1 *)0x45daac;
  FUN_00403b50((int *)&puStack_18);
  return;
}

