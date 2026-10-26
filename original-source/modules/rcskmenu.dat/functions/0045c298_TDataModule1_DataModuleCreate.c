/*
 * TDataModule1_DataModuleCreate at 0045c298
 * undefined TDataModule1_DataModuleCreate(void)
 * Address ranges: 0045c298-0045c420;0045c47c-0045c491
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TDataModule1_DataModuleCreate; original record 0005b2a4
 */

/* Named by original Delphi published-method table: TDataModule1_DataModuleCreate; original record
   0005b2a4 */

void TDataModule1_DataModuleCreate(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined1 *puStack_1c;
  int iStack_c;
  int iStack_8;
  
  puStack_1c = &stack0xfffffffc;
  puStack_28 = &stack0xfffffffc;
  iStack_c = 0;
  puStack_20 = &UNK_0045c492;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_2c = &UNK_0045c421;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  iStack_8 = param_1;
  uVar2 = FUN_0045adfc(&PTR_FUN_0045ada4,1);
  *(undefined4 *)(iStack_8 + 0x7c) = uVar2;
  piVar3 = FUN_00459f94((int *)&PTR_FUN_00459f34,'\x01',extraout_ECX);
  *(int **)(iStack_8 + 0x80) = piVar3;
  piVar3 = FUN_0044dbdc((int *)&UNK_00459c20,'\x01',extraout_ECX_00);
  *(int **)(iStack_8 + 0x84) = piVar3;
  uVar2 = FUN_00457484(&UNK_0045728c,1);
  *(undefined4 *)(iStack_8 + 0x9c) = uVar2;
  piVar3 = FUN_00458584((int *)&DAT_00458564,'\x01',extraout_ECX_01);
  *(int **)(iStack_8 + 0x8c) = piVar3;
  piVar3 = FUN_0044dbdc((int *)&UNK_00458c38,'\x01',extraout_ECX_02);
  *(int **)(iStack_8 + 0x88) = piVar3;
  uVar2 = FUN_00458264(&UNK_00458254,1);
  *(undefined4 *)(iStack_8 + 0x90) = uVar2;
  piVar3 = FUN_0044dbdc((int *)&UNK_00457e74,'\x01',extraout_ECX_03);
  *(int **)(iStack_8 + 0x94) = piVar3;
  iVar1 = *(int *)(iStack_8 + 0x90);
  if (iVar1 != 0) {
    FUN_00403e90(&iStack_c,3);
    FUN_004582a0(iVar1,iStack_c);
  }
  if (*(int *)(iStack_8 + 0x88) != 0) {
    FUN_00458d6c(*(int *)(iStack_8 + 0x88));
  }
  uVar2 = FUN_004578ac(&UNK_0045789c,1);
  *(undefined4 *)(iStack_8 + 0x98) = uVar2;
  if (*(int *)(iStack_8 + 0x94) != 0) {
    FUN_00457e84();
  }
  FUN_0045ae70(*(undefined4 *)(iStack_8 + 0x7c));
  FUN_00459c44(*(undefined4 *)(iStack_8 + 0x84));
  uVar2 = extraout_ECX_04;
  if (*(int *)(iStack_8 + 0x9c) != 0) {
    FUN_00457624();
    uVar2 = extraout_ECX_05;
  }
  uVar2 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',uVar2);
  *(undefined4 *)(iStack_8 + 0xa8) = uVar2;
  *in_FS_OFFSET = uStack_30;
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &UNK_0045c499;
  puStack_20 = (undefined *)0x45c491;
  FUN_00403b50(&iStack_c);
  return;
}

