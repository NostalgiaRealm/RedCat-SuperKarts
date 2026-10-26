/*
 * FUN_004bdf85 at 004bdf85
 * undefined FUN_004bdf85(void)
 * Address ranges: 004bdf85-004bdfe1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004bdf85(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004bfdec(iVar2);
  uVar1 = *(undefined1 *)(iVar2 + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 3) = uVar1;
  FUN_0040b4f0(0);
  FUN_00412870(iVar2 + 0xc,0,0xffffffff);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004d36a8;
  return extraout_ECX;
}

