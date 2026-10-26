/*
 * FUN_0046b8dc at 0046b8dc
 * undefined __register FUN_0046b8dc(undefined4 param_1, int param_2, undefined4 param_3)
 * Address ranges: 0046b8dc-0046b980
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046b8dc(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined *local_18;
  int local_14;
  undefined4 *local_10;
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = 0;
  local_18 = (undefined *)0x0;
  puStack_20 = (undefined1 *)0x46b8f7;
  local_8 = param_2;
  FUN_00403f84(param_2);
  puStack_24 = &LAB_0046b9ab;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_30 = &LAB_0046b981;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_2c = &stack0xfffffffc;
  puStack_20 = &stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
  FUN_004081c4(local_18,&local_14);
  puVar2 = &DAT_0046b9c0;
  pcVar1 = "shellimg.dat";
  iVar3 = local_14;
  FUN_00403e90((int *)&local_10,3);
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  (**(code **)*local_c)(local_c,"RESPICS",local_8,param_3,0,pcVar1,puVar2,iVar3);
  *in_FS_OFFSET = param_3;
  FUN_00402eac(local_c);
  return;
}

