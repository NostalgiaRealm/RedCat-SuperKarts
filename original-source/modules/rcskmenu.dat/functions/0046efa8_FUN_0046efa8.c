/*
 * FUN_0046efa8 at 0046efa8
 * undefined __register FUN_0046efa8(int param_1, uint param_2, int param_3)
 * Address ranges: 0046efa8-0046f050
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046efa8(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar2;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_10;
  uint *local_c;
  int local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  puStack_24 = &LAB_0046f051;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_8 = param_3;
  FUN_00407ca8(*(byte **)(PTR_PTR_0047c804 + (param_2 & 0xff) * 4),(int *)&local_c);
  iVar1 = 0;
  uVar2 = true;
  do {
    FUN_00407ca8(*(byte **)(param_1 + 0xc + iVar1 * 0x14),(int *)&local_10);
    FUN_00403ee0(local_10,local_c);
    if ((bool)uVar2) {
      FUN_00403ba4((int *)(local_8 + 4),*(undefined4 **)(param_1 + 8 + iVar1 * 0x14));
      FUN_00403ba4((int *)(local_8 + 8),*(undefined4 **)(param_1 + 0xc + iVar1 * 0x14));
      *(undefined4 *)(local_8 + 0xc) = *(undefined4 *)(param_1 + 0x10 + iVar1 * 0x14);
      *(undefined4 *)(local_8 + 0x10) = *(undefined4 *)(param_1 + 0x14 + iVar1 * 0x14);
      break;
    }
    iVar1 = iVar1 + 1;
    uVar2 = iVar1 == 10;
  } while (!(bool)uVar2);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0046f058;
  puStack_24 = (undefined1 *)0x46f050;
  FUN_00403b74((int *)&local_10,2);
  return;
}

