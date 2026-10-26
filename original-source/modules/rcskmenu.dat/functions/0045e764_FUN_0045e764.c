/*
 * FUN_0045e764 at 0045e764
 * undefined FUN_0045e764(void)
 * Address ranges: 0045e764-0045e950
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e764(int *param_1,int param_2)

{
  char cVar1;
  HDC pHVar2;
  int *piVar3;
  LPCSTR lpchText;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined3 uVar4;
  undefined4 extraout_EDX_01;
  undefined4 *in_FS_OFFSET;
  tagRECT *ptVar5;
  int cchText;
  UINT UVar6;
  UINT UVar7;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  RECT RStack_3c;
  undefined *puStack_2c;
  tagRECT tStack_28;
  tagRECT tStack_18;
  char cStack_6;
  char cStack_5;
  
  puStack_48 = &stack0xfffffffc;
  puStack_2c = (undefined *)0x0;
  puStack_4c = &LAB_0045e951;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  FUN_00418a14((int *)param_1[0x80],*(int *)(param_2 + 0x18));
  (**(code **)(*param_1 + 0x40))(param_1,&tStack_18);
  if (param_1[0x82] == 0) {
    UVar7 = 0;
    UVar6 = 4;
    ptVar5 = &tStack_18;
    pHVar2 = (HDC)FUN_00418994((int *)param_1[0x80]);
    DrawFrameControl(pHVar2,ptVar5,UVar6,UVar7);
  }
  else {
    if (((*(uint *)(param_2 + 0x10) & 1) == 0) || ((char)param_1[0x84] == '\0')) {
      cStack_5 = '\0';
    }
    else {
      cStack_5 = '\x01';
    }
    cStack_6 = (*(uint *)(param_2 + 0x10) & 0x10) != 0;
    cVar1 = (**(code **)(*param_1 + 0x4c))();
    if (cVar1 == '\0') {
      FUN_0045e01c((int)param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),4));
      piVar3 = FUN_00453450(param_1[0x82],4);
    }
    else {
      cVar1 = (**(code **)(*param_1 + 0xb4))();
      uVar4 = (undefined3)((uint)extraout_EDX_00 >> 8);
      if (cVar1 == '\0' && cStack_5 == '\0') {
        if ((char)param_1[0x84] == '\0') {
          if (cStack_6 == '\0') {
            FUN_0045e01c((int)param_1,0);
            piVar3 = FUN_00453450(param_1[0x82],0);
          }
          else {
            FUN_0045e01c((int)param_1,CONCAT31(uVar4,2));
            piVar3 = FUN_00453450(param_1[0x82],2);
          }
        }
        else {
          FUN_0045e01c((int)param_1,CONCAT31(uVar4,3));
          piVar3 = FUN_00453450(param_1[0x82],3);
        }
      }
      else {
        FUN_0045e01c((int)param_1,CONCAT31(uVar4,1));
        piVar3 = FUN_00453450(param_1[0x82],1);
      }
    }
    FUN_00418458((int *)param_1[0x80],0,0,piVar3);
    FUN_004188b4(param_1[0x80]);
    FUN_00417fbc(*(int **)(param_1[0x80] + 0x14),'\x01');
    FUN_0045354c(param_1[0x82],CONCAT31((int3)((uint)extraout_EDX_01 >> 8),(char)param_1[0x86]),
                 &tStack_28.left);
    UVar6 = 0x25;
    ptVar5 = &tStack_28;
    cchText = -1;
    FUN_0043f64c((int)param_1,(int *)&puStack_2c);
    lpchText = FUN_00403f94(puStack_2c);
    pHVar2 = (HDC)FUN_00418994((int *)param_1[0x80]);
    DrawTextA(pHVar2,lpchText,cchText,ptVar5,UVar6);
    if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
      FUN_00417ea0(*(int **)(param_1[0x80] + 0x14),0xffffff);
      (**(code **)(*param_1 + 0x40))(param_1,&RStack_3c);
      FUN_00418574((int *)param_1[0x80],&RStack_3c);
    }
    FUN_00418a14((int *)param_1[0x80],0);
  }
  *in_FS_OFFSET = uStack_50;
  puStack_48 = &LAB_0045e958;
  puStack_4c = (undefined1 *)0x45e950;
  FUN_00403b50((int *)&puStack_2c);
  return;
}

