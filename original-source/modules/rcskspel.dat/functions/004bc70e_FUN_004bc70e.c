/*
 * FUN_004bc70e at 004bc70e
 * undefined FUN_004bc70e(void)
 * Address ranges: 004bc70e-004bc76c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004bc70e(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_004d3548;
    extraout_ECX[0xb] = 0;
    extraout_ECX[2] = (int)&PTR_FUN_004d353c;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_FUN_004d352c;
  FUN_004be0fe();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

