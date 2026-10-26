/*
 * FUN_004c2cc3 at 004c2cc3
 * undefined FUN_004c2cc3(void)
 * Address ranges: 004c2cc3-004c2e69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c2cc3(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 char param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)(param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_004c2bd2();
  }
  piVar3 = DAT_006b677c;
  if (*param_1 == -0x1f928c9d) {
    if (((param_1[4] == 3) && (param_1[5] == 0x19930520)) && (param_1[7] == 0)) {
      if (DAT_006b677c == (int *)0x0) {
        return;
      }
      param_3 = DAT_006b6780;
      local_18 = CONCAT31(local_18._1_3_,1);
      iVar2 = FUN_004c972c(DAT_006b677c,1);
      if (iVar2 == 0) {
        FUN_004c2bd2();
      }
      param_1 = piVar3;
      if (*piVar3 != -0x1f928c9d) goto LAB_004c2e3f;
      if (((piVar3[4] == 3) && (piVar3[5] == 0x19930520)) && (piVar3[7] == 0)) {
        FUN_004c2bd2();
      }
    }
    iVar2 = local_14;
    if (((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) && (param_1[5] == 0x19930520)) {
      piVar3 = (int *)FUN_004bed4d(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_004c3382(param_1,1);
          return;
        }
        if ((*piVar3 <= iVar2) && (iVar2 <= piVar3[1])) {
          iVar1 = piVar3[4];
          for (local_10 = piVar3[3]; iVar2 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar4 = *(int **)(param_1[7] + 0xc);
            for (local_c = *piVar4; 0 < local_c; local_c = local_c + -1) {
              piVar4 = piVar4 + 1;
              iVar2 = FUN_004c2f12(iVar1,*piVar4,param_1[7]);
              if (iVar2 != 0) {
                FUN_004c300d(param_1,param_2,param_3,param_4,param_5,iVar1,*piVar4,piVar3,param_7,
                             param_8,local_18);
                iVar2 = local_14;
                goto LAB_004c2e1f;
              }
            }
            iVar1 = iVar1 + 0x10;
          }
        }
LAB_004c2e1f:
        local_8 = local_8 + 1;
        piVar3 = piVar3 + 5;
      } while( true );
    }
  }
LAB_004c2e3f:
  if (param_6 == '\0') {
    FUN_004c2e6a(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_004c2b7c();
  return;
}

