/*
 * FUN_0044fda0 at 0044fda0
 * undefined FUN_0044fda0(void)
 * Address ranges: 0044fda0-0044fe74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044fda0(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int *piStack_14;
  int *piStack_10;
  undefined4 uStack_c;
  int *piStack_8;
  
  puStack_30 = &stack0xfffffffc;
  uStack_18 = 0;
  puStack_20 = (undefined *)0x0;
  uStack_1c = 0;
  puStack_34 = &LAB_0044feb4;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_3c = (undefined1 *)0x44fdd7;
  piStack_10 = param_3;
  uStack_c = param_2;
  piStack_8 = param_1;
  piStack_14 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',param_3);
  puStack_40 = &LAB_0044fe92;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  puStack_48 = (undefined1 *)0x44fdf6;
  puStack_3c = &stack0xfffffffc;
  (**(code **)(*piStack_8 + 0x38))(piStack_8,uStack_c,piStack_14);
  puStack_48 = (undefined1 *)0x44fdfe;
  FUN_0041073c(piStack_10);
  puStack_4c = &LAB_0044fe75;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  puStack_48 = &stack0xfffffffc;
  iVar1 = (**(code **)(*piStack_14 + 0x14))();
  if (-1 < iVar1 + -1) {
    iVar2 = 0;
    do {
      (**(code **)(*piStack_14 + 0xc))(piStack_14,iVar2,&uStack_1c,&uStack_18);
      (**(code **)*piStack_8)(piStack_8,uStack_c,uStack_1c);
      (**(code **)(*piStack_14 + 0xc))(piStack_14,iVar2,&puStack_20,uStack_18);
      FUN_004111b4(piStack_10,puStack_20,0);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *in_FS_OFFSET = uStack_50;
  puStack_48 = &LAB_0044fe7c;
  puStack_4c = (undefined1 *)0x44fe74;
  FUN_004107f8(piStack_10);
  return;
}

