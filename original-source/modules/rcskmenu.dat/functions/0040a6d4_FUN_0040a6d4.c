/*
 * FUN_0040a6d4 at 0040a6d4
 * undefined FUN_0040a6d4(void)
 * Address ranges: 0040a6d4-0040a738
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a6d4(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  char *in_stack_00000004;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  byte *pbStack_8;
  
  puStack_14 = &stack0xfffffffc;
  pbStack_8 = (byte *)0x0;
  puStack_18 = &LAB_0040a739;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  for (iVar2 = 1; *(int *)(iVar2 * 4 + 0x47d5d4) != -1; iVar2 = iVar2 + 1) {
    if (iVar2 == 7) goto LAB_0040a723;
  }
  FUN_00403d08((int *)&pbStack_8,in_stack_00000004);
  uVar1 = FUN_00407fcc(pbStack_8,0,extraout_ECX);
  *(undefined4 *)(iVar2 * 4 + 0x47d5d4) = uVar1;
LAB_0040a723:
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0040a740;
  puStack_18 = (undefined1 *)0x40a738;
  FUN_00403b50((int *)&pbStack_8);
  return;
}

