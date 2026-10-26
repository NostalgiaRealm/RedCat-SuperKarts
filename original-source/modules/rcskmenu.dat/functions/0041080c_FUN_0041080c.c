/*
 * FUN_0041080c at 0041080c
 * undefined __register FUN_0041080c(int * param_1, int * param_2)
 * Address ranges: 0041080c-004108a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041080c(int *param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar4;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  uint *local_18;
  uint *local_14;
  undefined1 local_d;
  int *local_c;
  int *local_8;
  
  puStack_28 = &stack0xfffffffc;
  local_14 = (uint *)0x0;
  local_18 = (uint *)0x0;
  puStack_2c = &LAB_004108a1;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  local_d = 0;
  local_c = param_2;
  local_8 = param_1;
  iVar2 = (**(code **)(*param_1 + 0x14))();
  iVar3 = (**(code **)(*local_c + 0x14))();
  if (iVar2 == iVar3) {
    if (-1 < iVar2 + -1) {
      iVar3 = 0;
      uVar4 = true;
      do {
        (**(code **)(*local_8 + 0xc))(local_8,iVar3,&local_14);
        puVar1 = local_14;
        (**(code **)(*local_c + 0xc))(local_c,iVar3,&local_18);
        FUN_00403ee0(puVar1,local_18);
        if (!(bool)uVar4) goto LAB_00410886;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + -1;
        uVar4 = iVar2 == 0;
      } while (!(bool)uVar4);
    }
    local_d = 1;
  }
LAB_00410886:
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_004108a8;
  puStack_2c = (undefined1 *)0x4108a0;
  FUN_00403b74((int *)&local_18,2);
  return;
}

