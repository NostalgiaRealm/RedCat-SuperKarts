/*
 * FUN_00417d5c at 00417d5c
 * undefined FUN_00417d5c(void)
 * Address ranges: 00417d5c-00417dce;00417df3-00417e02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417d5c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x417d77;
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00416258);
  if ((char)uVar1 != '\0') {
    puStack_14 = (undefined1 *)0x417d83;
    FUN_00417254((int)param_1);
    puStack_18 = &LAB_00417dec;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    puStack_20 = (undefined1 *)0x417d9b;
    puStack_14 = &stack0xfffffffc;
    FUN_00417254((int)param_2);
    puStack_24 = &LAB_00417dcf;
    uStack_28 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_28;
    puStack_20 = &stack0xfffffffc;
    FUN_00416d34(DAT_0047d6d0,param_1,(undefined4 *)param_2[4]);
    *in_FS_OFFSET = uStack_28;
    puStack_20 = &LAB_00417dd6;
    puStack_24 = (undefined1 *)0x417dce;
    FUN_00417264((int)param_2);
    return;
  }
  puStack_14 = (undefined1 *)0x417dfe;
  FUN_0040fca8(param_1,param_2);
  return;
}

