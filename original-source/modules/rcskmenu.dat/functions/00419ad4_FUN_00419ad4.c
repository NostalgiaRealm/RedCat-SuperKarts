/*
 * FUN_00419ad4 at 00419ad4
 * ushort __register FUN_00419ad4(ushort * param_1)
 * Address ranges: 00419ad4-00419ae9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

ushort FUN_00419ad4(ushort *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = param_1 + 10;
  for (; (int)param_1 < (int)puVar1; param_1 = param_1 + 1) {
    uVar2 = uVar2 ^ *param_1;
  }
  return uVar2;
}

