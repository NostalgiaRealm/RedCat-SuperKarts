/*
 * FUN_00418110 at 00418110
 * undefined __register FUN_00418110(int * param_1, int * param_2, int * param_3, uint param_4, int * param_5)
 * Address ranges: 00418110-0041836e;004183bd-004183c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418110(int *param_1,int *param_2,int *param_3,uint param_4,int *param_5)

{
  int iVar1;
  int hDest;
  int hSrc;
  uint uVar2;
  HGDIOBJ h;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  COLORREF color;
  COLORREF color_00;
  undefined4 extraout_ECX;
  int wSrc;
  undefined4 *in_FS_OFFSET;
  int xSrc;
  int wSrc_00;
  int hSrc_00;
  DWORD rop;
  undefined4 uVar7;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  HGDIOBJ local_2c;
  int *local_28;
  HDC local_24;
  
  if (param_3 != (int *)0x0) {
    puStack_3c = (undefined1 *)0x418136;
    FUN_004185e8((int)param_1);
    puStack_40 = &LAB_004183b6;
    uStack_44 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_44;
    puStack_48 = (undefined1 *)0x41814c;
    puStack_3c = &stack0xfffffffc;
    (**(code **)(*param_1 + 0x10))();
    puStack_48 = (undefined1 *)0x41815a;
    FUN_00418a68(param_1,9);
    puStack_48 = (undefined1 *)0x418162;
    iVar1 = FUN_0041cd5c(param_3);
    puStack_48 = (undefined1 *)0x418167;
    FUN_004185e8(iVar1);
    puStack_4c = &LAB_00418391;
    uStack_50 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_50;
    iVar1 = param_2[2] - *param_2;
    hDest = param_2[3] - param_2[1];
    wSrc = param_5[2] - *param_5;
    hSrc = param_5[3] - param_5[1];
    puStack_48 = &stack0xfffffffc;
    uVar2 = FUN_0041ce40(param_3);
    if (uVar2 == param_4) {
      local_28 = (int *)0x0;
      h = (HGDIOBJ)(**(code **)(*param_3 + 100))();
      local_24 = CreateCompatibleDC((HDC)0x0);
      local_2c = SelectObject(local_24,h);
    }
    else {
      local_28 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
      (**(code **)(*local_28 + 8))(local_28,param_3);
      FUN_0041cf24(local_28,param_4);
      piVar3 = (int *)FUN_0041cd5c(local_28);
      FUN_00418a68(piVar3,1);
      iVar5 = FUN_0041cd5c(local_28);
      local_24 = *(HDC *)(iVar5 + 4);
      local_2c = (HGDIOBJ)0x0;
    }
    uVar7 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffa4;
    piVar3 = (int *)FUN_0041cd5c(param_3);
    FUN_00418a68(piVar3,1);
    uVar4 = FUN_00417fb4(param_1[5]);
    if ((char)uVar4 == '\x01') {
      iVar5 = FUN_0041cd5c(param_3);
      FUN_00418f30((HDC)param_1[1],*param_2,param_2[1],param_5[1],*param_5,local_24,hSrc,wSrc,
                   param_5[1],*param_5,*(HDC *)(iVar5 + 4),hDest,iVar1);
    }
    else {
      rop = 0xcc0020;
      iVar5 = param_5[1];
      xSrc = *param_5;
      wSrc_00 = wSrc;
      hSrc_00 = hSrc;
      iVar6 = FUN_0041cd5c(param_3);
      StretchBlt((HDC)param_1[1],*param_2,param_2[1],iVar1,hDest,*(HDC *)(iVar6 + 4),xSrc,iVar5,
                 wSrc_00,hSrc_00,rop);
      color = SetTextColor((HDC)param_1[1],0);
      color_00 = SetBkColor((HDC)param_1[1],0xffffff);
      StretchBlt((HDC)param_1[1],*param_2,param_2[1],iVar1,hDest,local_24,*param_5,param_5[1],wSrc,
                 hSrc,0xe20746);
      SetTextColor((HDC)param_1[1],color);
      SetBkColor((HDC)param_1[1],color_00);
    }
    *in_FS_OFFSET = uVar7;
    if (local_28 == (int *)0x0) {
      if (local_2c != (HGDIOBJ)0x0) {
        SelectObject(local_24,local_2c);
      }
      DeleteDC(local_24);
    }
    else {
      FUN_00402eac(local_28);
    }
    return;
  }
  return;
}

