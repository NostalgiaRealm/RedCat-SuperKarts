/*
 * FUN_004bd172 at 004bd172
 * undefined FUN_004bd172(void)
 * Address ranges: 004bd172-004bd2d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bd172(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  bool bVar2;
  
  FUN_004c0dec();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  bVar2 = DAT_0050279c < 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (bVar2) {
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b6570;
    DAT_0050279c = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004bd4e5(&PTR_DAT_00502b00);
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b6518;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004bd4e5(&DAT_00502b20);
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b6600;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_004bd4e5(&DAT_00502b40);
    *(int **)(unaff_EBP + -0x14) = &DAT_006b64d8;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_004bd41e(&DAT_006b6570,1,1);
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b65c8;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    FUN_004bd300(&DAT_006b6518,1,1,1);
    iVar1 = DAT_006b64d8;
    *(int **)(unaff_EBP + -0x14) = &DAT_006b6460;
    *(undefined **)(&DAT_006b6504 + *(int *)(iVar1 + 4)) = &DAT_006b65c8;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_004bd300(&DAT_006b6600,1,1,1);
    iVar1 = DAT_006b6460;
    *(int **)(unaff_EBP + -0x14) = &DAT_006b64a0;
    *(undefined **)(&DAT_006b648c + *(int *)(iVar1 + 4)) = &DAT_006b65c8;
    *(uint *)(&DAT_006b646c + *(int *)(DAT_006b6460 + 4)) =
         *(uint *)(&DAT_006b646c + *(int *)(DAT_006b6460 + 4)) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    FUN_004bd300(&DAT_006b6600,1,1,1);
    *(undefined **)(&DAT_006b64cc + *(int *)(DAT_006b64a0 + 4)) = &DAT_006b65c8;
  }
  else {
    DAT_0050279c = DAT_0050279c + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

