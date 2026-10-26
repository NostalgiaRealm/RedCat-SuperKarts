/*
 * FUN_0042ef80 at 0042ef80
 * undefined FUN_0042ef80(void)
 * Address ranges: 0042ef80-0042efef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ef80(void)

{
  byte *pbVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00430630(DAT_0047d774,0);
  FUN_004293e8(*(undefined4 **)(unaff_EBP + -0xc));
  if ((int)(*(undefined4 **)(DAT_0047d774 + 0x70))[2] < 1) {
    *(undefined4 *)(DAT_0047d774 + 0x6c) = 0;
  }
  else {
    iVar2 = FUN_0040f6a8(*(undefined4 **)(DAT_0047d774 + 0x70));
    *(int *)(DAT_0047d774 + 0x6c) = iVar2;
    FUN_0040f848(*(int **)(DAT_0047d774 + 0x70),iVar2);
  }
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    SetActiveWindow(*(HWND *)(unaff_EBP + -0x1c));
  }
  DAT_0047b6b8 = *(undefined4 *)(unaff_EBP + -0x10);
  pbVar1 = (byte *)(*(int *)(unaff_EBP + -4) + 0x2cc);
  *pbVar1 = *pbVar1 & 0xf7;
  return;
}

