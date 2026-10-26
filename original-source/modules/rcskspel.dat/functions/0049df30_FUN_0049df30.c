/*
 * FUN_0049df30 at 0049df30
 * undefined FUN_0049df30(void)
 * Address ranges: 0049df30-0049e09c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049df30(int param_1)

{
  int iVar1;
  
  FUN_004afce0();
  FUN_004afce0(s_____Dump_of_object_CSndEngine____004fc1b4);
  FUN_004afce0();
  FUN_004afce0();
  FUN_004afce0(s_Listener_position___f___f___f_004fc180,(double)*(float *)(param_1 + 0x254),
               (double)*(float *)(param_1 + 600),(double)*(float *)(param_1 + 0x25c));
  FUN_004afce0(s_Listener_velocity___f___f___f_004fc160,(double)*(float *)(param_1 + 0x264),
               (double)*(float *)(param_1 + 0x268),(double)*(float *)(param_1 + 0x26c));
  FUN_004afce0(s_Number_of_sample_groups_read___d_004fc13c,*(undefined4 *)(param_1 + 0x220));
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x220)) {
    do {
      FUN_004afce0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x220));
  }
  FUN_004afce0(s_Number_of_sound_types___d_004fc110,*(undefined4 *)(param_1 + 0x18));
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      FUN_0049ec00();
      FUN_0049efb0();
      FUN_004afce0(s_______________________Type__2d___004fc0d8,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x18));
  }
  FUN_004afce0();
  FUN_004afce0();
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      FUN_004afce0(s_______________________Source__2d_004fc048,iVar1);
      FUN_0049dd20();
      FUN_0049d280();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 8));
  }
  return;
}

