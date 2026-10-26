/*
 * FUN_004186c0 at 004186c0
 * undefined FUN_004186c0(void)
 * Address ranges: 004186c0-00418728
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004186c0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1[5] != 0) {
    FUN_004afee0(s__s___d__Minimum_RPM_table_alread_004e150c,
                 s_D__work_rcsk_Code_game_car_snd_c_004e14e8,0xe6);
  }
  pvVar1 = operator_new(*param_1 << 2);
  param_1[5] = (int)pvVar1;
  if (pvVar1 == (void *)0x0) {
    FUN_004afee0(s__s___d__Could_not_allocate_RPM_t_004e1560,
                 s_D__work_rcsk_Code_game_car_snd_c_004e153c,0xeb);
  }
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(param_1[5] + -4 + iVar2 * 4) = 0xffffffff;
    } while (iVar2 < *param_1);
  }
  return;
}

