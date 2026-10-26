/*
 * FUN_00448d54 at 00448d54
 * undefined FUN_00448d54(void)
 * Address ranges: 00448d54-00448e3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448d54(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int iStack_18;
  int *piStack_14;
  int iStack_10;
  int iStack_c;
  int *piStack_8;
  
  puStack_28 = &stack0xfffffffc;
  iStack_18 = 0;
  puStack_2c = &LAB_00448e8d;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_34 = (undefined1 *)0x448d89;
  iStack_c = param_1;
  piStack_8 = param_2;
  (**(code **)(*param_2 + 8))(param_2,param_1 + 0x70,4);
  puStack_34 = (undefined1 *)0x448d95;
  piStack_14 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX);
  puStack_38 = &LAB_00448e3c;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_34 = &stack0xfffffffc;
  iVar1 = FUN_0044401c(*(int *)(iStack_c + 0x14));
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      iVar2 = FUN_00444030(*(int *)(iStack_c + 0x14),iVar3);
      if ((*(char *)(iVar2 + 0x47) == '\0') && (*(int *)(iVar2 + 8) != 0)) {
        (**(code **)(*piStack_14 + 0x34))(piStack_14,*(undefined4 *)(iVar2 + 8));
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  iStack_10 = (**(code **)(*piStack_14 + 0x14))();
  (**(code **)(*piStack_8 + 8))(piStack_8,&iStack_10,4);
  if (-1 < iStack_10 + -1) {
    iVar3 = 0;
    iVar1 = iStack_10;
    do {
      puVar4 = &stack0xfffffffc;
      (**(code **)(*piStack_14 + 0xc))(piStack_14,iVar3,&iStack_18);
      FUN_00448c20(iStack_18,extraout_EDX,extraout_ECX_00,(int)puVar4);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *in_FS_OFFSET = uStack_3c;
  puStack_34 = &LAB_00448e43;
  puStack_38 = (undefined1 *)0x448e3b;
  FUN_00402eac(piStack_14);
  return;
}

