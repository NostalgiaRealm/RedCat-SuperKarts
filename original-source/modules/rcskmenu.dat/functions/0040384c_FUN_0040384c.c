/*
 * FUN_0040384c at 0040384c
 * undefined __register FUN_0040384c(void)
 * Address ranges: 0040384c-00403891;004038a6-004038aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040384c(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  iVar3 = DAT_0047d4b0;
  puStack_14 = &stack0xfffffffc;
  if (DAT_0047d4ac != 0) {
    iVar1 = *(int *)(DAT_0047d4ac + 4);
    puStack_18 = &LAB_00403892;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    while (0 < iVar3) {
      iVar3 = iVar3 + -1;
      pcVar2 = *(code **)(iVar1 + 4 + iVar3 * 8);
      DAT_0047d4b0 = iVar3;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)();
      }
    }
    *in_FS_OFFSET = uStack_1c;
  }
  return;
}

