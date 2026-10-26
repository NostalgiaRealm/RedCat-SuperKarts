/*
 * FUN_004949c0 at 004949c0
 * undefined FUN_004949c0(void)
 * Address ranges: 004949c0-00494b62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004949c0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = param_2;
  local_4 = 0;
  local_8 = 0;
  FUN_004bf930(param_1 + 0x24,4,1,param_2);
  FUN_004bf930(param_1 + 0x28,4,1,param_2);
  FUN_004bf930(param_1 + 0x2c,4,1,param_2);
  iVar3 = param_1 + 0xec;
  iVar4 = 2;
  do {
    FUN_004bf930(iVar3,4,1,param_2);
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = (int *)(param_1 + 0xe0);
  FUN_004bf930(piVar1,4,1,param_2);
  iVar3 = 0;
  if (0 < *piVar1) {
    param_2 = (undefined4 *)(param_1 + 0xf4);
    do {
      FUN_004bf930(&local_4,4,1,uVar2);
      iVar3 = iVar3 + 1;
      *param_2 = local_4;
      param_2 = param_2 + 1;
    } while (iVar3 < *piVar1);
  }
  piVar1 = (int *)(param_1 + 0xe4);
  FUN_004bf930(piVar1,4,1,uVar2);
  if (0xc < *piVar1) {
    FUN_004afee0(s__s__d____chunk_waypoint_left_ove_004faf8c,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fafb4,0x76,*piVar1,0xc);
  }
  iVar3 = 0;
  if (0 < *piVar1) {
    param_2 = (undefined4 *)(param_1 + 0x124);
    do {
      FUN_004bf930(&local_8,4,1,uVar2);
      iVar3 = iVar3 + 1;
      *param_2 = local_8;
      param_2 = param_2 + 1;
    } while (iVar3 < *piVar1);
  }
  piVar1 = (int *)(param_1 + 0xe8);
  FUN_004bf930(piVar1,4,1,uVar2);
  if (0xc < *piVar1) {
    FUN_004afee0(s__s__d____chunk_waypoint_left_ove_004faf8c,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fafb4,0x86,*piVar1,0xc);
  }
  iVar3 = 0;
  if (0 < *piVar1) {
    param_2 = (undefined4 *)(param_1 + 0x154);
    do {
      FUN_004bf930(&local_8,4,1,uVar2);
      iVar3 = iVar3 + 1;
      *param_2 = local_8;
      param_2 = param_2 + 1;
    } while (iVar3 < *piVar1);
  }
  *(undefined4 *)(param_1 + 0x20) = 1;
  return;
}

