/*
 * FUN_00433ccc at 00433ccc
 * undefined __register FUN_00433ccc(int * param_1, int param_2, int * param_3, char param_4, UINT param_5, int param_6, int param_7)
 * Address ranges: 00433ccc-00433ea2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433ccc(int *param_1,int param_2,int *param_3,char param_4,UINT param_5,int param_6,
                 int param_7)

{
  bool bVar1;
  COLORREF CVar2;
  uint uVar3;
  COLORREF CVar4;
  HDC pHVar5;
  HIMAGELIST p_Var6;
  int *piVar7;
  int iVar8;
  undefined4 extraout_ECX;
  int iVar9;
  int dx;
  int iVar10;
  int dy;
  RECT *pRVar11;
  UINT fStyle;
  RECT local_2c;
  undefined4 local_1c [4];
  HDC local_c;
  int local_8;
  
  local_8 = param_2;
  bVar1 = FUN_00433874((int)param_1);
  if (bVar1) {
    if (param_4 == '\0') {
      if (param_1[0x12] == 0) {
        piVar7 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
        param_1[0x12] = (int)piVar7;
        FUN_0041dabc(piVar7,1);
        (**(code **)(*piVar7 + 0x40))(piVar7,param_1[10]);
        (**(code **)(*piVar7 + 0x34))(piVar7,param_1[9]);
      }
      iVar8 = FUN_0041cd5c((int *)param_1[0x12]);
      FUN_00417ea0(*(int **)(iVar8 + 0x14),0xffffff);
      FUN_0040ebe8(0,0,param_1[10],&local_2c.left,param_1[9]);
      pRVar11 = &local_2c;
      piVar7 = (int *)FUN_0041cd5c((int *)param_1[0x12]);
      FUN_00418538(piVar7,pRVar11);
      fStyle = 0;
      CVar4 = 0;
      CVar2 = 0xff000000;
      dy = 0;
      dx = 0;
      iVar10 = 0;
      iVar9 = 0;
      piVar7 = (int *)FUN_0041cd5c((int *)param_1[0x12]);
      pHVar5 = (HDC)FUN_00418994(piVar7);
      iVar8 = local_8;
      p_Var6 = (HIMAGELIST)FUN_004339b0(param_1);
      ImageList_DrawEx(p_Var6,iVar8,pHVar5,iVar9,iVar10,dx,dy,CVar2,CVar4,fStyle);
      FUN_0040ebe8(param_7,param_6,param_7 + param_1[10],local_1c,param_6 + param_1[9]);
      piVar7 = (int *)FUN_0041cd5c((int *)param_1[0x12]);
      local_c = (HDC)FUN_00418994(piVar7);
      FUN_00417ea0((int *)param_3[5],0x80000014);
      pHVar5 = (HDC)FUN_00418994(param_3);
      SetTextColor(pHVar5,0xffffff);
      SetBkColor(pHVar5,0);
      BitBlt(pHVar5,param_7 + 1,param_6 + 1,param_1[10],param_1[9],local_c,0,0,0xe20746);
      FUN_00417ea0((int *)param_3[5],0x80000010);
      pHVar5 = (HDC)FUN_00418994(param_3);
      SetTextColor(pHVar5,0xffffff);
      SetBkColor(pHVar5,0);
      BitBlt(pHVar5,param_7,param_6,param_1[10],param_1[9],local_c,0,0,0xe20746);
    }
    else {
      CVar2 = FUN_004336c4(param_1[0xf]);
      uVar3 = FUN_00433ca4(param_1);
      CVar4 = FUN_004336c4(uVar3);
      iVar10 = 0;
      iVar9 = 0;
      pHVar5 = (HDC)FUN_00418994(param_3);
      iVar8 = local_8;
      p_Var6 = (HIMAGELIST)FUN_004339b0(param_1);
      ImageList_DrawEx(p_Var6,iVar8,pHVar5,param_7,param_6,iVar9,iVar10,CVar4,CVar2,param_5);
    }
  }
  return;
}

