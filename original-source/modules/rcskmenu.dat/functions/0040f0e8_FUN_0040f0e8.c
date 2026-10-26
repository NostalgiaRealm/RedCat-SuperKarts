/*
 * FUN_0040f0e8 at 0040f0e8
 * undefined4 __register FUN_0040f0e8(int param_1)
 * Address ranges: 0040f0e8-0040f157;0040f15f-0040f168
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040f0e8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x40f103;
  puVar1 = (undefined4 *)FUN_0040fa70(DAT_0047d62c);
  puStack_20 = &LAB_0040f158;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  iVar4 = puVar1[2];
  if (-1 < iVar4 + -1) {
    iVar5 = 0;
    puStack_1c = &stack0xfffffffc;
    do {
      iVar2 = FUN_0040f6b0(puVar1,iVar5);
      if (*(int *)(iVar2 + 4) == param_1) {
        uVar3 = *(undefined4 *)(iVar2 + 8);
        FUN_004036a4();
        return uVar3;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = (undefined1 *)0x40f15f;
  puStack_20 = (undefined1 *)0x40f157;
  uVar3 = FUN_0040fad4(DAT_0047d62c);
  return uVar3;
}

