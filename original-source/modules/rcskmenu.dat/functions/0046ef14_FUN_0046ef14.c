/*
 * FUN_0046ef14 at 0046ef14
 * undefined __register FUN_0046ef14(int param_1)
 * Address ranges: 0046ef14-0046ef97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046ef14(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar3;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *local_c;
  uint *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  puStack_20 = &LAB_0046ef98;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  iVar2 = 0;
  uVar3 = true;
  do {
    FUN_00407ca8(*(byte **)(param_1 + 8 + iVar2 * 0x14),(int *)&local_8);
    puVar1 = local_8;
    FUN_00407ca8(*(byte **)(PTR_PTR_0047c5e0 +
                           (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22) * 4),
                 (int *)&local_c);
    FUN_00403ee0(puVar1,local_c);
    if ((bool)uVar3) break;
    iVar2 = iVar2 + 1;
    uVar3 = iVar2 == 10;
  } while (!(bool)uVar3);
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0046ef9f;
  puStack_20 = (undefined1 *)0x46ef97;
  FUN_00403b74((int *)&local_c,2);
  return;
}

