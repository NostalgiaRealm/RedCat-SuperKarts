/*
 * FUN_004418ac at 004418ac
 * undefined __register FUN_004418ac(int * param_1, char param_2)
 * Address ranges: 004418ac-0044197c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004418ac(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00414a28((int)piVar1);
  if ((char)piVar1[0x51] != '\0') {
    *(undefined1 *)(piVar1 + 0x51) = 0;
    FUN_0043d560((int)piVar1,'\0',extraout_ECX);
  }
  FUN_00405490(piVar1 + 0x52);
  FUN_00402eac((int *)piVar1[0x50]);
  if (piVar1[9] != 0) {
    FUN_0044244c(piVar1,'\x01');
  }
  if (piVar1[0x53] != 0) {
    (**(code **)(*piVar1 + 0x9c))();
  }
  iVar2 = FUN_0044268c((int)piVar1);
  while (iVar2 != 0) {
    piVar3 = (int *)FUN_00442650((int)piVar1,iVar2 + -1);
    FUN_004424b8((int)piVar1,piVar3);
    (**(code **)(*piVar3 + -4))(piVar3,1);
    iVar2 = FUN_0044268c((int)piVar1);
  }
  FUN_00402eac((int *)piVar1[0x4c]);
  if (piVar1[0x57] != 0) {
    FUN_00429670(piVar1[0x57]);
  }
  FUN_0043e920(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

