/*
 * FUN_0044f110 at 0044f110
 * undefined FUN_0044f110(void)
 * Address ranges: 0044f110-0044f25e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0044f110(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_004afce0(s___s_Handle_current_animation_lin_004f0d78,
               s_D__work_rcsk_Code_game_msh_mshAn_004f0d4c,0x7d);
  if (*(int *)(param_1 + 0x60) != 0) {
    uVar4 = 100;
    FUN_0044f500(100);
    FUN_0044e850(uVar4);
    FUN_0044f500();
    iVar2 = FUN_0044eb50();
    if (iVar2 != -1) {
      FUN_0044f500();
      iVar2 = FUN_0044eb50();
      if (iVar2 == 0) {
        uVar4 = FUN_0044f500();
        FUN_004afce0(s___s__d_Current_Anim__d_done______004f0ddc,
                     s_D__work_rcsk_Code_game_msh_mshAn_004f0db0,0x85,uVar4);
        iVar3 = *(int *)(param_1 + 0x40) + 4;
        iVar2 = *(int *)(param_1 + 0x60) + -1;
        *(int *)(param_1 + 0x40) = iVar3;
        *(int *)(param_1 + 0x60) = iVar2;
        if ((iVar2 == 0) || (iVar3 == *(int *)(param_1 + 0x3c))) {
          puVar1 = *(undefined4 **)(param_1 + 0x44);
          *(undefined4 **)(param_1 + 0x44) = puVar1 + 1;
          FUN_004bc150(*puVar1);
          if (*(int *)(param_1 + 0x60) == 0) {
            *(undefined4 *)(param_1 + 0x38) = 0;
            *(undefined4 *)(param_1 + 0x3c) = 0;
            *(undefined4 *)(param_1 + 0x40) = 0;
            *(undefined4 *)(param_1 + 0x44) = 0;
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(undefined4 *)(param_1 + 0x4c) = 0;
            *(undefined4 *)(param_1 + 0x50) = 0;
            *(undefined4 *)(param_1 + 0x54) = 0;
            FUN_004bc150(*(undefined4 *)(param_1 + 0x58));
          }
          else {
            iVar2 = **(int **)(param_1 + 0x44);
            *(int *)(param_1 + 0x38) = iVar2;
            *(int *)(param_1 + 0x3c) = iVar2 + 0x1000;
            *(int *)(param_1 + 0x40) = iVar2;
            *(int **)(param_1 + 0x44) = *(int **)(param_1 + 0x44);
          }
        }
        FUN_0044f500();
        FUN_0044eb90();
      }
    }
  }
  FUN_004afce0(s____________________s_Handling_an_004f0e38,
               s_D__work_rcsk_Code_game_msh_mshAn_004f0e0c,0x8a);
  return;
}

