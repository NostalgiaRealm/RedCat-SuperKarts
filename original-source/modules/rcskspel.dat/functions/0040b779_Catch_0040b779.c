/*
 * Catch@0040b779 at 0040b779
 * undefined Catch@0040b779(void)
 * Address ranges: 0040b779-0040b799
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * Catch_0040b779(void)

{
  uint uVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8);
  uVar1 = *(int *)(unaff_EBP + 8) + 2;
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  pvVar2 = operator_new(uVar1);
  *(void **)(unaff_EBP + 8) = pvVar2;
  return &DAT_0040b79a;
}

