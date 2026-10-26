/*
 * FUN_00480080 at 00480080
 * undefined FUN_00480080(void)
 * Address ranges: 00480080-0048015a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00480080(undefined1 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 local_44 [4];
  int local_40;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [20];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004d1268;
  local_c = ExceptionList;
  local_3c[0] = param_1._0_1_;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_4 = 0;
  local_2c[0] = *param_1;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  FUN_00412870(param_1,0,0xffffffff);
  local_4._0_1_ = 1;
  FUN_0047d0c0(local_3c);
  local_4._0_1_ = 2;
  piVar2 = (int *)FUN_00480160(local_44,local_2c);
  iVar1 = *piVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  local_40 = piVar2[1];
  FUN_004bc150(local_18);
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_0040b4f0(1);
  FUN_004bc150(local_38);
  ExceptionList = local_c;
  return iVar1 + 0x1c;
}

