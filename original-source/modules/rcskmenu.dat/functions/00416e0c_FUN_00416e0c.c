/*
 * FUN_00416e0c at 00416e0c
 * undefined __register FUN_00416e0c(void)
 * Address ranges: 00416e0c-00416ea8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416e0c(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_8;
  
  local_8 = 0;
  puStack_18 = (undefined1 *)0x416e23;
  puVar1 = (undefined4 *)FUN_0040fa70(DAT_0047d6d4);
  puStack_1c = &LAB_00416ea9;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_18 = &stack0xfffffffc;
  while (local_8 < (int)puVar1[2]) {
    iVar3 = FUN_0040f6b0(puVar1,local_8);
    FUN_004185e8(iVar3);
    local_8 = local_8 + 1;
    FUN_004189b4(iVar3);
  }
  FUN_00416da0(DAT_0047d6cc);
  FUN_00416da0(DAT_0047d6d0);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00416eb0;
  if (-1 < local_8 + -1) {
    iVar3 = 0;
    do {
      puStack_1c = (undefined1 *)0x416e95;
      iVar2 = FUN_0040f6b0(puVar1,iVar3);
      puStack_1c = (undefined1 *)0x416e9a;
      FUN_0041888c(iVar2);
      iVar3 = iVar3 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  puStack_1c = (undefined1 *)0x416ea8;
  FUN_0040fad4(DAT_0047d6d4);
  return;
}

