/*
 * FUN_0049d7d0 at 0049d7d0
 * undefined FUN_0049d7d0(void)
 * Address ranges: 0049d7d0-0049d865
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __fastcall FUN_0049d7d0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int local_4;
  
  local_4 = param_1;
  FUN_0049f2a0(DAT_006ab7b4,s__s___d__LIB_not_initialised_yet__004fbe1c,
               s_D__work_rcracer_oursoundlib_soun_004fbd4c,0x223);
  FUN_0049f250(*(undefined4 *)(param_1 + 0x38),0,DAT_006ab78c + -1,
               s_D__work_rcracer_oursoundlib_soun_004fbd4c,0x225);
  if (*(int *)(DAT_006ab798 + 0x30 + *(int *)(param_1 + 0x38) * 0x44) == 0) {
    return (int *)0x0;
  }
  piVar1 = *(int **)(DAT_006ab798 + *(int *)(param_1 + 0x38) * 0x44 + 0x28);
  piVar3 = &local_4;
  iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
  FUN_0049f2a0(iVar2 == 0,s__s___d__Getting_sound_status_fai_004fbdf4,
               s_D__work_rcracer_oursoundlib_soun_004fbd4c,0x22f,*(undefined4 *)(param_1 + 0x38));
  return piVar3;
}

