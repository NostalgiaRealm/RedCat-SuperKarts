/*
 * FUN_00449c80 at 00449c80
 * undefined FUN_00449c80(void)
 * Address ranges: 00449c80-00449d2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00449c80(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd7fb;
  local_c = ExceptionList;
  if (param_2 != 0) {
    ExceptionList = &local_c;
    if (*param_1 != 0) {
      ExceptionList = &local_c;
      FUN_00449d30();
    }
    piVar1 = operator_new(param_2 * 0x10 + 4);
    local_4 = 0;
    if (piVar1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = piVar1 + 1;
      *piVar1 = param_2;
      FUN_004be91c(piVar2,0x10,param_2,&LAB_00449900,FUN_00449910);
    }
    local_4 = 0xffffffff;
    *param_1 = (int)piVar2;
    FUN_00492fe0(piVar2 != (int *)0x0,s__s___d__Could_not_allocate__d_an_004f0354,
                 s_D__work_rcsk_Code_game_anm_type__004f0330,0x169,param_2);
  }
  param_1[1] = param_2;
  ExceptionList = local_c;
  return;
}

