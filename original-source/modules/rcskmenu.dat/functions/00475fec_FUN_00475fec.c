/*
 * FUN_00475fec at 00475fec
 * undefined FUN_00475fec(void)
 * Address ranges: 00475fec-004760b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475fec(int param_1)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined1 *puStack_14;
  undefined4 *puStack_8;
  
  puStack_14 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_18 = &UNK_004760b3;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  iVar1 = *(int *)(param_1 + 0x3a4);
  if (iVar1 != -1) {
    bVar2 = FUN_00475c50(param_1,iVar1);
    FUN_0045c518(bVar2,0x1a,0);
    FUN_0045c4c8(0x30,(int *)&puStack_8);
    cVar3 = FUN_00460d08(puStack_8);
    if (cVar3 == '\x01') {
      FUN_00457cd0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar1);
      uVar4 = FUN_004578f0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
      *(undefined4 *)(param_1 + 0x3a4) = uVar4;
      FUN_0045aa5c(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
      FUN_0045aa5c(*(int *)(param_1 + 0x3a8));
      *(undefined4 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x14) =
           *(undefined4 *)(param_1 + 0x3a4);
      FUN_00475ab4(param_1);
    }
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &UNK_004760ba;
  puStack_18 = (undefined *)0x4760b2;
  FUN_00403b50((int *)&puStack_8);
  return;
}

