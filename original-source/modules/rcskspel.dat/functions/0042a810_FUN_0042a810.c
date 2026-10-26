/*
 * FUN_0042a810 at 0042a810
 * undefined FUN_0042a810(void)
 * Address ranges: 0042a810-0042a8ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a810(void)

{
  char cVar1;
  
  FUN_004afce0(s_Exit_Game_004e8c38);
  FUN_004afce0(s_Delete_particles_004e8c44);
  FUN_004afce0(s_Stop_Engine_Sound_004e8c58);
  FUN_00418980();
  FUN_004afce0(s_Exit_SoundFXEngine_004e8c6c);
  FUN_0043b560();
  FUN_004afce0(s_Exit_SoundFXEngine_Done_004e8c80);
  FUN_0042c4c0();
  FUN_0049b0a0();
  FUN_0042a7f0();
  FUN_00424330();
  FUN_004235b0();
  FUN_00426c40();
  FUN_00445040();
  cVar1 = FUN_0048ebc0();
  if (cVar1 != '\0') {
    FUN_0048eee0();
  }
  thunk_FUN_00416590();
  FUN_00420b40();
  if (DAT_0053b9c4 == 0) {
    FUN_004271e0();
  }
  thunk_FUN_0048faf0();
  return;
}

