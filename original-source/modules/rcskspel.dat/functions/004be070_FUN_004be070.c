/*
 * FUN_004be070 at 004be070
 * undefined FUN_004be070(void)
 * Address ranges: 004be070-004be0bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be070(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004d36b8;
  iVar1 = extraout_ECX[9];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar1 == 0) ||
     ((&DAT_006b667c)[iVar1] = (&DAT_006b667c)[iVar1] + -1,
     (char)(&DAT_006b667c)[extraout_ECX[9]] < '\x01')) {
    FUN_004be16b();
  }
  std::locale::~locale((locale *)(extraout_ECX + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

