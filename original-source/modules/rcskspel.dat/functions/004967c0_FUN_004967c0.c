/*
 * FUN_004967c0 at 004967c0
 * undefined FUN_004967c0(void)
 * Address ranges: 004967c0-004967e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004967c0(int param_1,int param_2,int param_3)

{
  return (uint)*(ushort *)(*(int *)(param_1 + 0x7e) + (param_2 + param_3) * 2) * 0x20 +
         *(int *)(param_1 + 0x7a);
}

