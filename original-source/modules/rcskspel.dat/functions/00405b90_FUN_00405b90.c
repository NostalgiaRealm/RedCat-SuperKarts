/*
 * FUN_00405b90 at 00405b90
 * undefined FUN_00405b90(void)
 * Address ranges: 00405b90-00405c81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405b90(int param_1)

{
  FUN_004afce0(s_FRAME___06d__004de548,DAT_0053b9fc);
  FUN_004afce0(s_Handling_collision_for_object__d_004de558,param_1);
  param_1 = param_1 * 0xd0;
  FUN_004afce0(s_Object_speed____f__f__f___004de57c,
               (double)*(float *)(param_1 + 0x9c + DAT_0067ee20),
               (double)*(float *)(param_1 + 0xa0 + DAT_0067ee20),
               (double)*(float *)(param_1 + 0xa4 + DAT_0067ee20));
  *(float *)(param_1 + 0x9c + DAT_0067ee20) = *(float *)(param_1 + 0x9c + DAT_0067ee20) * 0.95;
  *(float *)(param_1 + 0xa0 + DAT_0067ee20) = *(float *)(param_1 + 0xa0 + DAT_0067ee20) * 0.95;
  *(float *)(param_1 + 0xa4 + DAT_0067ee20) = *(float *)(param_1 + 0xa4 + DAT_0067ee20) * 0.95;
  FUN_004afce0(s_After_handling__004de598);
  FUN_004afce0(s_Object_speed____f__f__f___004de5ac,
               (double)*(float *)(param_1 + 0x9c + DAT_0067ee20),
               (double)*(float *)(param_1 + 0xa0 + DAT_0067ee20),
               (double)*(float *)(param_1 + 0xa4 + DAT_0067ee20));
  return;
}

