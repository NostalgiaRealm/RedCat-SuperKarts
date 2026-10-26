/*
 * FUN_0041aa20 at 0041aa20
 * undefined FUN_0041aa20(void)
 * Address ranges: 0041aa20-0041ab31
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041aa20(void)

{
  FUN_00419260();
  FUN_004b1850(0,0,0,s_Racer_Speed_Tweak_Menu_004e233c);
  FUN_004b1850(0,0x14,0x28,s_Max_speed_gear_1___f_004e2354,
               (double)(float)(&DAT_00506918)[DAT_00508618 * 0x1f]);
  FUN_004b1850(0,0x14,0x3c,s_Max_speed_gear_2___f_004e236c,
               (double)(float)(&DAT_0050691c)[DAT_00508618 * 0x1f]);
  FUN_004b1850(0,0x14,0x50,s_Max_speed_gear_3___f_004e2384,
               (double)*(float *)(&DAT_00506920 + DAT_00508618 * 0x7c));
  FUN_004b1850(0,0x14,100,s_Max_speed_gear_4___f_004e239c,
               (double)*(float *)(&DAT_00506924 + DAT_00508618 * 0x7c));
  FUN_004b1850(0,0x14,0x78,s_Max_speed_gear_5___f_004e23b4,
               (double)*(float *)(&DAT_00506928 + DAT_00508618 * 0x7c));
  FUN_004b1850(0,0x14,0x8c,s_Max_speed_gear_6___f_004e23cc,
               (double)*(float *)(&DAT_0050692c + DAT_00508618 * 0x7c));
  return;
}

