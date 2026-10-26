/*
 * FUN_00446970 at 00446970
 * undefined FUN_00446970(void)
 * Address ranges: 00446970-004469a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446970(int *param_1,int *param_2)

{
  FUN_004427e8(param_1,param_2);
  param_2[1] = -0x7f800000;
  param_2[9] = param_2[9] | 0x800;
  if (DAT_0047d7ac != '\0') {
    param_2[2] = 0x80;
  }
  FUN_00442780(param_1,(uint *)(param_2 + 2));
  return;
}

