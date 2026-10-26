/*
 * FUN_004415d0 at 004415d0
 * undefined FUN_004415d0(void)
 * Address ranges: 004415d0-004416e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004415d0(int *param_1,int param_2)

{
  POINT pt;
  BOOL BVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  LONG LVar3;
  LONG LVar4;
  int iStack_38;
  LONG LStack_34;
  LONG LStack_30;
  LONG LStack_2c;
  byte abStack_28 [4];
  RECT RStack_24;
  int aiStack_14 [2];
  
  if ((*(int *)(param_2 + 0xc) == 0) && ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
    FUN_00406c20(*(undefined4 *)(param_2 + 8),&iStack_38);
    if (iStack_38 < 0) {
      LStack_30 = iStack_38;
      LStack_2c = LStack_34;
    }
    else {
      FUN_0043f1f0(param_1,&iStack_38,&LStack_30);
      LVar3 = LStack_30;
      LVar4 = LStack_2c;
      (**(code **)(*param_1 + 0x40))(param_1,&RStack_24);
      pt.y = LVar4;
      pt.x = LVar3;
      BVar1 = PtInRect(&RStack_24,pt);
      if (BVar1 == 0) {
        (**(code **)(*param_1 + -0x10))(param_1,param_2);
        return;
      }
    }
    abStack_28[0] = 0;
    FUN_00403088(param_1,&LStack_30,abStack_28);
    *(uint *)(param_2 + 0xc) = (uint)abStack_28[0];
    if (abStack_28[0] == 0) {
      piVar2 = (int *)FUN_00403088(param_1,extraout_EDX,extraout_ECX);
      if ((piVar2 != (int *)0x0) && (*(char *)((int)piVar2 + 0x51) != '\0')) {
        FUN_0043f21c(param_1,0);
        piVar2[0x15] = (int)param_1;
        if (iStack_38 < 0) {
          FUN_0040ebd0(0,0,aiStack_14);
          FUN_0043f1c4(param_1,aiStack_14,&iStack_38);
        }
        (**(code **)(*piVar2 + 0x40))(piVar2,iStack_38,LStack_34);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      if (*(int *)(param_2 + 0xc) == 0) {
        (**(code **)(*param_1 + -0x10))(param_1,param_2);
      }
    }
  }
  return;
}

