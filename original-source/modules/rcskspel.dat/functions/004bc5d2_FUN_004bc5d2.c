/*
 * FUN_004bc5d2 at 004bc5d2
 * undefined FUN_004bc5d2(void)
 * Address ranges: 004bc5d2-004bc63b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004bc5d2(void)

{
  char cVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *extraout_ECX = (int)&DAT_004d3540;
    extraout_ECX[10] = 0;
    extraout_ECX[1] = (int)&PTR_FUN_004d353c;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  cVar1 = *(char *)(unaff_EBP + 0x10);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_FUN_004d3534;
  if (cVar1 != '\0') {
    FUN_004bce13(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

