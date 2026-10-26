/*
 * FUN_004c9e42 at 004c9e42
 * undefined FUN_004c9e42(void)
 * Address ranges: 004c9e42-004c9fed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004c9e42(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  if (DAT_005036b4 != 0) {
    iVar2 = param_1[5];
    if ((iVar2 != DAT_00503748) || (iVar2 != DAT_00503758)) {
      if (DAT_006b6910 == 0) {
        FUN_004c9fee(1,1,iVar2,4,1,0,0,2,0,0,0);
        FUN_004c9fee(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_006b69b0 != 0) {
          uVar4 = 0;
          uVar3 = 0;
          uVar5 = DAT_006b69b6;
        }
        else {
          uVar4 = DAT_006b69b4;
          uVar3 = DAT_006b69b6;
          uVar5 = 0;
        }
        FUN_004c9fee(1,DAT_006b69b0 == 0,iVar2,DAT_006b69b2,uVar3,uVar4,uVar5,DAT_006b69b8,
                     DAT_006b69ba,DAT_006b69bc,DAT_006b69be);
        if (DAT_006b695c != 0) {
          uVar4 = 0;
          uVar3 = 0;
          iVar2 = param_1[5];
          uVar5 = DAT_006b6962;
        }
        else {
          iVar2 = param_1[5];
          uVar4 = DAT_006b6960;
          uVar3 = DAT_006b6962;
          uVar5 = 0;
        }
        FUN_004c9fee(0,DAT_006b695c == 0,iVar2,DAT_006b695e,uVar3,uVar4,uVar5,DAT_006b6964,
                     DAT_006b6966,DAT_006b6968,DAT_006b696a);
      }
    }
    iVar2 = param_1[7];
    if (DAT_0050374c < DAT_0050375c) {
      if ((DAT_0050374c <= iVar2) && (iVar2 <= DAT_0050375c)) {
        if ((DAT_0050374c < iVar2) && (iVar2 < DAT_0050375c)) {
          return true;
        }
LAB_004c9fba:
        iVar1 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar2 == DAT_0050374c) {
          return DAT_00503750 <= iVar1;
        }
        return iVar1 < DAT_00503760;
      }
    }
    else {
      if (iVar2 < DAT_0050375c) {
        return true;
      }
      if (DAT_0050374c < iVar2) {
        return true;
      }
      if ((iVar2 <= DAT_0050375c) || (DAT_0050374c <= iVar2)) goto LAB_004c9fba;
    }
  }
  return false;
}

