/*
 * FUN_004180b4 at 004180b4
 * undefined __register FUN_004180b4(int * param_1, char param_2)
 * Address ranges: 004180b4-0041810e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004180b4(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0040fa84(DAT_0047d6d4,(int)piVar1);
  FUN_00418a14(piVar1,0);
  FUN_00402eac((int *)piVar1[3]);
  FUN_00402eac((int *)piVar1[4]);
  FUN_00402eac((int *)piVar1[5]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0xe));
  FUN_0040fc7c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

