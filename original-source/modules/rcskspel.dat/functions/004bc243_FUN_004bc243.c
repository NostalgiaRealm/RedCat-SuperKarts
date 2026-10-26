/*
 * FUN_004bc243 at 004bc243
 * undefined FUN_004bc243(void)
 * Address ranges: 004bc243-004bc29b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bc243(void)

{
  size_t sVar1;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0xd);
  FUN_0040b4f0(0);
  sVar1 = _strlen("invalid string position");
  FUN_0040b540("invalid string position",sVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004472d0(unaff_EBP + -0x20);
  *(undefined ***)(unaff_EBP + -0x3c) = &PTR_FUN_004d3504;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x3c,&DAT_004d58b8);
}

