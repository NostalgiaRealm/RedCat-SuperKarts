/*
 * FUN_0044e8dc at 0044e8dc
 * undefined __register FUN_0044e8dc(int * param_1, int * param_2, int * param_3, undefined4 param_4)
 * Address ranges: 0044e8dc-0044ea2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e8dc(int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  HDC pHVar5;
  int cx;
  HDC hdc;
  undefined4 *in_FS_OFFSET;
  int x;
  int y;
  int x1;
  RECT *pRVar6;
  int y1;
  COLORREF CVar7;
  DWORD rop;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  RECT local_18;
  int *local_8;
  
  puStack_28 = (undefined1 *)0x44e8f7;
  local_8 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',param_3);
  puStack_2c = &LAB_0044ea2b;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  uVar1 = (**(code **)(*param_3 + 0x2c))();
  (**(code **)(*local_8 + 0x40))(local_8,uVar1);
  uVar1 = (**(code **)(*param_3 + 0x20))();
  (**(code **)(*local_8 + 0x34))(local_8,uVar1);
  iVar2 = FUN_0041cd5c(local_8);
  FUN_00417ea0(*(int **)(iVar2 + 0x14),0x808000);
  uVar1 = (**(code **)(*local_8 + 0x20))();
  pRVar6 = &local_18;
  uVar3 = (**(code **)(*local_8 + 0x2c))();
  FUN_0040ebe8(0,0,uVar3,&pRVar6->left,uVar1);
  pRVar6 = &local_18;
  piVar4 = (int *)FUN_0041cd5c(local_8);
  FUN_00418538(piVar4,pRVar6);
  (**(code **)(*local_8 + 0x3c))(local_8,1);
  FUN_0041dc10(local_8,0x808000);
  CVar7 = 0;
  piVar4 = (int *)FUN_0041cd5c(local_8);
  pHVar5 = (HDC)FUN_00418994(piVar4);
  SetTextColor(pHVar5,CVar7);
  CVar7 = 0xffffff;
  piVar4 = (int *)FUN_0041cd5c(local_8);
  pHVar5 = (HDC)FUN_00418994(piVar4);
  SetBkColor(pHVar5,CVar7);
  iVar2 = FUN_0041cd5c(local_8);
  FUN_00417ea0(*(int **)(iVar2 + 0x14),param_4);
  rop = 0xe20746;
  y1 = 0;
  x1 = 0;
  piVar4 = (int *)FUN_0041cd5c(param_3);
  pHVar5 = (HDC)FUN_00418994(piVar4);
  iVar2 = (**(code **)(*param_3 + 0x20))();
  cx = (**(code **)(*param_3 + 0x2c))();
  y = 0;
  x = 0;
  piVar4 = (int *)FUN_0041cd5c(local_8);
  hdc = (HDC)FUN_00418994(piVar4);
  BitBlt(hdc,x,y,cx,iVar2,pHVar5,x1,y1,rop);
  FUN_00418458(param_1,*param_2,param_2[1],local_8);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_0044ea32;
  puStack_2c = (undefined1 *)0x44ea2a;
  FUN_00402eac(local_8);
  return;
}

