/*
 * FUN_004bc6a6 at 004bc6a6
 * undefined FUN_004bc6a6(void)
 * Address ranges: 004bc6a6-004bc70d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004bc6a6(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    *extraout_ECX = (int)&DAT_004d3548;
    extraout_ECX[0xb] = 0;
    extraout_ECX[2] = (int)&PTR_FUN_004d353c;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  extraout_ECX[1] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_FUN_004d352c;
  FUN_004bce13(uVar2,uVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

