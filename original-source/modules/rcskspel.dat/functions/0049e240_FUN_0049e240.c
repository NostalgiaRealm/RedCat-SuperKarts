/*
 * FUN_0049e240 at 0049e240
 * undefined FUN_0049e240(void)
 * Address ranges: 0049e240-0049e2c6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049e240(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  FUN_004afce0(s_____Initting_CSndEngine_version___004fc314,0x3ff19999a0000000,
               s_Sep_30_1999_004fc344);
  iVar1 = FUN_004b44b0(param_3);
  if (iVar1 == 0) {
    FUN_004afee0(s__s___d__Init_of_sound_lib_failed_004fc2f0,
                 s_D__work_rcracer_oursoundlib_soun_004fc23c,0x94);
  }
  FUN_0049f2a0(-1 < param_1,s__s___d__Trying_to_set_an_illegal_004fc2b0,
               s_D__work_rcracer_oursoundlib_soun_004fc23c,0x9a,param_1);
  FUN_0049dc60();
  FUN_0049ead0(param_2);
  return;
}

