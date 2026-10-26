/*
 * FUN_0048f010 at 0048f010
 * undefined FUN_0048f010(void)
 * Address ranges: 0048f010-0048f05e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048f010(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_4;
  
  piVar3 = &local_4;
  piVar2 = *(int **)(param_1 + 4);
  local_4 = param_1;
  iVar1 = (**(code **)*piVar2)(piVar2,&DAT_004d34a0,&local_4);
  if (-1 < iVar1) {
    (**(code **)(*piVar2 + 0x1c))(piVar2,piVar3);
    (**(code **)(*piVar2 + 8))(piVar2);
    return;
  }
  FUN_004afee0(s__s__d___Could_not_set_volume_004fa35c,s_D__work_rcsk_Code_game_DaviMedia_004fa334,
               0x1be);
  return;
}

