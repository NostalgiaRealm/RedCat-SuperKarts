/*
 * FUN_004bde9e at 004bde9e
 * undefined FUN_004bde9e(void)
 * Address ranges: 004bde9e-004bdf01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004bde9e(void)

{
  undefined1 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined1 **)(unaff_EBP + -0x10) = &DAT_005437b0;
  FUN_004bfdaf(unaff_EBP + -0x10);
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 3) = *puVar1;
  FUN_0040b4f0(0);
  FUN_00412870(puVar1,0,0xffffffff);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004d36a8;
  return extraout_ECX;
}

