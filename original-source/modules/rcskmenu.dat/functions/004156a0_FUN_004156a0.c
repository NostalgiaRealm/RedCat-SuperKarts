/*
 * FUN_004156a0 at 004156a0
 * undefined __register FUN_004156a0(void)
 * Address ranges: 004156a0-004156f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004156a0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x4156b0;
  puVar1 = (undefined4 *)FUN_0040fa70(DAT_0047d62c);
  puStack_18 = &LAB_004156f5;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  iVar3 = puVar1[2];
  if (-1 < iVar3 + -1) {
    iVar4 = 0;
    puStack_14 = &stack0xfffffffc;
    do {
      piVar2 = (int *)FUN_0040f6b0(puVar1,iVar4);
      FUN_00402eac(piVar2);
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004156fc;
  puStack_18 = (undefined1 *)0x4156f4;
  FUN_0040fad4(DAT_0047d62c);
  return;
}

