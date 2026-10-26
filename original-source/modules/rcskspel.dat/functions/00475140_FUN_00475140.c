/*
 * FUN_00475140 at 00475140
 * undefined FUN_00475140(void)
 * Address ranges: 00475140-004751a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 __thiscall FUN_00475140(int param_1,int param_2)

{
  float fVar1;
  
  if (5 < param_2) {
    FUN_004afee0(s__s__d____wheel_index___d__bigger_004f7940,
                 s_D__work_rcsk_Code_game_ssr_m25_g_004f7918,0xa1,param_2);
  }
  FUN_004afce0(s__s__d____Getting_m_WheelPos__d__004f7994,
               s_D__work_rcsk_Code_game_ssr_m25_g_004f796c,0xa7,param_2);
  fVar1 = *(float *)(*(int *)(param_1 + 0x54) + param_2 * 4);
  FUN_004afce0(s__s__d____Got_m_WheelPos__d__004f79e0,s_D__work_rcsk_Code_game_ssr_m25_g_004f79b8,
               0xa9,param_2);
  return (float10)fVar1;
}

