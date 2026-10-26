/*
 * FUN_004318a0 at 004318a0
 * undefined FUN_004318a0(void)
 * Address ranges: 004318a0-00431941
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004318a0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
    FUN_004afee0(s__s__d____Mouse_not_initialised_004eb24c,
                 s_D__work_rcsk_Code_game_input_CPP_004eb228,0x95);
  }
  piVar1 = (int *)(param_1 + 8);
  iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x24))(*(int **)(param_1 + 4),0x10,piVar1);
  if (iVar2 == -0x7ff8ffe2) {
    iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))(*(int **)(param_1 + 4));
    if (iVar2 == 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x24))(*(int **)(param_1 + 4),0x10,piVar1);
      if (iVar2 != 0) {
        uVar3 = FUN_004b0190(iVar2);
        FUN_004afee0(s__s__d____DIError___Failed_to_get_004eb290,
                     s_D__work_rcsk_Code_game_input_CPP_004eb26c,0xa0,uVar3);
      }
    }
  }
  *(float *)(param_1 + 0x24) = (float)*piVar1;
  *(float *)(param_1 + 0x28) = (float)*(int *)(param_1 + 0xc);
  *(float *)(param_1 + 0x2c) = (float)*(int *)(param_1 + 0x10);
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x1c);
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x20);
  return;
}

