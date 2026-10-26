/*
 * FUN_0047931c at 0047931c
 * undefined __register FUN_0047931c(void)
 * Address ranges: 0047931c-0047957a;0047959b-0047959f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047931c(void)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_0047957b;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  DAT_0047e594 = FUN_004747b8((int *)&PTR_FUN_00474488,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  DAT_0047e598 = FUN_004739f4((int *)&PTR_FUN_00473640,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  DAT_0047e59c = FUN_0046f55c((int *)&PTR_FUN_0046f11c,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  DAT_0047e5a0 = FUN_00471878((int *)&PTR_FUN_00471504,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  piVar1 = FUN_0046ae90((int *)&PTR_FUN_0046a938,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  *(int **)PTR_DAT_0047c8d0 = piVar1;
  DAT_0047e5a4 = FUN_00475360((int *)&PTR_FUN_00474da4,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  DAT_0047e5a8 = FUN_0045d414((int *)&PTR_FUN_00477e38,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  DAT_0047e5ac = FUN_004768a8((int *)&PTR_FUN_00476418,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  (**(code **)(*DAT_0047e594 + 0xe0))();
  (**(code **)(*DAT_0047e598 + 0xe0))();
  (**(code **)(*DAT_0047e59c + 0xe0))();
  (**(code **)(*DAT_0047e5a0 + 0xe0))();
  (**(code **)(**(int **)PTR_DAT_0047c8d0 + 0xe0))();
  (**(code **)(*DAT_0047e5a4 + 0xe0))();
  (**(code **)(*DAT_0047e5a8 + 0xe0))();
  (**(code **)(*DAT_0047e5ac + 0xe0))();
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX,extraout_ECX);
  FUN_00454f40((int)piVar1,(int)DAT_0047e594);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_00,extraout_ECX_00);
  FUN_00454f40((int)piVar1,(int)DAT_0047e598);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_01,extraout_ECX_01);
  FUN_00454f40((int)piVar1,(int)DAT_0047e59c);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_02,extraout_ECX_02);
  FUN_00454f40((int)piVar1,(int)DAT_0047e5a0);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_03,extraout_ECX_03);
  FUN_00454f40((int)piVar1,*(int *)PTR_DAT_0047c8d0);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_04,extraout_ECX_04);
  FUN_00454f40((int)piVar1,(int)DAT_0047e5a4);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_05,extraout_ECX_05);
  FUN_00454f40((int)piVar1,(int)DAT_0047e5a8);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_06,extraout_ECX_06);
  FUN_00454f40((int)piVar1,(int)DAT_0047e5ac);
  *in_FS_OFFSET = uStack_1c;
  return;
}

