/*
 * FUN_00452b68 at 00452b68
 * undefined FUN_00452b68(void)
 * Address ranges: 00452b68-00452be7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452b68(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint *puStack_8;
  
  puStack_18 = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  puStack_1c = &LAB_00452be8;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_004528d8);
  if ((char)uVar1 == '\0') {
    FUN_0040fca8(param_1,param_2);
  }
  else {
    iVar2 = FUN_0040303c(param_2,(int)&PTR_FUN_004528d8);
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(iVar2 + 8);
    FUN_00452bf8(iVar2,(int *)&puStack_8);
    FUN_00452c0c((int)param_1,puStack_8);
    (**(code **)(*(int *)param_1[4] + 8))((int *)param_1[4],*(undefined4 *)(iVar2 + 0x10));
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00452bef;
  puStack_1c = (undefined1 *)0x452be7;
  FUN_00403b50((int *)&puStack_8);
  return;
}

