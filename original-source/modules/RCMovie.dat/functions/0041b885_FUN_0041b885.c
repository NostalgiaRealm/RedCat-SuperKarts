/*
 * FUN_0041b885 at 0041b885
 * undefined __cdecl FUN_0041b885(int param_1)
 * Address ranges: 0041b885-0041bb91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041b885(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  iVar6 = piVar2[4];
  iVar5 = piVar2[5];
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_animbutton__no_va_00436798);
  }
  FUN_00404a0d();
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 4) {
    iVar6 = FUN_004128a6(iVar1);
    if (iVar6 != 2) {
      FUN_00411de7(iVar1,2);
      FUN_0041b539(piVar2[2],iVar1,piVar2[6],1);
    }
  }
  else if (iVar3 == 0x10) {
    iVar3 = FUN_0041294e(iVar1);
    if (iVar3 == 4) {
      FUN_00411de7(iVar1,1);
      iVar3 = FUN_00412687(piVar2[3],*(int *)(DAT_0043d858 + piVar2[3] * 0xc) + -1);
      uVar8 = 1;
      iVar4 = FUN_00412a49(iVar1);
      iVar4 = iVar4 + iVar5 / 2;
      iVar5 = FUN_004129f6(iVar1);
      iVar5 = iVar5 + iVar6 / 2;
      iVar6 = FUN_00412061();
      FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar8);
    }
    else {
      FUN_00411de7(iVar1,1);
      FUN_0041b539(piVar2[3],iVar1,piVar2[6],1);
    }
  }
  else if (iVar3 == 0x11) {
    FUN_00411de7(iVar1,4);
    FUN_0041b539(piVar2[1],iVar1,piVar2[6],1);
  }
  else {
    uVar7 = FUN_0041294e(iVar1);
    switch(uVar7) {
    case 0:
      iVar6 = FUN_004128a6(iVar1);
      if (iVar6 == 0) {
        FUN_00411de7(iVar1,0);
        FUN_0041b539(*piVar2,iVar1,piVar2[6],1);
      }
      break;
    case 1:
    case 4:
      FUN_00411de7(iVar1,0);
      iVar3 = FUN_00412687(*piVar2,*(int *)(DAT_0043d858 + *piVar2 * 0xc) + -1);
      uVar8 = 1;
      iVar4 = FUN_00412a49(iVar1);
      iVar4 = iVar4 + iVar5 / 2;
      iVar5 = FUN_004129f6(iVar1);
      iVar5 = iVar5 + iVar6 / 2;
      iVar6 = FUN_00412061();
      FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar8);
      break;
    case 2:
      FUN_00411de7(iVar1,0);
      FUN_0041b539(piVar2[2],iVar1,piVar2[6],2);
      break;
    default:
      FUN_00411de7(iVar1,0);
      FUN_0041b539(*piVar2,iVar1,piVar2[6],1);
    }
  }
  if (piVar2[8] != 0) {
    FUN_0041258a(iVar1,piVar2[9],piVar2[10],piVar2[10],piVar2[0xb]);
  }
  FUN_00404a81();
  return;
}

