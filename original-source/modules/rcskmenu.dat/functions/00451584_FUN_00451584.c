/*
 * FUN_00451584 at 00451584
 * undefined FUN_00451584(void)
 * Address ranges: 00451584-00451609
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451584(int *param_1,char param_2)

{
  int *piVar1;
  BOOL BVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  byte extraout_DL;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1[0x109] == 0) {
    BVar2 = FUN_0040272c(piVar1[0x110]);
    uVar4 = extraout_ECX_00;
    uVar5 = extraout_EDX_00;
  }
  else {
    if ((HGDIOBJ)piVar1[0x10d] != (HGDIOBJ)0x0) {
      SelectObject((HDC)piVar1[0x108],(HGDIOBJ)piVar1[0x10d]);
    }
    BVar2 = DeleteObject((HGDIOBJ)piVar1[0x109]);
    uVar4 = extraout_ECX;
    uVar5 = extraout_EDX;
  }
  piVar3 = FUN_004507d8(BVar2,uVar5,uVar4);
  FUN_00450794((int)piVar3,piVar1 + 0x10e);
  if ((HDC)piVar1[0x108] != (HDC)0x0) {
    DeleteDC((HDC)piVar1[0x108]);
  }
  FUN_0040272c(piVar1[3]);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

