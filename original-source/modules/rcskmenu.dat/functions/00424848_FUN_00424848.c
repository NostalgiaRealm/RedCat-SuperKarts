/*
 * FUN_00424848 at 00424848
 * undefined FUN_00424848(void)
 * Address ranges: 00424848-0042489f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424848(int *param_1,int *param_2)

{
  FUN_004427e8(param_1,param_2);
  FUN_00442714(param_1,(int)param_2,"COMBOBOX");
  param_2[1] = param_2[1] | 0x200240U |
               *(uint *)(&DAT_0047b670 + (uint)*(byte *)((int)param_1 + 0x1fa) * 4) |
               *(uint *)(&DAT_0047b690 + (uint)*(byte *)((int)param_1 + 0x1f9) * 4) |
               *(uint *)(&DAT_0047b684 + (uint)*(byte *)(param_1 + 0x7e) * 4);
  return;
}

