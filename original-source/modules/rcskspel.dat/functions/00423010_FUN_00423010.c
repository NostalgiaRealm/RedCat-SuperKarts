/*
 * FUN_00423010 at 00423010
 * undefined FUN_00423010(void)
 * Address ranges: 00423010-004231b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423010(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((DAT_0053b9f0 != 0) && (DAT_00509154 != 0)) {
    iVar1 = DAT_006a5c38 + DAT_0050914c * 0xa9;
    *(undefined4 *)(iVar1 + 0x80) = DAT_00509140;
    *(undefined4 *)(iVar1 + 0x84) = DAT_00509144;
    *(undefined4 *)(iVar1 + 0x88) = DAT_00509148;
    iVar1 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38;
    iVar2 = DAT_006a5c38 + DAT_0050914c * 0xa9;
    *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar1 + 0x50);
    *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar1 + 0x58);
    puVar3 = &DAT_006a5c90;
    puVar4 = (undefined4 *)(DAT_006a5c38 + DAT_0050914c * 0xa9 + 0x10);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + DAT_0050914c * 0xa8 + 0x40) =
         *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + 0x50 + DAT_0050914c * 0xa8);
    *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + DAT_0050914c * 0xa8 + 0x44) =
         *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + 0x54 + DAT_0050914c * 0xa8);
    *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + DAT_0050914c * 0xa8 + 0x48) =
         *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + 0x58 + DAT_0050914c * 0xa8);
    iVar1 = DAT_006a5c38 + DAT_0050914c * 0xa9;
    FUN_004a26b0(iVar1 + 0x10,*(undefined4 *)(iVar1 + 0x80),*(undefined4 *)(iVar1 + 0x84),
                 *(undefined4 *)(iVar1 + 0x88));
    FUN_004a0d80();
  }
  return;
}

