/*
 * FUN_004bdf2c at 004bdf2c
 * undefined FUN_004bdf2c(void)
 * Address ranges: 004bdf2c-004bdf68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bdf2c(void)

{
  exception *this;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(exception **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004d36a8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040b4f0(1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  exception::~exception(this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

