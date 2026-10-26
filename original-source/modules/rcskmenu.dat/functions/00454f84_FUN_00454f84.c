/*
 * FUN_00454f84 at 00454f84
 * undefined __register FUN_00454f84(int param_1, byte * param_2)
 * Address ranges: 00454f84-00455016
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454f84(int param_1,byte *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar4;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  uint *local_14;
  uint *local_10;
  int local_c;
  byte *local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  puStack_28 = &LAB_00455017;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  local_c = 0;
  iVar2 = local_c;
  local_8 = param_2;
  if (*(int *)(param_1 + 4) != 0) {
    for (iVar3 = 0; iVar2 = local_c, iVar3 < (int)(*(undefined4 **)(param_1 + 4))[2];
        iVar3 = iVar3 + 1) {
      iVar2 = FUN_0040f6b0(*(undefined4 **)(param_1 + 4),iVar3);
      uVar4 = iVar2 == 0;
      if (!(bool)uVar4) {
        FUN_00407ca8(*(byte **)(iVar2 + 0x2d0),(int *)&local_10);
        puVar1 = local_10;
        FUN_00407ca8(local_8,(int *)&local_14);
        FUN_00403ee0(puVar1,local_14);
        if ((bool)uVar4) break;
      }
    }
  }
  local_c = iVar2;
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_0045501e;
  puStack_28 = (undefined1 *)0x455016;
  FUN_00403b74((int *)&local_14,2);
  return;
}

