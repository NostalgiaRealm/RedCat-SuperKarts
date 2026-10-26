/*
 * FUN_00467538 at 00467538
 * undefined __register FUN_00467538(int * param_1, int param_2)
 * Address ranges: 00467538-00467594
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467538(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  int iVar3;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = 0;
  puStack_18 = &LAB_00467595;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  iVar3 = param_2;
  FUN_0043f64c(param_2,&local_8);
  iVar1 = local_8;
  iVar2 = FUN_00466cc0(param_2);
  FUN_00410cf0((int *)param_1[0x84],iVar2,iVar1,iVar3);
  (**(code **)(*param_1 + 0xc0))();
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0046759c;
  puStack_18 = (undefined1 *)0x467594;
  FUN_00403b50(&local_8);
  return;
}

