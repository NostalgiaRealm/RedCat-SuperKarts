/*
 * FUN_00441354 at 00441354
 * undefined __register FUN_00441354(int * param_1, int * param_2)
 * Address ranges: 00441354-004413ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441354(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  puStack_1c = &LAB_004413ed;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0042618c);
  if ((char)uVar1 == '\0') {
    FUN_0040fd8c(param_1,param_2);
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x4c))();
    FUN_00426a80(param_2,uVar1);
    FUN_00426b30(param_2,(uint *)param_1[0x1c]);
    FUN_0043f64c((int)param_1,(int *)&local_8);
    FUN_004269c0(param_2,local_8);
    FUN_00426c4c(param_2,CONCAT31((int3)((uint)extraout_EDX >> 8),
                                  *(undefined1 *)((int)param_1 + 0x47)));
    (**(code **)(*param_2 + 0x34))();
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_004413f4;
  puStack_1c = (undefined1 *)0x4413ec;
  FUN_00403b50((int *)&local_8);
  return;
}

