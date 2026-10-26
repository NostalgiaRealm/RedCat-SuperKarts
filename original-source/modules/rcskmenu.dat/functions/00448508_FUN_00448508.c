/*
 * FUN_00448508 at 00448508
 * undefined FUN_00448508(void)
 * Address ranges: 00448508-00448623
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448508(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
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
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int *piStack_8;
  
  puStack_30 = (undefined1 *)0x448521;
  piStack_8 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',param_3);
  puStack_34 = &LAB_0044865e;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_3c = (undefined1 *)0x44853d;
  puStack_30 = &stack0xfffffffc;
  FUN_0043e3e0(piStack_8,param_1[5]);
  puStack_3c = (undefined1 *)0x448545;
  FUN_004185e8((int)piStack_8);
  puStack_40 = &LAB_00448641;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  puStack_48 = (undefined1 *)0x44855d;
  puStack_3c = &stack0xfffffffc;
  FUN_00418a14(piStack_8,param_2);
  puStack_4c = &LAB_00448624;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  puStack_48 = &stack0xfffffffc;
  iVar1 = FUN_0044268c(param_1[5]);
  if (-1 < iVar1 + -1) {
    iStack_c = 0;
    iStack_10 = iVar1;
    do {
      iVar1 = FUN_00442650(param_1[5],iStack_c);
      if ((*(char *)(iVar1 + 0x47) != '\0') && (*(int *)(iVar1 + 0x90) == param_1[5])) {
        FUN_0043f054(iVar1,&iStack_20);
        (**(code **)*param_1)(param_1,iVar1,&iStack_20);
        iStack_20 = *(int *)(iVar1 + 0x30) * 2 - iStack_20;
        iStack_1c = *(int *)(iVar1 + 0x34) * 2 - iStack_1c;
        iStack_18 = *(int *)(iVar1 + 0x38) * -2 + iStack_18 * 3 + iStack_20 * -2;
        iStack_14 = *(int *)(iVar1 + 0x3c) * -2 + iStack_14 * 3 + iStack_1c * -2;
        (**(code **)(*param_1 + 0x10))(param_1,piStack_8,iVar1,&iStack_20);
      }
      iStack_c = iStack_c + 1;
      iStack_10 = iStack_10 + -1;
    } while (iStack_10 != 0);
  }
  *in_FS_OFFSET = uStack_50;
  puStack_48 = &LAB_0044862b;
  puStack_4c = (undefined1 *)0x448623;
  FUN_00418a14(piStack_8,0);
  return;
}

