/*
 * FUN_00427a18 at 00427a18
 * uint * __cdecl FUN_00427a18(uint * param_1, uint param_2)
 * Address ranges: 00427a18-00427a8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint * __cdecl FUN_00427a18(uint *param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  
  if (DAT_0043e5cc == 0) {
    puVar2 = FUN_00422350(param_1,(char)param_2);
    return puVar2;
  }
  while( true ) {
    uVar1 = (ushort)(byte)*param_1;
    if (uVar1 == 0) break;
    if ((*(byte *)((int)&DAT_0043e6e0 + uVar1 + 1) & 4) == 0) {
      puVar2 = param_1;
      if (param_2 == uVar1) break;
    }
    else {
      puVar2 = (uint *)((int)param_1 + 1);
      if (*(byte *)((int)param_1 + 1) == 0) {
        return (uint *)0x0;
      }
      if (param_2 == CONCAT11((byte)*param_1,*(byte *)((int)param_1 + 1))) {
        return param_1;
      }
    }
    param_1 = (uint *)((int)puVar2 + 1);
  }
  return (uint *)(~-(uint)(param_2 != uVar1) & (uint)param_1);
}

