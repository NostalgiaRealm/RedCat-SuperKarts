/*
 * FUN_004038ac at 004038ac
 * undefined __register FUN_004038ac(void)
 * Address ranges: 004038ac-004038f1;00403906-0040390a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004038ac(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  if (DAT_0047d4ac != (int *)0x0) {
    iVar1 = *DAT_0047d4ac;
    iVar4 = 0;
    iVar2 = DAT_0047d4ac[1];
    puStack_18 = &LAB_004038f2;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    if (0 < iVar1) {
      do {
        pcVar3 = *(code **)(iVar2 + iVar4 * 8);
        iVar4 = iVar4 + 1;
        DAT_0047d4b0 = iVar4;
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)();
        }
      } while (iVar4 < iVar1);
    }
    *in_FS_OFFSET = uStack_1c;
  }
  return;
}

