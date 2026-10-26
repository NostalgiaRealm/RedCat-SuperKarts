/*
 * FUN_00423d4f at 00423d4f
 * undefined __stdcall FUN_00423d4f(void)
 * Address ranges: 00423d4f-00423d94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423d4f(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_0043e458 = *(undefined4 *)(unaff_EBP + -0x1c);
  DAT_0043e45c = *(undefined4 *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == unaff_EBX && (*(int *)(unaff_EBP + -0x2c) != unaff_EBX)))) {
    __abnormal_termination();
    FUN_00423f83((int)unaff_EDI);
  }
  return;
}

