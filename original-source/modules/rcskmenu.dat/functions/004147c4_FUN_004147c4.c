/*
 * FUN_004147c4 at 004147c4
 * undefined __register FUN_004147c4(int * param_1, char param_2)
 * Address ranges: 004147c4-00414848
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004147c4(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  byte extraout_DL;
  int iVar3;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00414a28((int)piVar1);
  if (piVar1[5] != 0) {
    iVar3 = *(int *)(piVar1[5] + 8) + -1;
    if (-1 < iVar3) {
      do {
        piVar2 = (int *)FUN_0040f6b0((undefined4 *)piVar1[5],iVar3);
        (**(code **)(*piVar2 + 0x10))(piVar2,piVar1,1);
        if (piVar1[5] == 0) break;
        iVar3 = iVar3 + -1;
      } while (iVar3 != -1);
    }
    FUN_00402eac((int *)piVar1[5]);
    piVar1[5] = 0;
  }
  FUN_004149d0(piVar1);
  if ((int *)piVar1[1] != (int *)0x0) {
    FUN_00414998((int *)piVar1[1],(int)piVar1);
  }
  FUN_0040fc7c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

