/*
 * FUN_0041e2ec at 0041e2ec
 * undefined FUN_0041e2ec(void)
 * Address ranges: 0041e2ec-0041e37a;0041e392-0041e3a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e2ec(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 auStack_e [2];
  ushort uStack_c;
  int *piStack_8;
  
  puStack_20 = (undefined1 *)0x41e305;
  piStack_8 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',param_3);
  puStack_24 = &LAB_0041e37b;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  iVar1 = FUN_004118b0(param_2);
  iVar2 = FUN_00411894(param_2);
  (**(code **)*piStack_8)(piStack_8,iVar1 - iVar2);
  iVar1 = FUN_004118b0(piStack_8);
  FUN_004118e8(param_2,piStack_8[1],iVar1);
  FUN_004118e8(piStack_8,auStack_e,6);
  if (1 < uStack_c) {
    FUN_00418c78();
  }
  FUN_0041e3a4((int)param_1,0,piStack_8);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = (undefined1 *)0x41e39b;
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

