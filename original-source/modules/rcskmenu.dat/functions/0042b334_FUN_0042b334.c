/*
 * FUN_0042b334 at 0042b334
 * undefined __register FUN_0042b334(int * param_1)
 * Address ranges: 0042b334-0042b36f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b334(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  
  FUN_0044131c(param_1);
  piVar1 = (int *)param_1[0x82];
  if (piVar1 != (int *)0x0) {
    param_1[0x82] = 0;
    cVar2 = FUN_00403088(piVar1,extraout_EDX,extraout_ECX);
    if (cVar2 != '\0') {
      FUN_0042d2b4(param_1,piVar1,extraout_ECX_00);
    }
  }
  return;
}

