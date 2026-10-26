/*
 * FUN_00446b3c at 00446b3c
 * undefined FUN_00446b3c(void)
 * Address ranges: 00446b3c-00446bc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446b3c(int *param_1)

{
  LONG LVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined *puStack_c;
  undefined *puStack_8;
  
  puStack_14 = &stack0xfffffffc;
  puStack_8 = (undefined *)0x0;
  puStack_c = (undefined *)0x0;
  puStack_18 = &LAB_00446bc7;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  (**(code **)(*param_1 + -0x10))();
  if ((char)param_1[0x7e] == '\0') {
    FUN_0043f64c((int)param_1,(int *)&puStack_8);
    LVar1 = FUN_004187f4((int *)param_1[0x7c],puStack_8);
    FUN_0043eeb0(param_1,LVar1 + 6);
    FUN_0043f64c((int)param_1,(int *)&puStack_c);
    LVar1 = FUN_00418810((int *)param_1[0x7c],puStack_c);
    FUN_0043eed0(param_1,LVar1 + 4);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00446bce;
  puStack_18 = (undefined1 *)0x446bc6;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

