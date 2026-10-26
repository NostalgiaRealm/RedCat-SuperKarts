/*
 * FUN_0043e920 at 0043e920
 * undefined __register FUN_0043e920(int * param_1, char param_2)
 * Address ranges: 0043e920-0043e9d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e920(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  byte extraout_DL;
  undefined4 auStack_18 [4];
  
  piVar2 = FUN_0040320c(param_1,param_2);
  FUN_00431338(*(int *)PTR_DAT_0047c86c,(int)piVar2);
  iVar1 = piVar2[0x24];
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x20) & 8) != 0)) {
    (**(code **)(*piVar2 + 0x60))(piVar2,0);
  }
  else {
    FUN_004405f0(iVar1,0xb039,0,piVar2);
    (**(code **)(*piVar2 + 0x60))(piVar2,0);
    FUN_0043f054((int)piVar2,auStack_18);
    FUN_00403088(piVar2,0xffffffff,auStack_18);
    piVar2[0x24] = 0;
  }
  FUN_00402eac((int *)piVar2[0x17]);
  piVar2[0x17] = 0;
  FUN_00402eac((int *)piVar2[0x19]);
  FUN_00402eac((int *)piVar2[0x16]);
  FUN_00408574(piVar2[0x15]);
  FUN_004147c4(piVar2,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar2);
  }
  return;
}

