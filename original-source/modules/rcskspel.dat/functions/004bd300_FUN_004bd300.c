/*
 * FUN_004bd300 at 004bd300
 * undefined FUN_004bd300(void)
 * Address ranges: 004bd300-004bd369
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004bd300(void)

{
  char cVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *extraout_ECX = (int)&DAT_004d35d8;
    extraout_ECX[10] = 0;
    extraout_ECX[1] = (int)&PTR_FUN_004d35d4;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  cVar1 = *(char *)(unaff_EBP + 0x10);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_FUN_004d35cc;
  if (cVar1 != '\0') {
    FUN_004bdc5e(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

