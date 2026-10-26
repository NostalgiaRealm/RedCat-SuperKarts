/*
 * FUN_004bd486 at 004bd486
 * undefined FUN_004bd486(void)
 * Address ranges: 004bd486-004bd4e4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004bd486(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_004d35e0;
    extraout_ECX[0xb] = 0;
    extraout_ECX[2] = (int)&PTR_FUN_004d35d4;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_FUN_004d35c4;
  FUN_004be0fe();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

