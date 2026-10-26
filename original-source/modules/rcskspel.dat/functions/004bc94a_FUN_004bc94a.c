/*
 * FUN_004bc94a at 004bc94a
 * undefined FUN_004bc94a(void)
 * Address ranges: 004bc94a-004bc9ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bc94a(void)

{
  char cVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004d3554;
  cVar1 = *(char *)(extraout_ECX + 0x12);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (cVar1 != '\0') {
    FUN_004bce83();
  }
  iVar2 = extraout_ECX[0x11];
  if (iVar2 != 0) {
    FUN_0040b4f0(1);
    FUN_004bc150(iVar2);
  }
  std::locale::~locale((locale *)(extraout_ECX + 0x13));
  *extraout_ECX = &PTR_FUN_004d358c;
  std::locale::~locale((locale *)(extraout_ECX + 0xd));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

