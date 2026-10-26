/*
 * FUN_00466c18 at 00466c18
 * undefined FUN_00466c18(void)
 * Address ranges: 00466c18-00466c63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466c18(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  byte extraout_DL;
  
  piVar2 = FUN_0040320c(param_1,param_2);
  iVar1 = piVar2[0x7d];
  if (iVar1 != 0) {
    if (piVar2 == *(int **)(iVar1 + 0x24c)) {
      *(undefined4 *)(iVar1 + 0x24c) = 0;
    }
    FUN_004675bc((int *)piVar2[0x7d],piVar2);
  }
  FUN_004418ac(piVar2,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar2);
  }
  return;
}

