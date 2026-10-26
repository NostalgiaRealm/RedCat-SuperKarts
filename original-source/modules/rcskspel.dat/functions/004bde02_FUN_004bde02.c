/*
 * FUN_004bde02 at 004bde02
 * undefined FUN_004bde02(void)
 * Address ranges: 004bde02-004bde8d;004bde8f-004bde9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bde02(void)

{
  uint uVar1;
  size_t sVar2;
  int extraout_ECX;
  int unaff_EBP;
  char *_Str;
  
  FUN_004c0dec();
  uVar1 = *(uint *)(unaff_EBP + 8) & 7;
  *(uint *)(extraout_ECX + 4) = uVar1;
  uVar1 = *(uint *)(extraout_ECX + 8) & uVar1;
  if (uVar1 == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  if (*(char *)(unaff_EBP + 0xc) != '\0') {
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(0,0);
  }
  if ((uVar1 & 4) == 0) {
    _Str = "ios::failbit set";
    if ((uVar1 & 2) == 0) {
      _Str = "ios::eofbit set";
    }
  }
  else {
    _Str = "ios::badbit set";
  }
  *(undefined1 *)(unaff_EBP + -0x1c) = *(undefined1 *)(unaff_EBP + 0xf);
  FUN_0040b4f0(0);
  sVar2 = _strlen(_Str);
  FUN_0040b540(_Str,sVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004bde9e(unaff_EBP + -0x1c);
  *(undefined ***)(unaff_EBP + -0x38) = &PTR_FUN_004d3664;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x38,&DAT_004db4b8);
}

