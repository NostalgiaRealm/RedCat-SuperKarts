/*
 * FUN_00450024 at 00450024
 * undefined __register FUN_00450024(int * param_1, undefined4 * param_2, int param_3, int param_4)
 * Address ranges: 00450024-004500eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450024(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *piVar1;
  HDC hdcSrc;
  int cx;
  HDC hdc;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  int x;
  int y;
  int x1;
  int y1;
  DWORD rop;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 local_18 [4];
  int *local_8;
  
  puVar3 = local_18;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  puStack_28 = (undefined1 *)0x45004b;
  local_8 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',param_3);
  puStack_2c = &LAB_004500ec;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  (**(code **)(*local_8 + 0x40))(local_8,*(undefined4 *)(param_3 + 0x8c));
  (**(code **)(*local_8 + 0x34))(local_8,*(undefined4 *)(param_3 + 0x40));
  rop = 0xcc0020;
  y1 = 0;
  x1 = 0;
  piVar1 = (int *)FUN_00451e40(param_3,extraout_EDX,extraout_ECX);
  hdcSrc = (HDC)FUN_00418994(piVar1);
  iVar2 = (**(code **)(*local_8 + 0x20))();
  cx = (**(code **)(*local_8 + 0x2c))();
  y = 0;
  x = 0;
  piVar1 = (int *)FUN_0041cd5c(local_8);
  hdc = (HDC)FUN_00418994(piVar1);
  BitBlt(hdc,x,y,cx,iVar2,hdcSrc,x1,y1,rop);
  (**(code **)(*local_8 + 0x3c))(local_8,1);
  FUN_0041dc10(local_8,param_4);
  FUN_004186bc(param_1,local_18,local_8);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_004500f3;
  puStack_2c = (undefined1 *)0x4500eb;
  FUN_00402eac(local_8);
  return;
}

