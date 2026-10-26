/*
 * FUN_004106cc at 004106cc
 * undefined FUN_004106cc(void)
 * Address ranges: 004106cc-00410724;0041072c-00410739
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004106cc(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x4106e3;
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0040e1c8);
  if ((char)uVar1 != '\0') {
    puStack_10 = (undefined1 *)0x4106ef;
    FUN_0041073c(param_1);
    puStack_14 = &LAB_00410725;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    puStack_10 = &stack0xfffffffc;
    (**(code **)(*param_1 + 0x40))();
    (**(code **)(*param_1 + 0x3c))(param_1,param_2);
    *in_FS_OFFSET = uStack_18;
    puStack_10 = (undefined1 *)0x410736;
    puStack_14 = (undefined1 *)0x410724;
    FUN_004107f8(param_1);
    return;
  }
  puStack_10 = (undefined1 *)0x410736;
  FUN_0040fca8(param_1,param_2);
  return;
}

