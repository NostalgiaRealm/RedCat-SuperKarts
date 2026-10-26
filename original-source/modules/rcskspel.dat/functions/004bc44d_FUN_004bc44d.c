/*
 * FUN_004bc44d at 004bc44d
 * undefined FUN_004bc44d(void)
 * Address ranges: 004bc44d-004bc5aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bc44d(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  bool bVar2;
  
  FUN_004c0dec();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  bVar2 = DAT_00502640 < 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (bVar2) {
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b63d0;
    DAT_00502640 = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004bc76d(&PTR_DAT_00502b00);
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b62a8;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004bc76d(&DAT_00502b20);
    *(int **)(unaff_EBP + -0x14) = &DAT_006b6390;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_004bc6a6(&DAT_006b63d0,1,1);
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b6300;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_004bc5d2(&DAT_006b62a8,1,1,1);
    iVar1 = DAT_006b6390;
    *(undefined **)(unaff_EBP + -0x14) = &DAT_006b6338;
    *(undefined **)(&DAT_006b63bc + *(int *)(iVar1 + 4)) = &DAT_006b6300;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    FUN_004bc76d(&DAT_00502b40);
    *(int **)(unaff_EBP + -0x14) = &DAT_006b6428;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_004bc5d2(&DAT_006b6338,1,1,1);
    iVar1 = DAT_006b6428;
    *(int **)(unaff_EBP + -0x14) = &DAT_006b6270;
    *(undefined **)(&DAT_006b6454 + *(int *)(iVar1 + 4)) = &DAT_006b6300;
    *(uint *)(&DAT_006b6434 + *(int *)(DAT_006b6428 + 4)) =
         *(uint *)(&DAT_006b6434 + *(int *)(DAT_006b6428 + 4)) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    FUN_004bc5d2(&DAT_006b6338,1,1,1);
    *(undefined **)(&DAT_006b629c + *(int *)(DAT_006b6270 + 4)) = &DAT_006b6300;
  }
  else {
    DAT_00502640 = DAT_00502640 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

