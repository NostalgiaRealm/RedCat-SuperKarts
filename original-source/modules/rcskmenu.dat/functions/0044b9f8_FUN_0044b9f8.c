/*
 * FUN_0044b9f8 at 0044b9f8
 * undefined FUN_0044b9f8(void)
 * Address ranges: 0044b9f8-0044bb40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b9f8(int *param_1)

{
  int *piVar1;
  LONG LVar2;
  LPCSTR lpchText;
  HDC hdc;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint uVar3;
  undefined4 *in_FS_OFFSET;
  int cchText;
  tagRECT *lprc;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined *puStack_20;
  tagRECT tStack_1c;
  undefined4 uStack_8;
  
  puStack_30 = &stack0xfffffffc;
  puStack_20 = (undefined *)0x0;
  puStack_34 = &LAB_0044bb41;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  (**(code **)(*param_1 + 0x40))(param_1,&tStack_1c);
  if (*(char *)((int)param_1 + 0x1fa) != '\0') {
    FUN_0044b9c0(*(char *)((int)param_1 + 0x1fa),extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    FUN_0044b028(param_1[0x7c],&tStack_1c,uStack_8,param_1[0x7f]);
  }
  FUN_0044b028(param_1[0x7c],&tStack_1c,param_1[0x18],param_1[0x80]);
  if (*(char *)((int)param_1 + 0x1f9) != '\0') {
    FUN_0044b9c0(*(char *)((int)param_1 + 0x1f9),extraout_EDX_00,extraout_ECX_00,
                 (int)&stack0xfffffffc);
    FUN_0044b028(param_1[0x7c],&tStack_1c,uStack_8,param_1[0x7f]);
  }
  piVar1 = (int *)param_1[0x7c];
  FUN_00417ea0((int *)piVar1[5],param_1[0x18]);
  FUN_00418538(piVar1,&tStack_1c);
  FUN_00417fbc((int *)piVar1[5],'\x01');
  FUN_004188b4((int)piVar1);
  LVar2 = FUN_00418810(piVar1,&LAB_0044bb58);
  uVar3 = (tStack_1c.bottom + tStack_1c.top) - LVar2;
  tStack_1c.top = (int)uVar3 >> 1;
  if (tStack_1c.top < 0) {
    tStack_1c.top = tStack_1c.top + (uint)((uVar3 & 1) != 0);
  }
  tStack_1c.bottom = LVar2 + tStack_1c.top;
  uVar3 = FUN_00441538(param_1,*(uint *)(&DAT_0047ba2c + (uint)*(byte *)((int)param_1 + 0x207) * 4)
                               | 0x44,extraout_ECX_01);
  lprc = &tStack_1c;
  cchText = -1;
  FUN_0043f64c((int)param_1,(int *)&puStack_20);
  lpchText = FUN_00403f94(puStack_20);
  hdc = (HDC)FUN_00418994(piVar1);
  DrawTextA(hdc,lpchText,cchText,lprc,uVar3);
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0044bb48;
  puStack_34 = (undefined1 *)0x44bb40;
  FUN_00403b50((int *)&puStack_20);
  return;
}

