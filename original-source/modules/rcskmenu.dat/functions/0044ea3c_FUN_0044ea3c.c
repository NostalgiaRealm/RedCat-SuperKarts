/*
 * FUN_0044ea3c at 0044ea3c
 * undefined __register FUN_0044ea3c(int * param_1)
 * Address ranges: 0044ea3c-0044ec0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044ea3c(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  HPALETTE pHVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 *in_FS_OFFSET;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  int local_24 [2];
  RECT local_1c;
  int *local_c;
  int *local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    FUN_00403b34("CreateDisabledMask: The source bitmap must be transparent");
  }
  uVar2 = (**(code **)(*param_1 + 0x2c))();
  uVar3 = (**(code **)(*param_1 + 0x20))();
  uStack_3c = 0x44ea88;
  FUN_0040ebe8(0,0,uVar2,&local_1c.left,uVar3);
  local_8 = (int *)0x0;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_40 = (undefined1 *)0x44eaa7;
  local_8 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
  puStack_40 = (undefined1 *)0x44eab4;
  (**(code **)(*local_8 + 0x40))(local_8,uVar2);
  puStack_40 = (undefined1 *)0x44eabe;
  (**(code **)(*local_8 + 0x34))(local_8,uVar3);
  puStack_40 = (undefined1 *)0x44eac5;
  pHVar4 = (HPALETTE)(**(code **)(*param_1 + 0x24))();
  puStack_40 = (undefined1 *)0x44eaca;
  pHVar4 = FUN_0041c580(pHVar4);
  puStack_40 = (undefined1 *)0x44ead4;
  (**(code **)(*local_8 + 0x38))(local_8,pHVar4);
  local_c = (int *)0x0;
  puStack_44 = &LAB_0044ec0b;
  puStack_48 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_48;
  puStack_40 = &stack0xfffffffc;
  local_c = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_00);
  (**(code **)(*local_c + 8))(local_c,param_1);
  (**(code **)(*local_c + 0x68))(local_c,1);
  iVar5 = FUN_0041cd5c(local_c);
  FUN_00417ea0(*(int **)(iVar5 + 0x14),0);
  (**(code **)(*local_c + 0x40))(local_c,uVar2);
  uVar2 = FUN_0041ce10((int)local_c);
  if ((char)uVar2 != '\0') {
    iVar5 = FUN_0041cd5c(local_c);
    FUN_004176d0(*(int **)(iVar5 + 0xc),0xffffff,extraout_ECX_01);
    FUN_0041dabc(local_c,0);
    iVar5 = FUN_0041cd5c(local_c);
    FUN_00417ea0(*(int **)(iVar5 + 0x14),0xffffff);
  }
  FUN_0041dabc(local_c,1);
  (**(code **)(*local_8 + 0x3c))(local_8,1);
  uVar6 = FUN_0041ce40(param_1);
  iVar5 = FUN_0041cd5c(local_8);
  FUN_00417ea0(*(int **)(iVar5 + 0x14),uVar6);
  piVar7 = (int *)FUN_0041cd5c(local_8);
  FUN_00418538(piVar7,&local_1c);
  uVar2 = 0xffffff;
  FUN_0040ebd0(1,1,local_24);
  piVar7 = local_24;
  piVar8 = (int *)FUN_0041cd5c(local_8);
  FUN_0044e8dc(piVar8,piVar7,local_c,uVar2);
  uVar2 = 0x808080;
  FUN_0040ebd0(0,0,local_24);
  piVar7 = (int *)FUN_0041cd5c(local_8);
  FUN_0044e8dc(piVar7,local_24,local_c,uVar2);
  *in_FS_OFFSET = uVar2;
  puStack_48 = &LAB_0044ec12;
  FUN_00402eac(local_c);
  return;
}

