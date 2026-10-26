/*
 * FUN_00464a70 at 00464a70
 * undefined FUN_00464a70(void)
 * Address ranges: 00464a70-00464c55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00464a70(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_0048f4e0();
  *(float *)(param_1 + 4) = (float)(fVar2 + (float10)*(float *)(param_1 + 4));
  switch(*(undefined4 *)(param_1 + 0x18)) {
  case 0:
    FUN_00464e90();
    if ((1.1 <= *(float *)(param_1 + 4)) && (*(int *)(param_1 + 8) == 0)) {
      FUN_0043b600(s_STARTSE1_004f418c,0);
      *(undefined4 *)(param_1 + 8) = 1;
    }
    if (1.2 <= *(float *)(param_1 + 4)) {
      FUN_00464ff0(1);
      return;
    }
    break;
  case 1:
    FUN_00464dd0(0,1);
    if ((0.7 <= *(float *)(param_1 + 4)) && (*(int *)(param_1 + 8) < 2)) {
      FUN_0043b600(s_STARTSE2_004f4198,0);
      *(undefined4 *)(param_1 + 8) = 2;
    }
    if (0.8 <= *(float *)(param_1 + 4)) {
      FUN_00464ff0(2);
      return;
    }
    break;
  case 2:
    FUN_00464dd0(1,1);
    if ((0.7 <= *(float *)(param_1 + 4)) && (*(int *)(param_1 + 8) < 3)) {
      FUN_0043b600(s_STARTSE3_004f41a4,0);
      *(undefined4 *)(param_1 + 8) = 3;
    }
    if (0.8 <= *(float *)(param_1 + 4)) {
      FUN_00464ff0(3);
      return;
    }
    break;
  case 3:
    FUN_00464dd0(2,1);
    if ((0.7 <= *(float *)(param_1 + 4)) && (*(int *)(param_1 + 8) < 4)) {
      FUN_0043b600(s_STARTSE4_004f41b0,0);
      *(undefined4 *)(param_1 + 8) = 4;
    }
    if (0.8 <= *(float *)(param_1 + 4)) {
      FUN_00464ff0(4);
      return;
    }
    break;
  case 4:
    iVar1 = 0;
    do {
      FUN_00464dd0(iVar1,2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    if (0.8 <= *(float *)(param_1 + 4)) {
      FUN_00464ff0(5);
      return;
    }
    break;
  case 5:
    FUN_00464f30();
    if (1.2 <= *(float *)(param_1 + 4)) {
      FUN_00464ff0(6);
    }
  }
  return;
}

