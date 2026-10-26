/*
 * FUN_00446a34 at 00446a34
 * undefined FUN_00446a34(void)
 * Address ranges: 00446a34-00446ac1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446a34(int *param_1)

{
  uint uVar1;
  LPCSTR lpchText;
  HDC hdc;
  undefined4 extraout_ECX;
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
  puStack_24 = &LAB_00446ac2;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  (**(code **)(*param_1 + 0x40))(param_1,&tStack_14);
  tStack_14.left = tStack_14.left + 2;
  tStack_14.top = tStack_14.top + 2;
  FUN_004176d0(*(int **)(param_1[0x7c] + 0xc),-0x7fffffe9,extraout_ECX);
  uVar1 = FUN_00441578((int)param_1);
  uVar1 = uVar1 | 0x810;
  lprc = &tStack_14;
  cchText = -1;
  FUN_0043f64c((int)param_1,(int *)&puStack_18);
  lpchText = FUN_00403f94(puStack_18);
  hdc = (HDC)FUN_00418994((int *)param_1[0x7c]);
  DrawTextA(hdc,lpchText,cchText,lprc,uVar1);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00446ac9;
  puStack_24 = (undefined1 *)0x446ac1;
  FUN_00403b50((int *)&puStack_18);
  return;
}

