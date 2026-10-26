/*
 * FUN_004bc15b at 004bc15b
 * undefined FUN_004bc15b(void)
 * Address ranges: 004bc15b-004bc1b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bc15b(void)

{
  size_t sVar1;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0xd);
  FUN_0040b4f0(0);
  sVar1 = _strlen("string too long");
  FUN_0040b540("string too long",sVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004472d0(unaff_EBP + -0x20);
  *(undefined ***)(unaff_EBP + -0x3c) = &PTR_FUN_004d34d4;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x3c,&DAT_004db120);
}

