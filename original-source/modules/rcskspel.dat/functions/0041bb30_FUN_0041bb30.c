/*
 * FUN_0041bb30 at 0041bb30
 * undefined FUN_0041bb30(void)
 * Address ranges: 0041bb30-0041bcd2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bb30(undefined4 param_1,float *param_2,float *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  FUN_004b1d60();
  uVar1 = FUN_004b1ed0();
  FUN_004afce0();
  FUN_00475360();
  FUN_00476510();
  FUN_004afce0();
  uVar2 = FUN_004751b0();
  FUN_004afce0(s__s__d____Wheel_coordinates__d_004e2788,s_D__work_rcsk_Code_game_car_whl_C_004e2764,
               0xbd,uVar2);
  FUN_004afce0();
  fVar3 = (float10)FUN_00475140();
  *param_2 = (float)fVar3;
  FUN_004afce0();
  fVar3 = (float10)FUN_00475140();
  param_2[1] = (float)fVar3;
  FUN_004afce0();
  fVar3 = (float10)FUN_00475140();
  param_2[2] = (float)fVar3;
  FUN_004afce0();
  fVar3 = (float10)FUN_00475140();
  *param_3 = (float)fVar3;
  FUN_004afce0();
  fVar3 = (float10)FUN_00475140();
  param_3[1] = (float)fVar3;
  FUN_004afce0();
  fVar3 = (float10)FUN_00475140();
  param_3[2] = (float)fVar3;
  FUN_004afce0(s______Wheel_data_for_car__d___f____004e2900,uVar1,(double)*param_2,
               (double)param_2[1],(double)param_2[2],(double)*param_3,(double)param_3[1],
               (double)fVar3);
  return;
}

