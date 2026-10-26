/*
 * FUN_004be2cf at 004be2cf
 * undefined FUN_004be2cf(void)
 * Address ranges: 004be2cf-004be340
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004be2cf(void)

{
  undefined1 uVar1;
  size_t sVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 1;
  *extraout_ECX = &PTR_LAB_004d36d4;
  *(undefined1 *)(extraout_ECX + 5) = *(undefined1 *)(unaff_EBP + 8);
  uVar1 = *(undefined1 *)(unaff_EBP + 0xb);
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  *(undefined1 *)(extraout_ECX + 6) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040b4f0(0);
  sVar2 = _strlen("*");
  FUN_0040b540(&DAT_004d36c0,sVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004d36cc;
  return extraout_ECX;
}

