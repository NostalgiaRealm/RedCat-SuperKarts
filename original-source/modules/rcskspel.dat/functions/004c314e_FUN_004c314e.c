/*
 * FUN_004c314e at 004c314e
 * undefined FUN_004c314e(void)
 * Address ranges: 004c314e-004c3193
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c314e(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_006b677c = *(undefined4 *)(unaff_EBP + -0x1c);
  DAT_006b6780 = *(undefined4 *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == unaff_EBX && (*(int *)(unaff_EBP + -0x2c) != unaff_EBX)))) {
    __abnormal_termination();
    FUN_004c3382();
  }
  return;
}

