/*
 * FUN_004111b4 at 004111b4
 * undefined __register FUN_004111b4(int * param_1, undefined * param_2, int param_3)
 * Address ranges: 004111b4-0041123d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004111b4(int *param_1,undefined *param_2,int param_3)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  int local_c;
  int local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_c = 0;
  puStack_20 = &LAB_0041123e;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  local_8 = param_3;
  iVar1 = FUN_00410bf8(param_1,param_2);
  if (local_8 == 0) {
    if (-1 < iVar1) {
      (**(code **)(*param_1 + 0x44))(param_1,iVar1);
    }
  }
  else {
    if (iVar1 < 0) {
      iVar1 = (**(code **)(*param_1 + 0x34))(param_1,0);
    }
    puVar3 = &LAB_00411254;
    iVar2 = local_8;
    FUN_00403e90(&local_c,3);
    (**(code **)(*param_1 + 0x20))(param_1,iVar1,local_c,iVar2,puVar3,param_2);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00411245;
  puStack_20 = (undefined1 *)0x41123d;
  FUN_00403b50(&local_c);
  return;
}

