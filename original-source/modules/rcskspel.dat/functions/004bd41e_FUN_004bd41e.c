/*
 * FUN_004bd41e at 004bd41e
 * undefined FUN_004bd41e(void)
 * Address ranges: 004bd41e-004bd485
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004bd41e(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_004c0dec();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    *extraout_ECX = (int)&DAT_004d35e0;
    extraout_ECX[0xb] = 0;
    extraout_ECX[2] = (int)&PTR_FUN_004d35d4;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  extraout_ECX[1] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_FUN_004d35c4;
  FUN_004bdc5e(uVar2,uVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

