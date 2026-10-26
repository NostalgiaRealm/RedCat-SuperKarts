/*
 * FUN_00410b78 at 00410b78
 * undefined __register FUN_00410b78(int * param_1, undefined * param_2)
 * Address ranges: 00410b78-00410be4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410b78(int *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined *local_10;
  undefined *local_c;
  int *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_10 = (undefined *)0x0;
  puStack_24 = &LAB_00410be5;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_c = param_2;
  local_8 = param_1;
  iVar1 = (**(code **)(*param_1 + 0x14))();
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      (**(code **)(*local_8 + 0xc))(local_8,iVar3,&local_10);
      iVar2 = FUN_00407db0(local_10,local_c);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00410bec;
  puStack_24 = (undefined1 *)0x410be4;
  FUN_00403b50((int *)&local_10);
  return;
}

