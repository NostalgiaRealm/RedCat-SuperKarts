/*
 * FUN_0048fda0 at 0048fda0
 * undefined FUN_0048fda0(void)
 * Address ranges: 0048fda0-0048fe96
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048fda0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,float param_6,float param_7,float param_8,float param_9)

{
  undefined4 *puVar1;
  
  FUN_004afce0(s_Init_physics_for_main_object___d_004fa548,param_1);
  puVar1 = (undefined4 *)(param_1 * 0xd0 + DAT_0067ee20);
  *puVar1 = 1;
  if (0.1 <= param_6) {
    puVar1[0x24] = 1.0 / param_6;
    puVar1[0x25] = 1.0 / (param_6 * 0.083333336 * (param_9 * param_9 + param_8 * param_8));
  }
  else {
    puVar1[0x24] = 0;
    puVar1[0x25] = 0;
  }
  if ((param_7 < 0.0) || (1.0 < param_7)) {
    FUN_004afee0(s__s__d____Invalid_coef__of_restit_004fa51c,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x386,(double)param_7);
  }
  puVar1[0x26] = param_7;
  puVar1[0x27] = param_2;
  puVar1[0x28] = param_3;
  puVar1[0x2b] = param_5;
  puVar1[0x29] = param_4;
  return;
}

