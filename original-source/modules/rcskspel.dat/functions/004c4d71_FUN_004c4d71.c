/*
 * FUN_004c4d71 at 004c4d71
 * undefined FUN_004c4d71(void)
 * Address ranges: 004c4d71-004c4db5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c4d71(void)

{
  byte extraout_DL;
  byte extraout_DL_00;
  byte bVar1;
  int unaff_EBP;
  float10 fVar2;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 Var3;
  
  *(undefined1 *)(unaff_EBP + -0x90) = 0xfe;
  fVar2 = (float10)FUN_004c4ebe();
  fVar2 = (float10)1 + fVar2;
  bVar1 = extraout_DL;
  Var3 = extraout_ST1;
  if ((*(byte *)(unaff_EBP + -0x9f) & 1) != 0) {
    if (DAT_006b66c0 == 1) {
      fVar2 = (float10)FUN_004c5d21();
      bVar1 = extraout_DL_00;
      Var3 = extraout_ST1_00;
    }
    else {
      fVar2 = (float10)1 / fVar2;
    }
  }
  if ((bVar1 & 0x40) == 0) {
    fscale(fVar2,Var3);
  }
  FUN_004c1eb8();
  return;
}

