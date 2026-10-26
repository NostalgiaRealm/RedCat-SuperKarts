/*
 * FUN_00449b80 at 00449b80
 * undefined FUN_00449b80(void)
 * Address ranges: 00449b80-00449bcf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00449b80(int param_1,int param_2)

{
  void *pvVar1;
  
  if (param_2 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      FUN_00449bd0();
    }
    pvVar1 = operator_new(param_2 * 8);
    *(void **)(param_1 + 8) = pvVar1;
    FUN_00492fe0(pvVar1 != (void *)0x0,s_Could_not_allocate__d_frame_type_004f030c,
                 s_D__work_rcsk_Code_game_anm_type__004f02e8,0x10b,param_2);
  }
  *(int *)(param_1 + 0xc) = param_2;
  return;
}

