/*
 * FUN_00459910 at 00459910
 * undefined FUN_00459910(void)
 * Address ranges: 00459910-0045997d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00459910(int param_1,float *param_2)

{
  float local_c;
  float local_8;
  float local_4;
  
  *(float *)(param_1 + 0x44) = *param_2;
  *(float *)(param_1 + 0x48) = param_2[1];
  *(float *)(param_1 + 0x4c) = param_2[2];
  local_c = _DAT_00544ab0 * *param_2;
  local_8 = _DAT_00544ab4 * param_2[1];
  local_4 = _DAT_00544ab8 * param_2[2];
  FUN_00458420(&local_c);
  return;
}

