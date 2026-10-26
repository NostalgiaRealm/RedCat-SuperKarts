/*
 * FUN_004bdfe2 at 004bdfe2
 * undefined FUN_004bdfe2(void)
 * Address ranges: 004bdfe2-004be01e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bdfe2(void)

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

