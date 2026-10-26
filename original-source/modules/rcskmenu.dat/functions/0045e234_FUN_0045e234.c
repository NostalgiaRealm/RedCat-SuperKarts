/*
 * FUN_0045e234 at 0045e234
 * undefined __register FUN_0045e234(int * param_1, int param_2)
 * Address ranges: 0045e234-0045e44c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e234(int *param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  HDC pHVar3;
  int *piVar4;
  LPCSTR lpchText;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined3 uVar5;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  tagRECT *ptVar6;
  int cchText;
  UINT UVar7;
  UINT UVar8;
  undefined4 uStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  RECT local_3c;
  undefined *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  char local_5;
  
  puStack_4c = &stack0xfffffffc;
  local_2c = (undefined *)0x0;
  puStack_50 = &LAB_0045e44d;
  uStack_54 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_54;
  FUN_00418a14((int *)param_1[0x80],*(int *)(param_2 + 0x18));
  (**(code **)(*param_1 + 0x40))(param_1,&local_18);
  if (param_1[0x82] == 0) {
    UVar8 = 0x10;
    UVar7 = 4;
    ptVar6 = &local_18;
    pHVar3 = (HDC)FUN_00418994((int *)param_1[0x80]);
    DrawFrameControl(pHVar3,ptVar6,UVar7,UVar8);
  }
  else {
    if (((*(uint *)(param_2 + 0x10) & 1) == 0) || ((char)param_1[0x84] == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    local_5 = (*(uint *)(param_2 + 0x10) & 0x10) != 0;
    cVar2 = (**(code **)(*param_1 + 0x4c))();
    uVar5 = (undefined3)((uint)extraout_EDX >> 8);
    if (cVar2 == '\0') {
      FUN_0045e01c((int)param_1,CONCAT31(uVar5,4));
      piVar4 = FUN_00453450(param_1[0x82],4);
    }
    else if (bVar1) {
      FUN_0045e01c((int)param_1,CONCAT31(uVar5,1));
      piVar4 = FUN_00453450(param_1[0x82],1);
    }
    else if ((char)param_1[0x84] == '\0') {
      if ((local_5 == '\0') && ((char)param_1[0x81] == '\0')) {
        FUN_0045e01c((int)param_1,0);
        piVar4 = FUN_00453450(param_1[0x82],0);
      }
      else {
        FUN_0045e01c((int)param_1,CONCAT31(uVar5,2));
        piVar4 = FUN_00453450(param_1[0x82],2);
      }
    }
    else {
      FUN_0045e01c((int)param_1,CONCAT31(uVar5,3));
      piVar4 = FUN_00453450(param_1[0x82],3);
    }
    FUN_00418458((int *)param_1[0x80],0,0,piVar4);
    FUN_004188b4(param_1[0x80]);
    if ((char)param_1[0x86] == '\x04') {
      FUN_004176d0(*(int **)(param_1[0x80] + 0xc),param_1[0x83],extraout_ECX);
    }
    FUN_00417fbc(*(int **)(param_1[0x80] + 0x14),'\x01');
    FUN_0045354c(param_1[0x82],CONCAT31((int3)((uint)extraout_EDX_00 >> 8),(char)param_1[0x86]),
                 &local_28.left);
    UVar7 = 0x25;
    if ((char)param_1[0x8e] != '\0') {
      UVar7 = 0x15;
    }
    ptVar6 = &local_28;
    cchText = -1;
    FUN_0043f64c((int)param_1,(int *)&local_2c);
    lpchText = FUN_00403f94(local_2c);
    pHVar3 = (HDC)FUN_00418994((int *)param_1[0x80]);
    DrawTextA(pHVar3,lpchText,cchText,ptVar6,UVar7);
    if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
      FUN_00417ea0(*(int **)(param_1[0x80] + 0x14),0xffffff);
      (**(code **)(*param_1 + 0x40))(param_1,&local_3c);
      FUN_00418574((int *)param_1[0x80],&local_3c);
    }
    FUN_00418a14((int *)param_1[0x80],0);
  }
  *in_FS_OFFSET = uStack_54;
  puStack_4c = &LAB_0045e454;
  puStack_50 = (undefined1 *)0x45e44c;
  FUN_00403b50((int *)&local_2c);
  return;
}

