/*
 * FUN_004461e0 at 004461e0
 * undefined FUN_004461e0(void)
 * Address ranges: 004461e0-0044624d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * __thiscall FUN_004461e0(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (**(code **)*param_1)();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_00445de0();
      if (iVar2 == param_2) {
        return (undefined *)(*(int *)(param_1[1] + 4) + iVar3 * 0x2c);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_004afee0(s__s__d____Couldn_t_find_item_with_004ef6c4,
               s_D__work_rcsk_Code_game_pth_PathC_004ef694,0x143,param_2);
  return &DAT_00543778;
}

