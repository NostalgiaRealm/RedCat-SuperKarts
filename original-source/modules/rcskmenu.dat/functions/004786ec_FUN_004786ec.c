/*
 * FUN_004786ec at 004786ec
 * undefined __register FUN_004786ec(int param_1)
 * Address ranges: 004786ec-00478762;0047876d-00478788
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004786ec(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 local_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  iVar1 = *(int *)(*(int *)PTR_DAT_0047c670 + 0x80);
  *(undefined1 *)(iVar1 + 0x24) = *(undefined1 *)(param_1 + 0x391);
  puVar2 = PTR_DAT_0047c670;
  *(undefined1 *)(iVar1 + 0x25) = *(undefined1 *)(param_1 + 0x390);
  puStack_1c = &LAB_00478789;
  local_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_20;
  puStack_28 = &LAB_00478763;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  piVar3 = FUN_0044dbdc((int *)&LAB_0046e730,'\x01',puVar2);
  FUN_0046e9bc((int)piVar3,*(byte *)(param_1 + 0x390));
  *in_FS_OFFSET = uStack_2c;
  *in_FS_OFFSET = local_20;
  puStack_18 = &LAB_00478790;
  if (piVar3 != (int *)0x0) {
    puStack_1c = (undefined1 *)0x478788;
    FUN_00402eac(piVar3);
  }
  return;
}

