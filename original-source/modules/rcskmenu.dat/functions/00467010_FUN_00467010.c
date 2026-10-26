/*
 * FUN_00467010 at 00467010
 * undefined __register FUN_00467010(int * param_1, char param_2)
 * Address ranges: 00467010-0046706d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467010(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  byte extraout_DL;
  int iVar3;
  int iVar4;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  iVar3 = *(int *)(piVar1[0x90] + 8);
  if (-1 < iVar3 + -1) {
    iVar4 = 0;
    do {
      iVar2 = FUN_0040f6b0((undefined4 *)piVar1[0x90],iVar4);
      *(undefined4 *)(iVar2 + 500) = 0;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_00402eac((int *)piVar1[0x90]);
  FUN_00465f78(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

