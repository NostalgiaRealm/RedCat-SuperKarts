/*
 * FUN_004bc76d at 004bc76d
 * undefined FUN_004bc76d(void)
 * Address ranges: 004bc76d-004bc7cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004bc76d(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004bc7cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_004d358c;
  FUN_004bdd7e();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004bc7cd();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_004d3554;
  FUN_004bceaa(uVar1,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

