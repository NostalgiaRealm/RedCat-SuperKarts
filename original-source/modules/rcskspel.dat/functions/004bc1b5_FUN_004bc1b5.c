/*
 * FUN_004bc1b5 at 004bc1b5
 * undefined FUN_004bc1b5(void)
 * Address ranges: 004bc1b5-004bc1f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bc1b5(void)

{
  exception *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_004c0dec();
  *(exception **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004d34f4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040b4f0(1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  exception::~exception(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

