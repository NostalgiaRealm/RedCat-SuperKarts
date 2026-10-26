/*
 * FUN_004258a4 at 004258a4
 * undefined __register FUN_004258a4(int * param_1, int * param_2)
 * Address ranges: 004258a4-004258d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004258a4(int *param_1,int *param_2)

{
  FUN_004427e8(param_1,param_2);
  FUN_00442714(param_1,(int)param_2,"BUTTON");
  param_2[1] = param_2[1] | *(uint *)(&DAT_0047b698 + (uint)*(byte *)(param_1 + 0x7e) * 4);
  return;
}

